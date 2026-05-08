#pragma once

#include "sld-collections.hpp"

namespace sld {

    struct stack_buffer {
        byte* data;
        u32   size;
        u32   ptr;        
    };

    constexpr u32 STRUCT_SIZE_STACK_BUFFER = sizeof(stack_buffer);

    SLD_COLLECTIONS_API u32             stack_buffer_memory_size         (const u32 stack_size);
    SLD_COLLECTIONS_API stack_buffer*   stack_buffer_create              (const u32 stack_size);
    SLD_COLLECTIONS_API stack_buffer*   stack_buffer_memory_init         (const u32 stack_size, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            stack_buffer_destroy             (stack_buffer* sb);    
    SLD_COLLECTIONS_API bool            stack_buffer_is_valid            (const stack_buffer* sb);
    SLD_COLLECTIONS_API void            stack_buffer_assert_valid        (const stack_buffer* sb);
    SLD_COLLECTIONS_API byte*           stack_buffer_data                (const stack_buffer* sb);
    SLD_COLLECTIONS_API u32             stack_buffer_size_total          (const stack_buffer* sb);
    SLD_COLLECTIONS_API u32             stack_buffer_size_free           (const stack_buffer* sb);
    SLD_COLLECTIONS_API u32             stack_buffer_size_used           (const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*     stack_buffer_head                (const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*     stack_buffer_tail                (const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*     stack_buffer_peek                (const stack_buffer* sb, const u32 size);
    SLD_COLLECTIONS_API void            stack_buffer_reset               (stack_buffer* sb);
    SLD_COLLECTIONS_API u32             stack_buffer_push_data           (stack_buffer* sb, const u32 size, const byte* data);
    SLD_COLLECTIONS_API byte*           stack_buffer_pull_data           (stack_buffer* sb, const u32 size);

};