#pragma once

#include "sld-collections.hpp"

namespace sld {
    
    struct set_32 {
        element* elements;
        h32*     hashes;        
        u32      stride;
        u32      capacity;
        u32      count;
    };

    
    SLD_COLLECTIONS_API u32             set_32_memory_size               (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API set_32*         set_32_create                    (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API set_32*         set_32_memory_init               (const u32 stride, const u32 capacity, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            set_32_destroy                   (set_32* s);    
    SLD_COLLECTIONS_API bool            set_32_is_valid                  (const set_32* s);
    SLD_COLLECTIONS_API bool            set_32_assert_valid              (const set_32* s);
    SLD_COLLECTIONS_API u32             set_32_validate                  (const set_32* s);
    SLD_COLLECTIONS_API u32             set_32_size_total                (const set_32* s);
    SLD_COLLECTIONS_API u32             set_32_size_free                 (const set_32* s);
    SLD_COLLECTIONS_API u32             set_32_size_used                 (const set_32* s);
    SLD_COLLECTIONS_API element*        set_32_elements                  (const set_32* s);
    SLD_COLLECTIONS_API h32*            set_32_hashes                    (const set_32* s);
    SLD_COLLECTIONS_API u32             set_32_stride                    (const set_32* s);
    SLD_COLLECTIONS_API u32             set_32_capacity                  (const set_32* s);
    SLD_COLLECTIONS_API u32             set_32_count                     (const set_32* s);
    SLD_COLLECTIONS_API u32             set_32_index                     (const set_32* s, const u32  index);
    SLD_COLLECTIONS_API u32             set_32_index_of                  (const set_32* s, const element elmnt);
    SLD_COLLECTIONS_API void            set_32_reset                     (set_32* s);
    SLD_COLLECTIONS_API void            set_32_reverse                   (set_32* s);
    SLD_COLLECTIONS_API u32             set_32_remove_element            (set_32* s, const element elmnt);
    SLD_COLLECTIONS_API u32             set_32_remove_at                 (set_32* s, const u32  index);
    SLD_COLLECTIONS_API u32             set_32_insert_back               (set_32* s, const element* push,   const u32      count = 1);
    SLD_COLLECTIONS_API u32             set_32_insert_front              (set_32* s, const element* push,   const u32      count = 1);
    SLD_COLLECTIONS_API void            set_32_insert_before_index       (set_32* s, const element* insert, const u32      before_index, const u32 count = 1);
    SLD_COLLECTIONS_API void            set_32_insert_before_element     (set_32* s, const element* insert, const element* before_elmnt, const u32 count = 1);
    SLD_COLLECTIONS_API void            set_32_insert_after_index        (set_32* s, const element* insert, const u32      after_index,  const u32 count = 1);
    SLD_COLLECTIONS_API void            set_32_insert_after_element      (set_32* s, const element* insert, const element* after_elmnt,  const u32 count = 1);

};