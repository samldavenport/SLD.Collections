#pragma once

#include "sld-collections.hpp"

namespace sld {
    
    struct set_64 {
        element* elements;
        h64*     hashes;        
        u32      stride;
        u32      capacity;
        u32      count;
    };

    
    SLD_COLLECTIONS_API u64             set_64_memory_size               (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API set_64*         set_64_create                    (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API set_64*         set_64_memory_init               (const u32 stride, const u32 capacity, void* mem_ptr, const u64 mem_size);
    SLD_COLLECTIONS_API void            set_64_destroy                   (set_64* s);    
    SLD_COLLECTIONS_API bool            set_64_is_valid                  (const set_64* s);
    SLD_COLLECTIONS_API bool            set_64_assert_valid              (const set_64* s);
    SLD_COLLECTIONS_API u32             set_64_validate                  (const set_64* s);
    SLD_COLLECTIONS_API u32             set_64_size_total                (const set_64* s);
    SLD_COLLECTIONS_API u32             set_64_size_free                 (const set_64* s);
    SLD_COLLECTIONS_API u32             set_64_size_used                 (const set_64* s);
    SLD_COLLECTIONS_API void*           set_64_elements                  (const set_64* s);
    SLD_COLLECTIONS_API h64*            set_64_hashes                    (const set_64* s);
    SLD_COLLECTIONS_API u32             set_64_stride                    (const set_64* s);
    SLD_COLLECTIONS_API u32             set_64_capacity                  (const set_64* s);
    SLD_COLLECTIONS_API u32             set_64_count                     (const set_64* s);
    SLD_COLLECTIONS_API u32             set_64_index                     (const set_64* s, const u64  index);
    SLD_COLLECTIONS_API u32             set_64_index_of                  (const set_64* s, const element elmnt);
    SLD_COLLECTIONS_API void            set_64_reset                     (set_64* s);
    SLD_COLLECTIONS_API void            set_64_reverse                   (set_64* s);
    SLD_COLLECTIONS_API u32             set_64_remove_element            (set_64* s, const element elmnt);
    SLD_COLLECTIONS_API u32             set_64_remove_at                 (set_64* s, const u64  index);
    SLD_COLLECTIONS_API u32             set_64_insert_back               (set_64* s, const void* push,   const u32   count = 1);
    SLD_COLLECTIONS_API u32             set_64_insert_front              (set_64* s, const void* push,   const u32   count = 1);
    SLD_COLLECTIONS_API void            set_64_insert_before_index       (set_64* s, const void* insert, const u32   before_index, const u32 count = 1);
    SLD_COLLECTIONS_API void            set_64_insert_before_element     (set_64* s, const void* insert, const void* before_elmnt, const u32 count = 1);
    SLD_COLLECTIONS_API void            set_64_insert_after_index        (set_64* s, const void* insert, const u32   after_index,  const u32 count = 1);
    SLD_COLLECTIONS_API void            set_64_insert_after_element      (set_64* s, const void* insert, const void* after_elmnt,  const u32 count = 1);

};