#ifndef SLD_COLLECTIONS_HPP
#define SLD_COLLECTIONS_HPP

#include "sld.hpp"

#ifdef SLD_COLLECTIONS_DLL
#   define SLD_COLLECTIONS_API __declspec(dllexport)
#else
#   define SLD_COLLECTIONS_API __declspec(dllimport)
#endif

#define SLD_COLLECTIONS_UTILITY  inline
#define SLD_COLLECTIONS_CONSTANT 

namespace sld {

    //--------------------------------------------------------------------
    // CONSTANTS
    //--------------------------------------------------------------------

    static constexpr u32 INVALID_INDEX = 0xFFFFFFFF;
    static constexpr u32 MAX_CAPACITY  = 0xFFFFFFFE;

    //--------------------------------------------------------------------
    // COLLECTIONS
    //--------------------------------------------------------------------

    struct array_list;
    struct data_buffer;
    struct double_linked_list;
    struct double_linked_node;
    struct map;
    struct set;
    struct single_linked_list;
    struct single_linked_node;
    struct stack_buffer;
    struct stack_list;
    struct sparse_set;
    struct queue_buffer;
    struct queue_list;

    //--------------------------------------------------------------------
    // DATA BUFFER
    //--------------------------------------------------------------------

    SLD_COLLECTIONS_API u32             data_buffer_memory_size          (const u32 buffer_size);
    SLD_COLLECTIONS_API data_buffer*    data_buffer_create               (const u32 buffer_size);
    SLD_COLLECTIONS_API data_buffer*    data_buffer_memory_init          (const u32 buffer_size, const u32 mem_size, void* mem_ptr);
    SLD_COLLECTIONS_API void            data_buffer_destroy              (data_buffer* db);
    SLD_COLLECTIONS_API void            data_buffer_assert_valid         (const data_buffer* db);
    SLD_COLLECTIONS_API const byte*     data_buffer_data                 (const data_buffer* db);
    SLD_COLLECTIONS_API u32             data_buffer_size_total           (const data_buffer* db);
    SLD_COLLECTIONS_API u32             data_buffer_size_remaining       (const data_buffer* db);
    SLD_COLLECTIONS_API u32             data_buffer_length               (const data_buffer* db);
    SLD_COLLECTIONS_API u32             data_buffer_copy_to_mem          (const data_buffer* db,     const u32 db_offset,  const u32 db_size,  byte*        mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API u32             data_buffer_append_src_to_dst    (const data_buffer* src_db, const u32 src_offset, const u32 src_size, data_buffer* dst_db);
    SLD_COLLECTIONS_API u32             data_buffer_copy_src_to_dst      (const data_buffer* src_db, const u32 src_offset, const u32 src_size, data_buffer* dst_db, const u32 dst_offset, const u32 dst_size);
    SLD_COLLECTIONS_API void            data_buffer_reset                (data_buffer* db);
    SLD_COLLECTIONS_API void            data_buffer_update               (data_buffer* db, const u32   db_offset, const byte* src_mem, const u32 src_size);
    SLD_COLLECTIONS_API u32             data_buffer_append_from_mem      (data_buffer* db, const byte* src_mem,   const u32   src_size);

    //--------------------------------------------------------------------
    // STACK BUFFER
    //--------------------------------------------------------------------

    SLD_COLLECTIONS_API u32             stack_buffer_memory_size         (const u32 stack_size);
    SLD_COLLECTIONS_API stack_buffer*   stack_buffer_create              (const u32 stack_size);
    SLD_COLLECTIONS_API stack_buffer*   stack_buffer_memory_init         (const u32 stack_size, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            stack_buffer_destroy             (stack_buffer* sb);    
    SLD_COLLECTIONS_API bool            stack_buffer_is_valid            (const stack_buffer* sb);
    SLD_COLLECTIONS_API void            stack_buffer_assert_valid        (const stack_buffer* sb);
    SLD_COLLECTIONS_API byte*           stack_buffer_data                (const stack_buffer* sb);
    SLD_COLLECTIONS_API u32             stack_buffer_size_total          (const stack_buffer* sb);
    SLD_COLLECTIONS_API u32             stack_buffer_size_free           (const stack_buffer* sb);
    SLD_COLLECTIONS_API u32             stack_buffer_size_used           (const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*     stack_buffer_head                (const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*     stack_buffer_tail                (const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*     stack_buffer_peek                (const stack_buffer* sb, const u32 size);
    SLD_COLLECTIONS_API void            stack_buffer_reset               (stack_buffer* sb);
    SLD_COLLECTIONS_API u32             stack_buffer_push_data           (stack_buffer* sb, const u32 size, const byte* data);
    SLD_COLLECTIONS_API byte*           stack_buffer_pull_data           (stack_buffer* sb, const u32 size);

    //--------------------------------------------------------------------
    // QUEUE BUFFER
    //--------------------------------------------------------------------

    SLD_COLLECTIONS_API u32             queue_memory_size                (const u32 queue_size);
    SLD_COLLECTIONS_API queue_buffer*   queue_buffer_create              (const u32 queue_size);
    SLD_COLLECTIONS_API queue_buffer*   queue_buffer_memory_init         (const u32 queue_size, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            queue_buffer_destroy             (queue_buffer* qb);    
    SLD_COLLECTIONS_API bool            queue_buffer_is_valid            (const queue_buffer* qb);
    SLD_COLLECTIONS_API void            queue_buffer_assert_valid        (const queue_buffer* qb);
    SLD_COLLECTIONS_API byte*           queue_buffer_data                (const queue_buffer* qb);
    SLD_COLLECTIONS_API u32             queue_buffer_size_total          (const queue_buffer* qb);
    SLD_COLLECTIONS_API u32             queue_buffer_size_free           (const queue_buffer* qb);
    SLD_COLLECTIONS_API u32             queue_buffer_size_used           (const queue_buffer* qb);
    SLD_COLLECTIONS_API const byte*     queue_buffer_head                (const queue_buffer* qb, const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*     queue_buffer_tail                (const queue_buffer* qb, const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*     queue_buffer_peek                (const queue_buffer* qb, const stack_buffer* sb, const u32 size);
    SLD_COLLECTIONS_API void            queue_buffer_reset               (queue_buffer* qb);
    SLD_COLLECTIONS_API const byte*     queue_buffer_peek                (queue_buffer* qb);
    SLD_COLLECTIONS_API u32             queue_buffer_push_data           (queue_buffer* qb, const u32 size, const byte* data);
    SLD_COLLECTIONS_API byte*           queue_buffer_pop_data            (queue_buffer* qb, const u32 size);

    //--------------------------------------------------------------------
    // ARRAY LIST
    //--------------------------------------------------------------------

    SLD_COLLECTIONS_API u32             array_list_memory_size           (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API array_list*     array_list_create                (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API array_list*     array_list_memory_init           (const u32 stride, const u32 capacity, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            array_list_destroy               (array_list* al);    
    SLD_COLLECTIONS_API bool            array_list_is_valid              (const array_list* al);
    SLD_COLLECTIONS_API bool            array_list_assert_valid          (const array_list* al);
    SLD_COLLECTIONS_API u32             array_list_validate              (const array_list* al);
    SLD_COLLECTIONS_API u32             array_list_size_total            (const array_list* al);
    SLD_COLLECTIONS_API u32             array_list_size_free             (const array_list* al);
    SLD_COLLECTIONS_API u32             array_list_size_used             (const array_list* al);
    SLD_COLLECTIONS_API element*        array_list_elements              (const array_list* al);
    SLD_COLLECTIONS_API u32             array_list_stride                (const array_list* al);
    SLD_COLLECTIONS_API u32             array_list_capacity              (const array_list* al);
    SLD_COLLECTIONS_API u32             array_list_count                 (const array_list* al);
    SLD_COLLECTIONS_API element*        array_list_index                 (const array_list* al, const u32     index);
    SLD_COLLECTIONS_API u32             array_list_index_of              (const array_list* al, const element* elmnt);
    SLD_COLLECTIONS_API void            array_list_reset                 (array_list* al);
    SLD_COLLECTIONS_API void            array_list_reverse               (array_list* al);
    SLD_COLLECTIONS_API u32             array_list_remove_element        (array_list* al, const element* elmnt);
    SLD_COLLECTIONS_API u32             array_list_remove_at             (array_list* al, const u32      index);
    SLD_COLLECTIONS_API u32             array_list_insert_back           (array_list* al, const element* push,   const u32      count = 1);
    SLD_COLLECTIONS_API u32             array_list_insert_front          (array_list* al, const element* push,   const u32      count = 1);
    SLD_COLLECTIONS_API void            array_list_insert_before_index   (array_list* al, const element* insert, const u32      before_index, const u32 count = 1);
    SLD_COLLECTIONS_API void            array_list_insert_before_element (array_list* al, const element* insert, const element* before_elmnt, const u32 count = 1);
    SLD_COLLECTIONS_API void            array_list_insert_after_index    (array_list* al, const element* insert, const u32      after_index,  const u32 count = 1);
    SLD_COLLECTIONS_API void            array_list_insert_after_element  (array_list* al, const element* insert, const element* after_elmnt,  const u32 count = 1);

    //--------------------------------------------------------------------
    // STACK LIST
    //--------------------------------------------------------------------

    SLD_COLLECTIONS_API u32             stack_list_memory_size           (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API stack_list*     stack_list_create                (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API stack_list*     stack_list_memory_init           (const u32 stride, const u32 capacity, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            stack_list_destroy               (stack_list* sl);    
    SLD_COLLECTIONS_API bool            stack_list_is_valid              (const stack_list* sl);
    SLD_COLLECTIONS_API void            stack_list_assert_valid          (const stack_list* sl);
    SLD_COLLECTIONS_API const element*  stack_list_elements              (const stack_list* sl);
    SLD_COLLECTIONS_API const u32       stack_list_stride                (const stack_list* sl);
    SLD_COLLECTIONS_API const u32       stack_list_capacity              (const stack_list* sl);
    SLD_COLLECTIONS_API const u32       stack_list_count                 (const stack_list* sl);
    SLD_COLLECTIONS_API u32             stack_list_size_total            (const stack_list* sl);
    SLD_COLLECTIONS_API u32             stack_list_size_used             (const stack_list* sl);
    SLD_COLLECTIONS_API u32             stack_list_size_free             (const stack_list* sl);
    SLD_COLLECTIONS_API const element*  stack_list_head_element          (const stack_list* sl);
    SLD_COLLECTIONS_API const element*  stack_list_tail_element          (const stack_list* sl);
    SLD_COLLECTIONS_API const element*  stack_list_peek_element          (const stack_list* sl, const u32 count);
    SLD_COLLECTIONS_API void            stack_list_reset                 (stack_list* sl);
    SLD_COLLECTIONS_API u32             stack_list_push_element          (stack_list* sl, const element* elmnt, const u32 count = 1);
    SLD_COLLECTIONS_API element*        stack_list_pull_element          (stack_list* sl, const u32 count = 1);

    //--------------------------------------------------------------------
    // QUEUE LIST
    //--------------------------------------------------------------------

    SLD_COLLECTIONS_API u32             queue_list_memory_size           (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API queue_list*     queue_list_create                (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API queue_list*     queue_list_memory_init           (const u32 stride, const u32 capacity, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            queue_list_destroy               (queue_list* ql);    
    SLD_COLLECTIONS_API bool            queue_list_is_valid              (const queue_list* ql);
    SLD_COLLECTIONS_API void            queue_list_assert_valid          (const queue_list* ql);
    SLD_COLLECTIONS_API const void*     queue_list_elements              (const queue_list* ql);
    SLD_COLLECTIONS_API const u32       queue_list_stride                (const queue_list* ql);
    SLD_COLLECTIONS_API const u32       queue_list_capacity              (const queue_list* ql);
    SLD_COLLECTIONS_API const u32       queue_list_count                 (const queue_list* ql);
    SLD_COLLECTIONS_API u32             queue_list_size_total            (const queue_list* ql);
    SLD_COLLECTIONS_API u32             queue_list_size_used             (const queue_list* ql);
    SLD_COLLECTIONS_API u32             queue_list_size_free             (const queue_list* ql);
    SLD_COLLECTIONS_API const void*     queue_list_head_element          (const queue_list* ql);
    SLD_COLLECTIONS_API const void*     queue_list_tail_element          (const queue_list* ql);
    SLD_COLLECTIONS_API const void*     queue_list_peek_element          (const queue_list* ql, const u32 count);
    SLD_COLLECTIONS_API void            queue_list_reset                 (queue_list* ql);
    SLD_COLLECTIONS_API u32             queue_list_push_element          (queue_list* ql, element* elmnt, const u32 count = 1);
    SLD_COLLECTIONS_API void*           queue_list_pop_element           (queue_list* ql, const u32 count = 1);

    //--------------------------------------------------------------------
    // MAP 32
    //--------------------------------------------------------------------

    SLD_COLLECTIONS_API u32             map_list_memory_size          (const u32 key_size, const u32 val_size, const u32 capacity);
    SLD_COLLECTIONS_API map*            map_list_create               (const u32 key_size, const u32 val_size, const u32 capacity);
    SLD_COLLECTIONS_API map*            map_list_memory_init          (const u32 key_size, const u32 val_size, const u32 capacity, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            map_list_destroy              (map* m);    
    SLD_COLLECTIONS_API bool            map_list_is_valid             (const map* m);
    SLD_COLLECTIONS_API void            map_list_assert_valid         (const map* m);
    SLD_COLLECTIONS_API const value*    map_values                    (const map* m);
    SLD_COLLECTIONS_API const key*      map_keys                      (const map* m);
    SLD_COLLECTIONS_API const u32*      map_hashes                    (const map* m);
    SLD_COLLECTIONS_API u32             map_capacity                  (const map* m);
    SLD_COLLECTIONS_API u32             map_count                     (const map* m);
    SLD_COLLECTIONS_API u32             map_size_total                (const map* m);
    SLD_COLLECTIONS_API u32             map_size_used                 (const map* m);
    SLD_COLLECTIONS_API u32             map_size_free                 (const map* m);
    SLD_COLLECTIONS_API bool            map_does_key_exist            (const map* m, const key*   k);
    SLD_COLLECTIONS_API bool            map_does_value_exist          (const map* m, const value* v);
    SLD_COLLECTIONS_API bool            map_lookup                    (const map* m, const key*   k, value* v);
    SLD_COLLECTIONS_API void            map_reset                     (map* m);
    SLD_COLLECTIONS_API u32             map_remove                    (map* m, const key* k, const value* v, const u32 count = 1);
    SLD_COLLECTIONS_API u32             map_insert                    (map* m, const key* k, const value* v, const u32 count = 1, h32* h = NULL); 
    SLD_COLLECTIONS_API u32             map_update                    (map* m, const key* k, const value* v, const u32 count = 1); 

    //--------------------------------------------------------------------
    // SET
    //--------------------------------------------------------------------

    SLD_COLLECTIONS_API u32             set_memory_size               (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API set*            set_create                    (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API set*            set_memory_init               (const u32 stride, const u32 capacity, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            set_destroy                   (set* s);    
    SLD_COLLECTIONS_API bool            set_is_valid                  (const set* s);
    SLD_COLLECTIONS_API bool            set_assert_valid              (const set* s);
    SLD_COLLECTIONS_API u32             set_validate                  (const set* s);
    SLD_COLLECTIONS_API u32             set_size_total                (const set* s);
    SLD_COLLECTIONS_API u32             set_size_free                 (const set* s);
    SLD_COLLECTIONS_API u32             set_size_used                 (const set* s);
    SLD_COLLECTIONS_API element*        set_elements                  (const set* s);
    SLD_COLLECTIONS_API u32*            set_hashes                    (const set* s);
    SLD_COLLECTIONS_API u32             set_stride                    (const set* s);
    SLD_COLLECTIONS_API u32             set_capacity                  (const set* s);
    SLD_COLLECTIONS_API u32             set_count                     (const set* s);
    SLD_COLLECTIONS_API u32             set_index                     (const set* s, const u32  index);
    SLD_COLLECTIONS_API u32             set_index_of                  (const set* s, const element* elmnt);
    SLD_COLLECTIONS_API void            set_reset                     (set* s);
    SLD_COLLECTIONS_API void            set_reverse                   (set* s);
    SLD_COLLECTIONS_API u32             set_remove_element            (set* s, const element* elmnt);
    SLD_COLLECTIONS_API u32             set_remove_at                 (set* s, const u32  index);
    SLD_COLLECTIONS_API u32             set_insert_back               (set* s, const element* push,   const u32      count = 1);
    SLD_COLLECTIONS_API u32             set_insert_front              (set* s, const element* push,   const u32      count = 1);
    SLD_COLLECTIONS_API void            set_insert_before_index       (set* s, const element* insert, const u32      before_index, const u32 count = 1);
    SLD_COLLECTIONS_API void            set_insert_before_element     (set* s, const element* insert, const element* before_elmnt, const u32 count = 1);
    SLD_COLLECTIONS_API void            set_insert_after_index        (set* s, const element* insert, const u32      after_index,  const u32 count = 1);
    SLD_COLLECTIONS_API void            set_insert_after_element      (set* s, const element* insert, const element* after_elmnt,  const u32 count = 1);

    //--------------------------------------------------------------------
    // SPARSE SET
    //--------------------------------------------------------------------

    SLD_COLLECTIONS_API u32             sparse_set_memory_size        (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API sparse_set*     sparse_set_create             (const u32 stride, const u32 capacity);
    SLD_COLLECTIONS_API sparse_set*     sparse_set_memory_init        (const u32 stride, const u32 capacity, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            sparse_set_destroy            (sparse_set* ss);    
    SLD_COLLECTIONS_API bool            sparse_set_is_valid           (const sparse_set* ss);
    SLD_COLLECTIONS_API bool            sparse_set_assert_valid       (const sparse_set* ss);
    SLD_COLLECTIONS_API u32             sparse_set_validate           (const sparse_set* ss);
    SLD_COLLECTIONS_API u32             sparse_set_size_total         (const sparse_set* ss);
    SLD_COLLECTIONS_API u32             sparse_set_size_free          (const sparse_set* ss);
    SLD_COLLECTIONS_API u32             sparse_set_size_used          (const sparse_set* ss);
    SLD_COLLECTIONS_API const element*  sparse_set_elements           (const sparse_set* ss);
    SLD_COLLECTIONS_API const index*    sparse_set_indexes            (const sparse_set* ss);
    SLD_COLLECTIONS_API const u32*      sparse_set_hashes             (const sparse_set* ss);
    SLD_COLLECTIONS_API u32             sparse_set_stride             (const sparse_set* ss);
    SLD_COLLECTIONS_API u32             sparse_set_capacity           (const sparse_set* ss);
    SLD_COLLECTIONS_API u32             sparse_set_count              (const sparse_set* ss);
    SLD_COLLECTIONS_API void            sparse_set_reset              (sparse_set* ss);
    SLD_COLLECTIONS_API u32             sparse_set_remove_element     (sparse_set* ss, const element* elmnt);
    SLD_COLLECTIONS_API u32             sparse_set_insert_element     (sparse_set* ss, const element* elmnt, const u32 count = 1);

    //--------------------------------------------------------------------
    // DATA HASHING
    //--------------------------------------------------------------------

    SLD_COLLECTIONS_API u32             hash_32                          (const void* data, const u32 size);
    SLD_COLLECTIONS_API u64             hash_64                          (const void* data, const u32 size);
    SLD_COLLECTIONS_API u128            hash_128                         (const void* data, const u32 size);
    SLD_COLLECTIONS_API u32             h32_search                       (const void* data, const u32 size, const u32* hash, const u32 count = 1);
    SLD_COLLECTIONS_API u32             h64_search                       (const void* data, const u32 size, const u32* hash, const u32 count = 1);
    SLD_COLLECTIONS_API u32             hash128_search                   (const void* data, const u32 size, const u32* hash, const u32 count = 1);
    
    //--------------------------------------------------------------------
    // UTILITIES
    //--------------------------------------------------------------------

    SLD_COLLECTIONS_UTILITY u64         size_kilobytes                   (const u64 n_kilobytes)               { return (n_kilobytes * 1024);                               }
    SLD_COLLECTIONS_UTILITY u64         size_megabytes                   (const u64 n_megabytes)               { return (n_megabytes * 1024 * 1024);                        }
    SLD_COLLECTIONS_UTILITY u64         size_gigabytes                   (const u64 n_gigabytes)               { return (n_gigabytes * 1024 * 1024 * 1024);                 }
    SLD_COLLECTIONS_UTILITY u64         size_align                       (const u64 size, const u64 alignment) { return ((size + alignment - 1) / (alignment * alignment)); }
    SLD_COLLECTIONS_UTILITY u64         size_align_pow_2                 (const u64 size, const u64 alignment) { return ((size + alignment - 1) & ~(alignment - 1));        }
    SLD_COLLECTIONS_UTILITY bool        size_is_pow_2                    (const u64 size)                      { return (((size > 0) && ((size & (size - 1)) == 0)));       }               
    SLD_COLLECTIONS_UTILITY void        zero_memory                      (void* memory, const u32 size)        { memset(memory, 0, size); }
};

#endif //SLD_COLLECTIONS_HPP