#ifndef SLD_COLLECTIONS_INTERNAL_HPP
#define SLD_COLLECTIONS_INTERNAL_HPP

#include "sld-collections.hpp"

namespace sld {

    struct array_list {
        element* elements;
        u32      stride;
        u32      capacity;
        u32      count;
    };

    struct stack_list {
        element*  elements;
        u32       stride;
        u32       capacity;
        u32       count;
        b32       internal_memory;
    };

    struct stack_buffer {
        byte* data;
        u32   size;
        u32   ptr;        
    };

    struct sparse_set_128 {
        struct  {
            element* sparse_elements;
            index*   dense_indexes;
            h128*    dense_hashes;
        } array;
        struct {
            u32 element;
            u32 key;
        } size;
        u32      capacity;
        u32      count;
        f32      percentage_max;
    };

    struct sparse_set_64 {
        struct  {
            element* sparse_elements;
            index*   dense_indexes;
            h64*     dense_hashes;
        } array;
        struct {
            u32 element;
            u32 key;
        } size;
        u32      capacity;
        u32      count;
        f32      percentage_max;
    };


    struct sparse_set_32 {
        struct  {
            element* sparse_elements;
            index*   dense_indexes;
            h32*     dense_hashes;
        } array;
        struct {
            u32 element;
            u32 key;
        } size;
        u32      capacity;
        u32      count;
        f32      percentage_max;
    };

    struct set_128 {
        element* elements;
        h128*    hashes;        
        u128     stride;
        u128     capacity;
        u128     count;
    };

    struct set_64 {
        element* elements;
        h64*     hashes;        
        u32      stride;
        u32      capacity;
        u32      count;
    };

    
    struct set_32 {
        element* elements;
        h32*     hashes;        
        u32      stride;
        u32      capacity;
        u32      count;
    };

    struct queue_list {
        void*  elements;
        u32   stride;
        u32   capacity;
        u32   count;
    };

    struct queue_buffer {
        byte* data;
        u32   size;
        u32   head;
        u32   tail;
    };

    struct map_128 {
        value* array_value;
        key*   array_key;
        h128*  array_hash; 
        u32    size_value;
        u32    size_key;
        u32    capacity;       
        u32    count;       
    };

    struct map_64 {
        value* array_value;
        key*   array_key;
        h64*   array_hash; 
        u32    size_value;
        u32    size_key;
        u32    capacity;       
        u32    count;       
    };

    struct map_32 {
        value* array_value;
        key*   array_key;
        h32*   array_hash; 
        u32    size_value;
        u32    size_key;
        u32    capacity;       
        u32    count;       
    };

    struct data_buffer {
        byte* data;
        u32   size;
        u32   length;
        b64   internal_memory;
    };

    static constexpr u32 BUFFER_STRUCT_SIZE = sizeof(data_buffer);


    static constexpr u32 STRUCT_SIZE_STACK_LIST = sizeof(stack_list);
    static constexpr u32 STRUCT_SIZE_STACK_BUFFER = sizeof(stack_buffer);


};

#endif //SLD_COLLECTIONS_INTERNAL_HPP