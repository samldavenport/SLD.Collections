#pragma once

#include "sld-collections.hpp"

#define array_list_static   template<typename type> static auto array_list<type>
#define array_list_instance template<typename type>        auto array_list<type>


namespace sld {

    // static methods
    array_list_static::memory_size(
        const u32 capacity) -> u32 {

    }

    // constructors
    array_list_instance::array_list(
        const u32 capacity) {

    }

    array_list_instance::array_list(
        const u32 capacity,
        type*     elements) {

    }

    array_list_instance::array_list(
        const u32 mem_size,
        vptr      mem_ptr) {

    }

    // destructors
    array_list_instance::~array_list(
        void) {

    }

    // constant methods
    array_list_instance::size_total(void) const -> u32 { }
    array_list_instance::size_free(void) const -> u32 { }
    array_list_instance::size_used(void) const -> u32 { }
    u32 array_list_instance::index_of          (const t* element)                                               const;
    u32 array_list_instance::to_buffer         (buffer*           to, const u32 index = 0, const u32 count = 0) const;
    u32 array_list_instance::to_buffer         (buffer&           to, const u32 index = 0, const u32 count = 0) const;
    u32 array_list_instance::to_sub_array_list (array_list<type>* to, const u32 index = 0, const u32 count = 0) const;
    u32 array_list_instance::to_sub_array_list (array_list<type>& to, const u32 index = 0, const u32 count = 0) const;

    // mutable methods
    void array_list_instance::reset            (void);
    void array_list_instance::reverse          (void);
    u32  array_list_instance::remove           (const type* element);
    u32  array_list_instance::remove_at        (const u32   index,    const u32 index = 0);
    u32  array_list_instance::push_back        (const type* elements, const u32 count = 1);
    u32  array_list_instance::push_front       (const type* elements, const u32 count = 1);
    void array_list_instance::insert_at        (const type* elements, const u32 index, const u32 count = 1);


};