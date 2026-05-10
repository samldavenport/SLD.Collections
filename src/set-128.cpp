#pragma once

#include "sld-collections-internal.hpp"

namespace sld {
    
    SLD_COLLECTIONS_API u128            set_128_memory_size              (const u128 stride, const u128 capacity);
    SLD_COLLECTIONS_API set_128*        set_128_create                   (const u128 stride, const u128 capacity);
    SLD_COLLECTIONS_API set_128*        set_128_memory_init              (const u128 stride, const u128 capacity, void* mem_ptr, const u128 mem_size);
    SLD_COLLECTIONS_API void            set_128_destroy                  (set_128* s);    
    SLD_COLLECTIONS_API bool            set_128_is_valid                 (const set_128* s);
    SLD_COLLECTIONS_API bool            set_128_assert_valid             (const set_128* s);
    SLD_COLLECTIONS_API u128            set_128_validate                 (const set_128* s);
    SLD_COLLECTIONS_API u128            set_128_size_total               (const set_128* s);
    SLD_COLLECTIONS_API u128            set_128_size_free                (const set_128* s);
    SLD_COLLECTIONS_API u128            set_128_size_used                (const set_128* s);
    SLD_COLLECTIONS_API element*        set_128_elements                 (const set_128* s);
    SLD_COLLECTIONS_API h128*           set_128_hashes                   (const set_128* s);
    SLD_COLLECTIONS_API u128            set_128_stride                   (const set_128* s);
    SLD_COLLECTIONS_API u128            set_128_capacity                 (const set_128* s);
    SLD_COLLECTIONS_API u128            set_128_count                    (const set_128* s);
    SLD_COLLECTIONS_API u128            set_128_index                    (const set_128* s, const u128     index);
    SLD_COLLECTIONS_API u128            set_128_index_of                 (const set_128* s, const element* elmnt);
    SLD_COLLECTIONS_API void            set_128_reset                    (set_128* s);
    SLD_COLLECTIONS_API void            set_128_reverse                  (set_128* s);
    SLD_COLLECTIONS_API u128            set_128_remove_element           (set_128* s, const element* elmnt);
    SLD_COLLECTIONS_API u128            set_128_remove_at                (set_128* s, const u128     index);
    SLD_COLLECTIONS_API u128            set_128_insert_back              (set_128* s, const element* push,   const u128     count = 1);
    SLD_COLLECTIONS_API u128            set_128_insert_front             (set_128* s, const element* push,   const u128     count = 1);
    SLD_COLLECTIONS_API void            set_128_insert_before_index      (set_128* s, const element* insert, const u128     before_index, const u128 count = 1);
    SLD_COLLECTIONS_API void            set_128_insert_before_element    (set_128* s, const element* insert, const element* before_elmnt, const u128 count = 1);
    SLD_COLLECTIONS_API void            set_128_insert_after_index       (set_128* s, const element* insert, const u128     after_index,  const u128 count = 1);
    SLD_COLLECTIONS_API void            set_128_insert_after_element     (set_128* s, const element* insert, const element* after_elmnt,  const u128 count = 1);

};
