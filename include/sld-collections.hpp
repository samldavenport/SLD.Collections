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
    struct map_32;
    struct map_64; 
    struct map_128;
    struct set_32;
    struct set_64;
    struct set_128;
    struct single_linked_list;
    struct single_linked_node;
    struct stack_buffer;
    struct stack_list;
    struct sparse_set_32;
    struct sparse_set_64;
    struct sparse_set_128;
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
    SLD_COLLECTIONS_API bool            map_32_does_key_exist            (const map_32* m, const key*   k);
    SLD_COLLECTIONS_API bool            map_32_does_value_exist          (const map_32* m, const value* v);
    SLD_COLLECTIONS_API bool            map_32_lookup                    (const map_32* m, const key*   k, value* v);
    SLD_COLLECTIONS_API void            map_32_reset                     (map_32* m);
    SLD_COLLECTIONS_API u32             map_32_remove                    (map_32* m, const key* k, const value* v, const u32 count = 1);
    SLD_COLLECTIONS_API u32             map_32_insert                    (map_32* m, const key* k, const value* v, const u32 count = 1, h32* h = NULL); 
    SLD_COLLECTIONS_API u32             map_32_update                    (map_32* m, const key* k, const value* v, const u32 count = 1); 

    //--------------------------------------------------------------------
    // MAP 64
    //--------------------------------------------------------------------

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
    SLD_COLLECTIONS_API bool            map_64_does_key_exist            (const map_64* m, const key*   k);
    SLD_COLLECTIONS_API bool            map_64_does_value_exist          (const map_64* m, const value* v);
    SLD_COLLECTIONS_API bool            map_64_lookup                    (const map_64* m, const key*   k, value* v);
    SLD_COLLECTIONS_API void            map_64_reset                     (map_64* m);
    SLD_COLLECTIONS_API u32             map_64_remove                    (map_64* m, const key* k, const value* v, const u32 count = 1);
    SLD_COLLECTIONS_API u32             map_64_insert                    (map_64* m, const key* k, const value* v, const u32 count = 1, h64* h = NULL); 
    SLD_COLLECTIONS_API u32             map_64_update                    (map_64* m, const key* k, const value* v, const u32 count = 1); 

    //--------------------------------------------------------------------
    // MAP 128
    //--------------------------------------------------------------------

    SLD_COLLECTIONS_API u128            map_128_list_memory_size         (const u128 key_size, const u32 val_size, const u32 capacity);
    SLD_COLLECTIONS_API map_128*        map_128_list_create              (const u128 key_size, const u32 val_size, const u32 capacity);
    SLD_COLLECTIONS_API map_128*        map_128_list_memory_init         (const u128 key_size, const u32 val_size, const u32 capacity, void* mem_ptr, const u128 mem_size);
    SLD_COLLECTIONS_API void            map_128_list_destroy             (map_128* m);    
    SLD_COLLECTIONS_API bool            map_128_list_is_valid            (const map_128* m);
    SLD_COLLECTIONS_API void            map_128_list_assert_valid        (const map_128* m);
    SLD_COLLECTIONS_API const value*    map_128_values                   (const map_128* m);
    SLD_COLLECTIONS_API const key*      map_128_keys                     (const map_128* m);
    SLD_COLLECTIONS_API const h128      map_128_hashes                   (const map_128* m);
    SLD_COLLECTIONS_API u32             map_128_capacity                 (const map_128* m);
    SLD_COLLECTIONS_API u32             map_128_count                    (const map_128* m);
    SLD_COLLECTIONS_API u32             map_128_size_total               (const map_128* m);
    SLD_COLLECTIONS_API u32             map_128_size_used                (const map_128* m);
    SLD_COLLECTIONS_API u32             map_128_size_free                (const map_128* m);
    SLD_COLLECTIONS_API bool            map_128_does_key_exist           (const map_128* m, const key*   k);
    SLD_COLLECTIONS_API bool            map_128_does_value_exist         (const map_128* m, const value* v);
    SLD_COLLECTIONS_API bool            map_128_lookup                   (const map_128* m, const key*   k, value* v);
    SLD_COLLECTIONS_API void            map_128_reset                    (map_128* m);
    SLD_COLLECTIONS_API u32             map_128_remove                   (map_128* m, const key* k, const value* v, const u32 count = 1);
    SLD_COLLECTIONS_API u32             map_128_insert                   (map_128* m, const key* k, const value* v, const u32 count = 1, h128* h = NULL); 
    SLD_COLLECTIONS_API u32             map_128_update                   (map_128* m, const key* k, const value* v, const u32 count = 1); 

    //--------------------------------------------------------------------
    // SET 32
    //--------------------------------------------------------------------

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
    SLD_COLLECTIONS_API u32             set_32_index_of                  (const set_32* s, const element* elmnt);
    SLD_COLLECTIONS_API void            set_32_reset                     (set_32* s);
    SLD_COLLECTIONS_API void            set_32_reverse                   (set_32* s);
    SLD_COLLECTIONS_API u32             set_32_remove_element            (set_32* s, const element* elmnt);
    SLD_COLLECTIONS_API u32             set_32_remove_at                 (set_32* s, const u32  index);
    SLD_COLLECTIONS_API u32             set_32_insert_back               (set_32* s, const element* push,   const u32      count = 1);
    SLD_COLLECTIONS_API u32             set_32_insert_front              (set_32* s, const element* push,   const u32      count = 1);
    SLD_COLLECTIONS_API void            set_32_insert_before_index       (set_32* s, const element* insert, const u32      before_index, const u32 count = 1);
    SLD_COLLECTIONS_API void            set_32_insert_before_element     (set_32* s, const element* insert, const element* before_elmnt, const u32 count = 1);
    SLD_COLLECTIONS_API void            set_32_insert_after_index        (set_32* s, const element* insert, const u32      after_index,  const u32 count = 1);
    SLD_COLLECTIONS_API void            set_32_insert_after_element      (set_32* s, const element* insert, const element* after_elmnt,  const u32 count = 1);

    //--------------------------------------------------------------------
    // SET 64
    //--------------------------------------------------------------------

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
    SLD_COLLECTIONS_API u32             set_64_index_of                  (const set_64* s, const element* elmnt);
    SLD_COLLECTIONS_API void            set_64_reset                     (set_64* s);
    SLD_COLLECTIONS_API void            set_64_reverse                   (set_64* s);
    SLD_COLLECTIONS_API u32             set_64_remove_element            (set_64* s, const element* elmnt);
    SLD_COLLECTIONS_API u32             set_64_remove_at                 (set_64* s, const u64  index);
    SLD_COLLECTIONS_API u32             set_64_insert_back               (set_64* s, const void* push,   const u32   count = 1);
    SLD_COLLECTIONS_API u32             set_64_insert_front              (set_64* s, const void* push,   const u32   count = 1);
    SLD_COLLECTIONS_API void            set_64_insert_before_index       (set_64* s, const void* insert, const u32   before_index, const u32 count = 1);
    SLD_COLLECTIONS_API void            set_64_insert_before_element     (set_64* s, const void* insert, const void* before_elmnt, const u32 count = 1);
    SLD_COLLECTIONS_API void            set_64_insert_after_index        (set_64* s, const void* insert, const u32   after_index,  const u32 count = 1);
    SLD_COLLECTIONS_API void            set_64_insert_after_element      (set_64* s, const void* insert, const void* after_elmnt,  const u32 count = 1);

    //--------------------------------------------------------------------
    // SET 128
    //--------------------------------------------------------------------

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
    SLD_COLLECTIONS_API u128            set_128_insert_back              (set_128* s, const element* push,   const u32     count = 1);
    SLD_COLLECTIONS_API u128            set_128_insert_front             (set_128* s, const element* push,   const u32     count = 1);
    SLD_COLLECTIONS_API void            set_128_insert_before_index      (set_128* s, const element* insert, const u128     before_index, const u32 count = 1);
    SLD_COLLECTIONS_API void            set_128_insert_before_element    (set_128* s, const element* insert, const element* before_elmnt, const u32 count = 1);
    SLD_COLLECTIONS_API void            set_128_insert_after_index       (set_128* s, const element* insert, const u128     after_index,  const u32 count = 1);
    SLD_COLLECTIONS_API void            set_128_insert_after_element     (set_128* s, const element* insert, const element* after_elmnt,  const u32 count = 1);

    //--------------------------------------------------------------------
    // SPARSE SET 32
    //--------------------------------------------------------------------

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

    //--------------------------------------------------------------------
    // SPARSE SET 64
    //--------------------------------------------------------------------

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

    //--------------------------------------------------------------------
    // SPARSE SET 128
    //--------------------------------------------------------------------

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