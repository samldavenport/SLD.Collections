#pragma once

#include "sld-collections.hpp"

#define STACK_LIST_FUNC_STATIC     template<typename type> static auto stack_list<type>::
#define STACK_LIST_FUNC_INSTANCE   template<typename type> auto stack_list<type>::

namespace sld {

    //-------------------------------------------------------------------
    // CONSTRUCTORS
    //-------------------------------------------------------------------

    // constructors
    STACK_LIST_FUNC_INSTANCE
    stack_list (const u32 capacity) {
        
        assert(capacity != 0);

        this->_elements = (type*)malloc(capacity * sizeof(type));
        this->_count    = 0;
        this->_capacity = capacity;
        this->_internal = true;

        this->assert_valid();
    }        
    
    STACK_LIST_FUNC_INSTANCE
    stack_list(
        const u32 capacity,
        type*     elements) {

        assert(this->_capacity != 0 && this->_elements != NULL);
        this->_elements = elements;
        this->_capacity = _capacity;
        this->_count    = 0;
        this->_internal = false;

        this->assert_valid();
    }     
    
    STACK_LIST_FUNC_INSTANCE
    stack_list(
        const u32 mem_size,
        vptr      mem_ptr) {

        const u32 size_type = sizeof(type);

        assert(
            mem_size != 0         &&
            mem_size >= size_type &&
            mem_ptr  != NULL
        );

        this->_elements = (type*)mem_ptr;
        this->_capacity = (mem_size / size_type);
        this->_count    = 0; 

        this->assert_valid();
    }

    //-------------------------------------------------------------------
    // DESTRUCTORS
    //-------------------------------------------------------------------

    STACK_LIST_FUNC_INSTANCE
    ~stack_list(void) {

        if (this->_internal) {
            zero_memory(this->_capacity, this->_elements);
            free(this->_elements);
        }

        this->_elements = NULL;
        this->_capacity = 0;
        this->_count    = 0;
    }

    //-------------------------------------------------------------------
    // STATIC METHODS
    //-------------------------------------------------------------------

    STACK_LIST_FUNC_STATIC
    memory_size(
        const u32 capacity) -> u32 {

        const u32 size = sizeof(type) * capacity;
        return(size_mem);
    }

    //-------------------------------------------------------------------
    // CONSTANT METHODS
    //-------------------------------------------------------------------

    // constant methods        
    STACK_LIST_FUNC_INSTANCE
    is_valid(
        void) const -> bool {

        const u32  size_type     = sizeof(type);
        const u32  size_elements = (size_type * this->_capacity); 
        const bool is_valid = (
            (this->_elements != NULL)           &&
            (this->_capacity > 0)               &&
            (this->_count    <= this->_capacity) &&
            (size_elements  < MAX_CAPACITY)
        );

        return(is_valid);
    }
    
    STACK_LIST_FUNC_INSTANCE
    assert_valid(
        void) const -> void {

        const bool is_valid = this->is_valid();
        assert(is_valid);
    }

    STACK_LIST_FUNC_INSTANCE
    peek(
        const u32 count) const -> const type* {

        this->assert_valid();

        if (count == 0 || count > this->_count) {
            return(NULL);
        }

        const u32   index = (this->_capacity - count);
        const type* peek  = &this->_elements[index];

        return(peek); 
    }

    STACK_LIST_FUNC_INSTANCE
    peek(
        const u32 count) const -> const type& {

        this->assert_valid();

        if (count == 0 || count > this->_count) {
            return(NULL);
        }

        const u32   index = (this->_capacity - count);
        const type& peek  = this->_elements[index];

        return(peek); 
    }

    STACK_LIST_FUNC_INSTANCE
    head(
        void) const -> const type* {

        this->assert_valid();

        const u32   index = (this->_count - 1);
        const type* head  = (this->_count > 0) ? &this->_elements[index] : NULL;

        return(head); 
    }

    STACK_LIST_FUNC_INSTANCE
    head(
        void) const -> const type& {

        assert(
            this->is_valid() &&
            this->_count != 0
        );

        const type& head  = this->_elements[index];

        return(head);  
    }

    STACK_LIST_FUNC_INSTANCE
    tail(
        void) const -> const type* {

        this->assert_valid();

        const u32   index = (this->_count - 1);
        const type* tail  = (this->_count > 0) ? this->_elements[0] : NULL;

        return(head); 
    }

    STACK_LIST_FUNC_INSTANCE
    tail(
        void) const -> const type& {

        assert(
            this->is_valid() &&
            this->_count != 0
        );

        const type& tail = this->_elements[0];

        return(head); 
    }

    STACK_LIST_FUNC_INSTANCE
    size_used(
        void) const -> u32 {

        this->is_valid();

        const u32 size_struct = sizeof(stack_list<type>); 
        const u32 size_count  = sizeof(type)* this->_count;
        const u32 size_used   = size_struct + size_count;   

        return(size_used);
    }

    STACK_LIST_FUNC_INSTANCE
    size_free(
        void) const -> u32 {

        this->is_valid();

        const u32 size_type              = sizeof(type);
        const u32 size_elements_capacity = (size_type * this->_capacity); 
        const u32 size_elements_count    = (size_type * this->_count); 
        const u32 size_struct            = sizeof(stack_list<type>);
        const u32 size_total             = (size_struct + size_elements_capacity);
        const u32 size_free              = size_total - size_elements_count; 
        
        return(size_free);
    }

    STACK_LIST_FUNC_INSTANCE
    to_data_buffer(
        data_buffer* buffer) const -> void {

    }

    STACK_LIST_FUNC_INSTANCE
    to_data_buffer(
        data_buffer& buffer) const -> void {

    }

    //-------------------------------------------------------------------
    // MUTABLE METHODS
    //-------------------------------------------------------------------

    STACK_LIST_FUNC_INSTANCE
    reset(void) -> void {

        this->assert_valid();

        const u32 size = sizeof(type) * this->_capacity;
        zero_memory(size, (vptr)this->_elements);
        this->_count = 0;
    }

    STACK_LIST_FUNC_INSTANCE
    pull(const u32 count) -> type* {

        assert(this->is_valid());

        if (count == 0 || count > this->_count) {
            return(NULL);
        }

        const u32 index = this->_count - count;
        type*     pull  = &this->_elements[index];
        
        this->_count -= count;
        
        return(pull);
    }

    STACK_LIST_FUNC_INSTANCE
    pull(type& element) -> bool {

        this->assert_valid();

        if (this->_count == 0) {
            return(false);
        }

        const u32 index = this->_count - 1;
        element = this->_elements[index];
        --this->_count;

        return(true);
    }

    STACK_LIST_FUNC_INSTANCE
    push(
        const u32   count,
        const type* elements) -> u32 {

        assert(
            this->is_valid() &&
            elements != NULL
        );

        if (count == 0 || this->_count == this->_capacity) {
            return(0);
        }

        const u32 push_count = (count > this->_count) ? count - this->_count : count;
        const u32 push_size  = sizeof(type) * push_count;

        (void)memccpy(
            (vptr)this->_elements, // dst
            (vptr)elements,       // src
            push_size);           // size

        this->_count += push_count

        return(push_count);
    }

    STACK_LIST_FUNC_INSTANCE
    push(
        const type& element) -> bool {
        
        this->is_valid();

        if (this->_count == this->_capacity) {
            return(false);
        }

        const u32 index = this->_count;
        this->_elements[index] = element;
        ++this->_count;
    
        return(true);
    }

};