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

    bool          stack_buffer::validate       (void)            const;
    void          stack_buffer::assert_valid   (void)            const;
    const byte*   stack_buffer::peek           (const u32 size)  const;
    void          stack_buffer::to_data_buffer (data_buffer* to) const;
    void          stack_buffer::to_data_buffer (data_buffer& to) const;
    
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

    const byte*
    stack_buffer::peek(
        const u32 size) {

        
    }

    byte*
    stack_buffer::pull(
        const u32 size) {

        
    }

    u32           stack_buffer::push         (const u32 size, const byte* data);

};