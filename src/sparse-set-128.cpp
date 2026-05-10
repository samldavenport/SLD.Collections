#pragma once

#include "sld-collections-internal.hpp" 

namespace sld {


    SLD_COLLECTIONS_API u32             sparse_set_128_memory_size       (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API sparse_set_128* sparse_set_128_create            (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API sparse_set_128* sparse_set_128_memory_init       (const u32 stride, const u32 capacity, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            sparse_set_128_destroy           (sparse_set_128* ss);    
    SLD_COLLECTIONS_API bool            sparse_set_128_is_valid          (const sparse_set_128* ss);
    SLD_COLLECTIONS_API bool            sparse_set_128_assert_valid      (const sparse_set_128* ss);
    SLD_COLLECTIONS_API u32             sparse_set_128_validate          (const sparse_set_128* ss);
    SLD_COLLECTIONS_API u32             sparse_set_128_size_total        (const sparse_set_128* ss);
    SLD_COLLECTIONS_API u32             sparse_set_128_size_free         (const sparse_set_128* ss);
    SLD_COLLECTIONS_API u32             sparse_set_128_size_used         (const sparse_set_128* ss);
    SLD_COLLECTIONS_API element*        sparse_set_128_elements          (const sparse_set_128* ss);
    SLD_COLLECTIONS_API index*          sparse_set_128_indexes           (const sparse_set_128* ss);
    SLD_COLLECTIONS_API h128*           sparse_set_128_hashes            (const sparse_set_128* ss);
    SLD_COLLECTIONS_API u32             sparse_set_128_stride            (const sparse_set_128* ss);
    SLD_COLLECTIONS_API u32             sparse_set_128_capacity          (const sparse_set_128* ss);
    SLD_COLLECTIONS_API u32             sparse_set_128_count             (const sparse_set_128* ss);
    SLD_COLLECTIONS_API void            sparse_set_128_reset             (sparse_set_128* ss);
    SLD_COLLECTIONS_API u32             sparse_set_128_remove_element    (sparse_set_128* ss, const element* elmnt);
    SLD_COLLECTIONS_API u32             sparse_set_128_insert_element    (sparse_set_128* ss, const element* elmnt, const u32 count = 1);


};
