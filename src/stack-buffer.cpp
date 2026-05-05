#pragma once

#include "sld-collections.hpp"

namespace sld {

    //-------------------------------------------------------------------
    // CONSTANTS
    //-------------------------------------------------------------------

    constexpr u32 STRUCT_SIZE_STACK_BUFFER = sizeof(stack_buffer);

    //-------------------------------------------------------------------
    // STATIC METHODS
    //-------------------------------------------------------------------

    static stack_buffer*
    stack_buffer::create(
        const u32 size) {

        assert(size != 0 && size > STRUCT_SIZE_STACK_BUFFER);

        const u32 mem_size = stack_buffer::memory_size(size);
        void*     mem_ptr  = malloc(mem_size);
        assert(mem_ptr != NULL);

        stack_buffer* sb = stack_buffer::init(mem_size, mem_ptr);        
        assert(
            sb != NULL       &&
            sb->is_valid()   &&
            sb->size == size &&
            sb->ptr  == 0
        );
        return(sb);
    }

    static u32
    stack_buffer::memory_size(
        const u32 size) {

        assert(
            size != 0 &&
            size >  STRUCT_SIZE_STACK_BUFFER
        );

        return(STRUCT_SIZE_STACK_BUFFER + size);
    }

    static void
    stack_buffer::destroy(
        stack_buffer* sb) {

        assert(sb != NULL && sb->is_valid());

        const u32 mem_size = stack_buffer::memory_size(sb->size);
        vptr      mem_ptr  = (vptr)sb;
        zero_memory(mem_size, mem_ptr);

        free(sb);
    }

    static stack_buffer*
    stack_buffer::init(
        const u32 size,
        vptr      memory) {

        assert(
            size   != 0                        &&
            size   >  STRUCT_SIZE_STACK_BUFFER &&
            memory != NULL
        );

        zero_memory(size, memory);
    
        stack_buffer* sb = (stack_buffer*)memory;
        sb->data = (memory + STRUCT_SIZE_STACK_BUFFER);
        sb->size = (size   - STRUCT_SIZE_STACK_BUFFER);
        sb->ptr  = 0;
    }

    //-------------------------------------------------------------------
    // CONSTANT METHODS
    //-------------------------------------------------------------------

    bool
    stack_buffer::is_valid(void) const {

        const bool is_valid = (
            this->data != NULL                     &&
            this->size >  STRUCT_SIZE_STACK_BUFFER &&
            this->size <  MAX_CAPACITY             &&
            this->ptr  <= this->size
        );

        return(is_valid);
    }

    void
    stack_buffer::assert_valid(
        void) const {

        assert(this->is_valid());
    }

    const byte*
    stack_buffer::peek(
        const u32 size) const {

        this->assert_valid();
        
        if (size > this->ptr) {
            return(NULL);
        }

        const u32  peek_ptr  = (this->ptr  - size);
        const vptr peek_data = (this->data + peek_ptr);

        return((byte*)peek_data);
    }

    u32
    stack_buffer::to_data_buffer(
        data_buffer* to) const {

        assert(
            this->is_valid() &&
              to->is_valid()
        );

        const u32 size_copied = to->copy_from(
            this->data,
            this->ptr
        );

        return(size_copied);
    }

    u32
    stack_buffer::to_data_buffer(
        data_buffer& to) const {

        assert(
            this->is_valid() &&
               to.is_valid()
        );

        const u32 size_copied = to.copy_from(
            this->data,
            this->ptr
        );

        return(size_copied);
    }

    
    //-------------------------------------------------------------------
    // MUTABLE METHODS
    //-------------------------------------------------------------------

    void
    stack_buffer::reset(
        void) {

        this->assert_valid();
        this->ptr = 0;

        zero_memory(this->size, (vptr)this->data);
    }

    byte*
    stack_buffer::pull(
        const u32 size) {

        this->assert_valid();

        const u32   pull_size = (size > this->ptr) ? this->ptr : size;
        const byte* pull_data = (byte*)(this->data - size_actual);
    
        this->ptr -= pull_size;
        this->assert_valid();

        return(pull_data);
    }

    u32
    stack_buffer::push(
        const u32   size,
        const byte* data) {

        assert(
            this->is_valid() &&
            size >  0        &&
            data != NULL
        );

        const u32 size_free = (this->size - this->ptr);
        const u32 size_push = (size <= size_free) ? size : size_free;
         
        (void)memccpy(
            this->data,
            data,
            size_push
        );

        this->assert_valid();

        return(size_push);
    }
};