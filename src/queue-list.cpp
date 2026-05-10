#pragma once

#include "sld-collections-internal.hpp"

namespace sld {


    SLD_COLLECTIONS_API u32             queue_list_memory_size           (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API queue_list*     queue_list_create                (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API queue_list*     queue_list_memory_init           (const u32 stride, const u32 capacity, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            queue_list_destroy               (queue_list* ql);    
    SLD_COLLECTIONS_API bool            queue_list_is_valid              (const queue_list* ql);
    SLD_COLLECTIONS_API void            queue_list_assert_valid          (const queue_list* ql);
    SLD_COLLECTIONS_API const void*     queue_list_elements              (const queue_list* ql);
    SLD_COLLECTIONS_API const u32       queue_list_stride                (const queue_list* ql);
    SLD_COLLECTIONS_API const u32       queue_list_capacity              (const queue_list* ql);
    SLD_COLLECTIONS_API const u32       queue_list_count                 (const queue_list* ql);
    SLD_COLLECTIONS_API u32             queue_list_size_total            (const queue_list* ql);
    SLD_COLLECTIONS_API u32             queue_list_size_used             (const queue_list* ql);
    SLD_COLLECTIONS_API u32             queue_list_size_free             (const queue_list* ql);
    SLD_COLLECTIONS_API const void*     queue_list_head_element          (const queue_list* ql);
    SLD_COLLECTIONS_API const void*     queue_list_tail_element          (const queue_list* ql);
    SLD_COLLECTIONS_API const void*     queue_list_peek_element          (const queue_list* ql, const u32 count);
    SLD_COLLECTIONS_API void            queue_list_reset                 (queue_list* ql);
    SLD_COLLECTIONS_API u32             queue_list_push_element          (queue_list* ql, element elmnt, const u32 count = 1);
    SLD_COLLECTIONS_API void*           queue_list_pop_element           (queue_list* ql, const u32 count = 1);

};