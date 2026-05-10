#pragma once

#include "sld-collections-internal.hpp"

namespace sld {


    SLD_COLLECTIONS_API u32
    stack_list_memory_size(
        const u32 stride,
        const u32 capacity) {

        assert(
            stride   != 0 &&
            capacity != 0);


    }

    SLD_COLLECTIONS_API stack_list*     stack_list_create                (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API stack_list*     stack_list_memory_init           (const u32 stride, const u32 capacity, void* mem_ptr, const u32 mem_size);
    
    SLD_COLLECTIONS_API void
    stack_list_destroy(
        stack_list* sl) {

    }
    
    SLD_COLLECTIONS_API bool
    stack_list_is_valid(
        const stack_list* sl) {

    }

    SLD_COLLECTIONS_API void
    stack_list_assert_valid(
        const stack_list* sl) {

    }

    SLD_COLLECTIONS_API const element*
    stack_list_elements(
        const stack_list* sl) {

    }

    SLD_COLLECTIONS_API const u32
    stack_list_stride(
        const stack_list* sl) {

    }

    SLD_COLLECTIONS_API const u32
    stack_list_capacity(
        const stack_list* sl) {

    }

    SLD_COLLECTIONS_API const u32
    stack_list_count(
        const stack_list* sl) {

    }

    SLD_COLLECTIONS_API u32
    stack_list_size_total(
        const stack_list* sl) {

    }

    SLD_COLLECTIONS_API u32
    stack_list_size_used(
        const stack_list* sl) {

    }

    SLD_COLLECTIONS_API u32
    stack_list_size_free(
        const stack_list* sl) {

    }

    SLD_COLLECTIONS_API const element*
    stack_list_head_element(
        const stack_list* sl) {

    }

    SLD_COLLECTIONS_API const element*
    stack_list_tail_element(
        const stack_list* sl) {

    }

    SLD_COLLECTIONS_API const element*
    stack_list_peek_element(
        const stack_list* sl {

    } co
    nst u32 count);
    SLD_COLLECTIONS_API void            stack_list_reset                 (stack_list* sl);
    SLD_COLLECTIONS_API u32             stack_list_push_element          (stack_list* sl, const element* elmnt, const u32 count = 1);
    SLD_COLLECTIONS_API element*        stack_list_pull_element          (stack_list* sl, const u32 count = 1);


};