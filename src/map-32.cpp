#pragma once

#include "sld-collections-internal.hpp"

namespace sld {

    SLD_COLLECTIONS_API u32             map_32_list_memory_size          (const u32 key_size, const u32 val_size, const u32 capacity);
    SLD_COLLECTIONS_API map_32*         map_32_list_create               (const u32 key_size, const u32 val_size, const u32 capacity);
    SLD_COLLECTIONS_API map_32*         map_32_list_memory_init          (const u32 key_size, const u32 val_size, const u32 capacity, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            map_32_list_destroy              (map_32* m);    
    SLD_COLLECTIONS_API bool            map_32_list_is_valid             (const map_32* m);
    SLD_COLLECTIONS_API void            map_32_list_assert_valid         (const map_32* m);
    SLD_COLLECTIONS_API const value*    map_32_values                    (const map_32* m);
    SLD_COLLECTIONS_API const key*      map_32_keys                      (const map_32* m);
    SLD_COLLECTIONS_API const h32       map_32_hashes                    (const map_32* m);
    SLD_COLLECTIONS_API u32             map_32_capacity                  (const map_32* m);
    SLD_COLLECTIONS_API u32             map_32_count                     (const map_32* m);
    SLD_COLLECTIONS_API u32             map_32_size_total                (const map_32* m);
    SLD_COLLECTIONS_API u32             map_32_size_used                 (const map_32* m);
    SLD_COLLECTIONS_API u32             map_32_size_free                 (const map_32* m);
    SLD_COLLECTIONS_API bool            map_32_does_key_exist            (const map_32* m, const key    k);
    SLD_COLLECTIONS_API bool            map_32_does_value_exist          (const map_32* m, const value* v);
    SLD_COLLECTIONS_API bool            map_32_lookup                    (const map_32* m, const key*   k, value* v);
    SLD_COLLECTIONS_API void            map_32_reset                     (map_32* m);
    SLD_COLLECTIONS_API u32             map_32_remove                    (map_32* m, const key* k, const value* v, const u32 count = 1);
    SLD_COLLECTIONS_API u32             map_32_insert                    (map_32* m, const key* k, const value* v, const u32 count = 1, h32* h = NULL); 
    SLD_COLLECTIONS_API u32             map_32_update                    (map_32* m, const key* k, const value* v, const u32 count = 1); 


};