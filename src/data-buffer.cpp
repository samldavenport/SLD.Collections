#pragma once

#include "sld-collections.hpp"

namespace sld {

    struct data_buffer {
        byte* data;
        u32   size;
        u32   length;
        b64   internal_memory;
    };

    static constexpr u32 BUFFER_STRUCT_SIZE = sizeof(data_buffer);

    SLD_COLLECTIONS_API u32
    data_buffer_memory_size(
        const u32 buffer_size) {

        assert(
            buffer_size != 0 &&
            buffer_size <  MAX_CAPACITY
        );

        const u32 mem_size = (BUFFER_STRUCT_SIZE + buffer_size); 

        return(mem_size);
    }

    SLD_COLLECTIONS_API data_buffer*
    data_buffer_create(
        const u32 buffer_size) {

        assert(
            buffer_size != 0 &&
            buffer_size <  MAX_CAPACITY
        );

        const u32 mem_size = data_buffer_memory_size(buffer_size);
        assert(mem_size > BUFFER_STRUCT_SIZE);

        vptr mem = malloc(mem_size);
        assert(mem != NULL);

        auto db             = (data_buffer*)mem;
        db->data            = (byte*)(mem + BUFFER_STRUCT_SIZE);
        db->size            = buffer_size;
        db->length          = 0;
        db->internal_memory = true;
        buffer_assert_valid(db);

        return(db); 
    }

    SLD_COLLECTIONS_API data_buffer*
    data_buffer_memory_init(
        const u32 buffer_size,
        const u32 mem_size,
        void*     mem_ptr) {

        const u32 size_min  = (BUFFER_STRUCT_SIZE + buffer_size);
        const u32 size_diff = (mem_size - buffer_size);

        assert(
            buffer_size != 0    &&
            mem_ptr     != NULL &&
            mem_size    >= size_min
            size_diff   == BUFFER_STRUCT_SIZE
        );

        auto db             = (data_buffer*)mem_ptr;
        db->data            = (byte*)(mem_ptr + BUFFER_STRUCT_SIZE);
        db->size            = buffer_size;
        db->length          = 0;
        db->internal_memory = false;
        buffer_assert_valid(db);

        return(db);
    }
    
    SLD_COLLECTIONS_API void
    data_buffer_destroy(
        data_buffer* db) {

        buffer_assert_valid(db);
        assert(db->internal_memory == true);

        zero_memory((vptr)db->data, db->size);

        db->data            = NULL;
        db->size            = 0
        db->length          = 0
        db->internal_memory = false

        free(db);
    }

    SLD_COLLECTIONS_API bool
    data_buffer_is_valid(
        const data_buffer* db) {

        assert(db);

        const bool is_valid = (
            db->data   != NULL &&
            db->size   != 0    &&
            db->length <= db->size
        );

        return(is_valid);
    }

    SLD_COLLECTIONS_API void
    data_buffer_assert_valid(
        const data_buffer* db) {

        const bool is_valid = data_buffer_is_valid(is_valid);
    }

    SLD_COLLECTIONS_API u32
    data_buffer_size_remaining(
        const data_buffer* db) {

        data_buffer_assert_valid(db);

        const u32 size_remaining = (db->size - db->length);
        return(size_remaining);
    }

    SLD_COLLECTIONS_API u32
    data_buffer_append_from_a_to_b(
        const data_buffer* db_a,
        data_buffer*       db_b,
        const u32          db_a_offset) {

        assert(
            data_buffer_is_valid(db_a) &&
            data_buffer_is_valid(db_b) &&
            db_a_offset < db_a->length
        );

        vptr       dst              = (vptr)&db_b->data[db_b->length];
        const vptr src              = (vptr)&db_a->data[db_a_offset];
        const u32  length_requested = (db_a->length - db_a_offset);
        const u32  length_available = (db_b->size   - db_b->length); 
        const u32  length_actual    = (length_requested <= length_available)
            ? length_requested
            : length_requested - length_available;

        if (length_available == 0) {
            return(0);
        }

        const errno_t error = memmove_s(
            dst,
            length_available,
            src,
            length_actual
        );
        assert(error == 0);

        return(length_actual);
    }

    SLD_COLLECTIONS_API u32
    data_buffer_copy_to_dst(
        const data_buffer* db, 
        byte*              dst_memory,
        const u32          dst_size,
        const u32          db_offset) {

        assert(
            data_buffer_is_valid(db) &&
            dst_memory != NULL       &&
            dst_size   != 0          &&
            db_offset  <  db->length
        );
    
        const vptr src            = (vptr)&db->data[db_offset];
        const u32  size_requested = (db->length - db_offset);
        const u32  size_actual    = (size_requested <= dst_size)
            ? size_requested
            : size_requested - dst_size;

        const errno_t error = memmove_s(
            (vptr)dst_memory,
            size_actual,
            src,
            size_requested
        );
        assert(error == 0);

        return(size_actual);
    }

    SLD_COLLECTIONS_API u32
    data_buffer_copy_from_a_to_b(
        const data_buffer* db_a,
        data_buffer*       db_b,        
        const u32          db_a_offset,
        const u32          db_b_offset) {
    
    }

    SLD_COLLECTIONS_API void
    data_buffer_reset(
        data_buffer* db) {

        data_buffer_assert_valid(db);

        zero_memory((vptr)db->data, db->size);
        db->length = 0;
    }

    SLD_COLLECTIONS_API u32
    data_buffer_append_from_src(
        data_buffer* b,
        const byte* src_memory,
        const u32   src_size) {

    }

    SLD_COLLECTIONS_API u32
    data_buffer_copy_from_src(
        data_buffer* b,
        const u32    b_offset, 
        const byte*  src_memory,
        const u32    src_size) {

    }
};