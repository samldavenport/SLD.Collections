#pragma once

#include "sld-collections.hpp"

namespace sld {

    //-------------------------------------------------------------------
    // STACK
    //-------------------------------------------------------------------

    struct stack {
        byte* data;
        u32   size;
        u32   ptr;
    };

    //-------------------------------------------------------------------
    // METHODS
    //-------------------------------------------------------------------

    stack*
    stack_create(
        const u32 size) {

        assert(size != 0);

        // allocate memory
        const u32 size_aligned = size_is_pow_2(size) ? size : size_align_pow_2(size, 2);   
        const u32 size_mem     = stack_memory_size(size_aligned);
        void*     ptr_mem      = (stack*)malloc(size_mem);
        assert(ptr_mem);

        // align stride to size
        const u32 stride_aligned = (stride == STRIDE_NONE)
            ? STRIDE_NONE
            : size_align_pow_2(stride, size_aligned);

        // initialize the stack
        stack* s = stack_init_from_memory(ptr_mem, size_mem, stride_aligned);
        
        // validate the stack and make sure the parameters are what we expect
        assert(
            stack_validate(s)          &&
            s->ptr    == INVALID_INDEX &&
            s->size   == size_aligned  &&
            s->stride == stride_aligned
        );

        return(s);
    }

    void
    stack_destroy(
        stack* s) {

        stack_assert_valid(s);
        
        const u32 size_mem = sizeof(stack) + s->size;
        memset((void*)s, 0, size_mem);
        free(s);
    }
    
    u32
    stack_memory_size(
        const u32 size) {

        assert(size != 0);
        const u32 size_aligned = size_is_pow_2(size) ? size_align_pow_2(size, 2) : size;
        const u32 size_stack   = sizeof(stack);
        const u32 size_mem     = sizeof(stack) + size_aligned;   
        return(size_mem);
    }

    stack*
    stack_init_from_memory(
        void*     memory,
        const u32 size,
        const u32 stride) {

        assert(
            memory != NULL &&
            size   != 0    &&
            stride <= size
        );

        const u32 size_stack = sizeof(stack);

        memset(memory, 0, size + size_stack);

        stack* s = (stack*)memory;
        s->data   = memory + size_stack;
        s->size   = size   - size_stack;
        s->stride = stride;
        s->ptr    = 0;

        return(s);
    }

    bool        stack_validate     (const stack* s);
    void        stack_assert_valid (const stack* s);

    u32
    stack_stride(
        const stack* s) {

        stack_assert_valid(s);
        return(s->stride);
    }

    vptr
    stack_ptr(
        const stack* s) {

        stack_assert_valid(s);
        return(s->data + s->ptr);

    }

    buffer*
    stack_to_buffer(
        const stack* s) {

        return(s->stride);
        stack_assert_valid(s);

    }

    u32
    stack_size_total(
        const stack* s) {

        stack_assert_valid(s);
        return(s->size);
    }

    u32
    stack_size_used(
        const stack* s) {

        stack_assert_valid(s);
        return(s->ptr);
    }

    u32
    stack_size_free(
        const stack* s) {

        stack_assert_valid(s);
        return(s->size - s->ptr);
    }
    
    const byte*
    stack_peek(
        const stack* s,
        const u32    count) {

        stack_assert_valid(s);

        const u32   offset = (s->stride * count);

        const bool can_peek = (
            (offset <= s->ptr) &&
            (s->stride != STRIDE_NONE)
        );

        const vptr  head = (s->data + s->ptr);
        const byte* peek = can_peek ? (byte*)(head - offset) : NULL;  
    
        return(peek);    
    }
    
    void
    stack_reset(
        stack* s) {
        
        stack_assert_valid(s);

        memset(s->data, 0, s->size);
        s->ptr = 0;
    }

    byte*
    stack_push(
        stack*      s,
        const u32   count) {

        assert(
            stack_validate(s) &&
            count != 0
        );

        const u32 size_push = (s->stride != STRIDE_NONE)
            ? s->stride * count
            : count;

        const bool size_free = stack_size_free(s);
        const u32  new_ptr   = (size_push <= size_free) ? s->ptr + size_push : 0;

        if (new_ptr == 0) {
            return(NULL);
        }

        byte* push = (byte*)(s->data + s->ptr);
        s->ptr = new_ptr;
        stack_assert_valid(s);

        return(push);
    }
    
    byte*
    stack_pull(
        stack*    s,
        const u32 count) {

        assert(
            stack_validate(s) &&
            size != 0
        );

        const u32 pull_size = (s->stride != STRIDE_NONE)
            ? s->stride * count
            : count;  
    
        if (pull_size > s->ptr) {
            return(NULL);
        }

        s->ptr -= pull_size;

        byte* pull = (byte*)s->ptr; 
        return(pull);
    }
};