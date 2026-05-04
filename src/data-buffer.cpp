#pragma once

#include "sld-collections.hpp"

namespace sld {

    //-------------------------------------------------------------------
    // CONSTANTS
    //-------------------------------------------------------------------

    static constexpr u32 BUFFER_STRUCT_SIZE = sizeof(data_buffer);

    //-------------------------------------------------------------------
    // STATIC METHODS
    //-------------------------------------------------------------------

    static data_buffer*
    data_buffer::create(
        const u32 buffer_size) {

        // allocate memory
        const u32 mem_size = data_buffer::memory_size(buffer_size); 
        vptr      mem_ptr  = malloc(mem_size); 
        assert(mem_ptr);

        // initialize memory
        data_buffer* db = data_buffer::init(mem_ptr, mem_size);

        // assert valid
        assert(
            db != NULL                &&
            db->is_valid()            &&
            db->size   == buffer_size &&
            db->length == 0
        );
        return(db);
    }

    static u32
    data_buffer::memory_size(
        const u32 buffer_size) {
        
        const u32 mem_size = (BUFFER_STRUCT_SIZE + buffer_size);
        return(mem_size);
    }

    static data_buffer* 
    data_buffer::init(
        const u32 memory_size,
        vptr      memory_ptr) {

        zero_memory(memory_ptr, memory_size);

        data_buffer* db = (data_buffer*)memory_ptr;
        db->data   = (memory_ptr  + BUFFER_STRUCT_SIZE);
        db->size   = (memory_size - BUFFER_STRUCT_SIZE);
        db->length = 0;

        return(db);
    }

    static void
    data_buffer::destroy(
        data_buffer* db) {

        assert(db != NULL && db->is_valid());

        const u32 memory_size = data_buffer::memory_size(db->size);

        zero_memory(memory_size, (vptr)db);

        free(db);
    }

    //-------------------------------------------------------------------
    // CONSTANT METHODS
    //-------------------------------------------------------------------

    u32
    data_buffer::size_free(
        void) const {

        this->assert_valid();
        return(this->size - this->length);
    }

    u32 data_buffer::copy_to       (const data_buffer*  to, const u32   offset = 0)                    const;
    u32 data_buffer::copy_to       (const data_buffer&  to, const u32   offset = 0)                    const;
    u32 data_buffer::append_to     (const data_buffer*  to, const u32   offset = 0)                    const;
    u32 data_buffer::append_to     (const data_buffer&  to, const u32   offset = 0)                    const;
    u32 data_buffer::copy_to       (const u32      to_size, const byte* to_data, const u32 offset = 0) const;
    u32 data_buffer::append_to     (const u32      to_size, const byte* to_data, const u32 offset = 0) const;
    u32 data_buffer::to_sub_buffer (data_buffer*        to, const u32   start,   const u32 length)     const;        
    u32 data_buffer::to_sub_buffer (data_buffer&        to, const u32   start,   const u32 length)     const;        

    //-------------------------------------------------------------------
    // MUTABLE METHODS
    //-------------------------------------------------------------------

    u32
    data_buffer::copy_from(
        const data_buffer* from,
        const u32          offset) {

    }
    
    u32
    data_buffer::append_from(
        const data_buffer* from,
        const u32          offset) {

    }
    
    u32
    data_buffer::copy_from(
        const data_buffer& from,
        const u32          offset) {

    }
    
    u32
    data_buffer::append_from(
        const data_buffer& from,
        const u32          offset) {

    }
    
    
    u32 data_buffer::copy_from   (const u32     from_size, const byte* from_data, const u32 offset);
    u32 data_buffer::append_from (const u32     from_size, const byte* from_data, const u32 offset);

    //-------------------------------------------------------------------
    // OPERATORS
    //-------------------------------------------------------------------

    byte&
    data_buffer::operator[] (
        const u32 index) {

        assert(
            this->is_valid() &&
            index < this->length 
        );
        return(this->data[index]);
    }

    const byte&
    data_buffer::operator[] (
        const u32 index) const {

        assert(
            this->is_valid() &&
            index < this->length 
        );
        return(this->data[index]);
    }
};