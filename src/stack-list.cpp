#pragma once

#include "sld-collections.hpp"

namespace sld {
    
    //-------------------------------------------------------------------
    // STACK LIST
    //-------------------------------------------------------------------

    template<typename t>
    struct stack_list {
        t*  _elements;
        u32 _capacity;
        u32 _ptr;
    };

    //-------------------------------------------------------------------
    // METHODS
    //-------------------------------------------------------------------

    template<typename t> stack_list<t>*
    stack_list_create(
        const u32 size) {
 
        
    }
    
    template<typename t> void
    stack_list_destroy(
        stack_list<t>* sl) {

    }
    
    template<typename t> u32
    stack_list_memory_size(
        const u32 size) {

    }
    
    template<typename t> stack_list<t>*
    stack_list_init_from_memory(
        void*     memory,
        const u32 size) {

    }
    
    template<typename t> bool
    stack_list_validate(
        const stack_list<t>* sl) {

    }
    
    template<typename t> void
    stack_list_assert_valid(
        const stack_list<t>* sl) {

    }
    
    template<typename t> u32
    stack_list_head(
        const stack_list<t>* sl) {

    }

    template<typename t> buffer*
    stack_list_to_buffer(
        const stack_list<t>* sl);
    
    template<typename t> u32
    stack_list_size_total(
        const stack_list<t>* sl);
    
    template<typename t> u32
    stack_list_size_used(
        const stack_list<t>* sl);
    
    template<typename t> u32
    stack_list_size_free(
        const stack_list<t>* sl);
    
    template<typename t> const byte*
    stack_list_peek(
        const stack_list<t>* sl, const u32 size);
    
    template<typename t> void
    stack_list_reset(
        stack_list<t>* sl);
    
    template<typename t> byte*
    stack_list_push(
        stack_list<t>* sl, const u32 size);
    
    template<typename t> byte*
    stack_list_pull(
        stack_list<t>* sl, const u32 size);


};