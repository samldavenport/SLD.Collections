#pragma once

#include "sld-collections.hpp"

namespace sld {

    struct sparse_set_32 {
        struct  {
            element* sparse_elements;
            index*   dense_indexes;
            h32*     dense_hashes;
        } array;
        struct {
            u32 element;
            u32 key;
        } size;
        u32      capacity;
        u32      count;
        f32      percentage_max;
    };

    SLD_COLLECTIONS_API u32             sparse_set_32_memory_size        (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API sparse_set_32*  sparse_set_32_create             (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API sparse_set_32*  sparse_set_32_memory_init        (const u32 stride, const u32 capacity, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            sparse_set_32_destroy            (sparse_set_32* ss);    
    SLD_COLLECTIONS_API bool            sparse_set_32_is_valid           (const sparse_set_32* ss);
    SLD_COLLECTIONS_API bool            sparse_set_32_assert_valid       (const sparse_set_32* ss);
    SLD_COLLECTIONS_API u32             sparse_set_32_validate           (const sparse_set_32* ss);
    SLD_COLLECTIONS_API u32             sparse_set_32_size_total         (const sparse_set_32* ss);
    SLD_COLLECTIONS_API u32             sparse_set_32_size_free          (const sparse_set_32* ss);
    SLD_COLLECTIONS_API u32             sparse_set_32_size_used          (const sparse_set_32* ss);
    SLD_COLLECTIONS_API element*        sparse_set_32_elements           (const sparse_set_32* ss);
    SLD_COLLECTIONS_API index*          sparse_set_32_indexes            (const sparse_set_32* ss);
    SLD_COLLECTIONS_API h32*            sparse_set_32_hashes             (const sparse_set_32* ss);
    SLD_COLLECTIONS_API u32             sparse_set_32_stride             (const sparse_set_32* ss);
    SLD_COLLECTIONS_API u32             sparse_set_32_capacity           (const sparse_set_32* ss);
    SLD_COLLECTIONS_API u32             sparse_set_32_count              (const sparse_set_32* ss);
    SLD_COLLECTIONS_API void            sparse_set_32_reset              (sparse_set_32* ss);
    SLD_COLLECTIONS_API u32             sparse_set_32_remove_element     (sparse_set_32* ss, const element* elmnt);
    SLD_COLLECTIONS_API u32             sparse_set_32_insert_element     (sparse_set_32* ss, const element* elmnt, const u32 count = 1);

};
