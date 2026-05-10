#pragma once

#include "sld-collections-internal.hpp"

namespace sld {


    SLD_COLLECTIONS_API u32             sparse_set_64_memory_size        (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API sparse_set_64*  sparse_set_64_create             (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API sparse_set_64*  sparse_set_64_memory_init        (const u32 stride, const u32 capacity, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            sparse_set_64_destroy            (sparse_set_64* ss);    
    SLD_COLLECTIONS_API bool            sparse_set_64_is_valid           (const sparse_set_64* ss);
    SLD_COLLECTIONS_API bool            sparse_set_64_assert_valid       (const sparse_set_64* ss);
    SLD_COLLECTIONS_API u32             sparse_set_64_validate           (const sparse_set_64* ss);
    SLD_COLLECTIONS_API u32             sparse_set_64_size_total         (const sparse_set_64* ss);
    SLD_COLLECTIONS_API u32             sparse_set_64_size_free          (const sparse_set_64* ss);
    SLD_COLLECTIONS_API u32             sparse_set_64_size_used          (const sparse_set_64* ss);
    SLD_COLLECTIONS_API element*        sparse_set_64_elements           (const sparse_set_64* ss);
    SLD_COLLECTIONS_API index*          sparse_set_64_indexes            (const sparse_set_64* ss);
    SLD_COLLECTIONS_API h32*            sparse_set_64_hashes             (const sparse_set_64* ss);
    SLD_COLLECTIONS_API u32             sparse_set_64_stride             (const sparse_set_64* ss);
    SLD_COLLECTIONS_API u32             sparse_set_64_capacity           (const sparse_set_64* ss);
    SLD_COLLECTIONS_API u32             sparse_set_64_count              (const sparse_set_64* ss);
    SLD_COLLECTIONS_API void            sparse_set_64_reset              (sparse_set_64* ss);
    SLD_COLLECTIONS_API u32             sparse_set_64_remove_element     (sparse_set_64* ss, const element* elmnt);
    SLD_COLLECTIONS_API u32             sparse_set_64_insert_element     (sparse_set_64* ss, const element* elmnt, const u32 count = 1);
};

