#ifndef SLD_COLLECTIONS_INTERNAL_HPP
#define SLD_COLLECTIONS_INTERNAL_HPP

#include "sld-collections.hpp"

namespace sld {

    //--------------------------------------------------------------------
    // DEFINITIONS
    //--------------------------------------------------------------------

    struct array_list {
        element* elements;
        u32      stride;
        u32      capacity;
        u32      count;
    };

    struct data_buffer {
        byte* data;
        u32   size;
        u32   length;
        b64   internal_memory;
    };

    struct double_linked_list {

    };
    
    struct double_linked_node {

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

    struct map_64 {
        value* array_value;
        key*   array_key;
        h64*   array_hash; 
        u32    size_value;
        u32    size_key;
        u32    capacity;       
        u32    count;       
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

    struct set_32 {
        element* elements;
        h32*     hashes;        
        u32      stride;
        u32      capacity;
        u32      count;
    };

    struct set_64 {
        element* elements;
        h64*     hashes;        
        u32      stride;
        u32      capacity;
        u32      count;
    };

    struct set_128 {
        element* elements;
        h128*    hashes;        
        u128     stride;
        u128     capacity;
        u128     count;
    };

    struct single_linked_list {

    };

    struct single_linked_node {

    };

    struct stack_buffer {
        byte* data;
        u32   size;
        u32   ptr;        
    };

    struct stack_list {
        element*  elements;
        u32       stride;
        u32       capacity;
        u32       count;
        b32       internal_memory;
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

    //--------------------------------------------------------------------
    // CONSTANTS
    //--------------------------------------------------------------------

    static constexpr u32 STRUCT_SIZE_ARRAY_LIST         = sizeof(array_list);
    static constexpr u32 STRUCT_SIZE_DATA_BUFFER        = sizeof(data_buffer);
    static constexpr u32 STRUCT_SIZE_DOUBLE_LINKED_LIST = sizeof(double_linked_list);
    static constexpr u32 STRUCT_SIZE_DOUBLE_LINKED_NODE = sizeof(double_linked_node);
    static constexpr u32 STRUCT_SIZE_MAP_32             = sizeof(map_32);
    static constexpr u32 STRUCT_SIZE_MAP_64             = sizeof(map_64);
    static constexpr u32 STRUCT_SIZE_MAP_128            = sizeof(map_128);
    static constexpr u32 STRUCT_SIZE_SET_32             = sizeof(set_32);
    static constexpr u32 STRUCT_SIZE_SET_64             = sizeof(set_64);
    static constexpr u32 STRUCT_SIZE_SET_128            = sizeof(set_128);
    static constexpr u32 STRUCT_SIZE_SINGLE_LINKED_LIST = sizeof(single_linked_list);
    static constexpr u32 STRUCT_SIZE_SINGLE_LINKED_NODE = sizeof(single_linked_node);
    static constexpr u32 STRUCT_SIZE_STACK_BUFFER       = sizeof(stack_buffer);
    static constexpr u32 STRUCT_SIZE_STACK_LIST         = sizeof(stack_list);
    static constexpr u32 STRUCT_SIZE_SPARSE_SET_32      = sizeof(sparse_set_32);
    static constexpr u32 STRUCT_SIZE_SPARSE_SET_64      = sizeof(sparse_set_64);
    static constexpr u32 STRUCT_SIZE_SPARSE_SET_128     = sizeof(sparse_set_128);
    static constexpr u32 STRUCT_SIZE_QUEUE_BUFFER       = sizeof(queue_buffer);
    static constexpr u32 STRUCT_SIZE_QUEUE_LIST         = sizeof(queue_list);

};

#endif //SLD_COLLECTIONS_INTERNAL_HPP