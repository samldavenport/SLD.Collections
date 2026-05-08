#pragma once

#include "sld-collections.hpp"

namespace sld {

    struct map_64 {
        value* array_value;
        key*   array_key;
        h64*   array_hash; 
        u32    size_value;
        u32    size_key;
        u32    capacity;       
        u32    count;       
    };


    SLD_COLLECTIONS_API u64             map_64_list_memory_size          (const u32 key_size, const u32 val_size, const u32 capacity);
    SLD_COLLECTIONS_API map_64*         map_64_list_create               (const u32 key_size, const u32 val_size, const u32 capacity);
    SLD_COLLECTIONS_API map_64*         map_64_list_memory_init          (const u32 key_size, const u32 val_size, const u32 capacity, void* mem_ptr, const u64 mem_size);
    SLD_COLLECTIONS_API void            map_64_list_destroy              (map_64* m);    
    SLD_COLLECTIONS_API bool            map_64_list_is_valid             (const map_64* m);
    SLD_COLLECTIONS_API void            map_64_list_assert_valid         (const map_64* m);
    SLD_COLLECTIONS_API const value*    map_64_values                    (const map_64* m);
    SLD_COLLECTIONS_API const key*      map_64_keys                      (const map_64* m);
    SLD_COLLECTIONS_API const h64       map_64_hashes                    (const map_64* m);
    SLD_COLLECTIONS_API u32             map_64_capacity                  (const map_64* m);
    SLD_COLLECTIONS_API u32             map_64_count                     (const map_64* m);
    SLD_COLLECTIONS_API u32             map_64_size_total                (const map_64* m);
    SLD_COLLECTIONS_API u32             map_64_size_used                 (const map_64* m);
    SLD_COLLECTIONS_API u32             map_64_size_free                 (const map_64* m);
    SLD_COLLECTIONS_API bool            map_64_does_key_exist            (const map_64* m, const key    k);
    SLD_COLLECTIONS_API bool            map_64_does_value_exist          (const map_64* m, const value* v);
    SLD_COLLECTIONS_API bool            map_64_lookup                    (const map_64* m, const key*   k, value* v);
    SLD_COLLECTIONS_API void            map_64_reset                     (map_64* m);
    SLD_COLLECTIONS_API u32             map_64_remove                    (map_64* m, const key* k, const value* v, const u64 count = 1);
    SLD_COLLECTIONS_API u32             map_64_insert                    (map_64* m, const key* k, const value* v, const u64 count = 1, h64* h = NULL); 
    SLD_COLLECTIONS_API u32             map_64_update                    (map_64* m, const key* k, const value* v, const u64 count = 1); 


};