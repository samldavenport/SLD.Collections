#pragma once

#include "sld-collections.hpp"

namespace sld {

    struct map_128 {
        value* array_value;
        key*   array_key;
        h128*  array_hash; 
        u32    size_value;
        u32    size_key;
        u32    capacity;       
        u32    count;       
    };


    SLD_COLLECTIONS_API u128            map_128_list_memory_size         (const u128 key_size, const u32 val_size, const u32 capacity);
    SLD_COLLECTIONS_API map_128*        map_128_list_create              (const u128 key_size, const u32 val_size, const u32 capacity);
    SLD_COLLECTIONS_API map_128*        map_128_list_memory_init         (const u128 key_size, const u32 val_size, const u32 capacity, void* mem_ptr, const u128 mem_size);
    SLD_COLLECTIONS_API void            map_128_list_destroy             (map_128* m);    
    SLD_COLLECTIONS_API bool            map_128_list_is_valid            (const map_128* m);
    SLD_COLLECTIONS_API void            map_128_list_assert_valid        (const map_128* m);
    SLD_COLLECTIONS_API const value*    map_128_values                   (const map_128* m);
    SLD_COLLECTIONS_API const key*      map_128_keys                     (const map_128* m);
    SLD_COLLECTIONS_API const hash128   map_128_hashes                   (const map_128* m);
    SLD_COLLECTIONS_API u32             map_128_capacity                 (const map_128* m);
    SLD_COLLECTIONS_API u32             map_128_count                    (const map_128* m);
    SLD_COLLECTIONS_API u32             map_128_size_total               (const map_128* m);
    SLD_COLLECTIONS_API u32             map_128_size_used                (const map_128* m);
    SLD_COLLECTIONS_API u32             map_128_size_free                (const map_128* m);
    SLD_COLLECTIONS_API bool            map_128_does_key_exist           (const map_128* m, const key    k);
    SLD_COLLECTIONS_API bool            map_128_does_value_exist         (const map_128* m, const value* v);
    SLD_COLLECTIONS_API bool            map_128_lookup                   (const map_128* m, const key*   k, value* v);
    SLD_COLLECTIONS_API void            map_128_reset                    (map_128* m);
    SLD_COLLECTIONS_API u32             map_128_remove                   (map_128* m, const key* k, const value* v, const u128 count = 1);
    SLD_COLLECTIONS_API u32             map_128_insert                   (map_128* m, const key* k, const value* v, const u128 count = 1, h128* h = NULL); 
    SLD_COLLECTIONS_API u32             map_128_update                   (map_128* m, const key* k, const value* v, const u128 count = 1); 

};