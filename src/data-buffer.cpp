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

    SLD_COLLECTIONS_API void
    data_buffer_assert_valid(
        const data_buffer* db) {

        const bool is_valid = (
            db         != NULL &&
            db->data   != NULL &&
            db->size   != 0    &&
            db->length <= db->size
        );
        assert(is_valid);
    }

    SLD_COLLECTIONS_API const byte*
    data_buffer_data(
        const data_buffer* db) {

        data_buffer_assert_valid(db);
        return(db->data)
    }

    SLD_COLLECTIONS_API u32
    data_buffer_size_total(
        const data_buffer* db) {

        data_buffer_assert_valid(db);
        return(db->size);
    }


    SLD_COLLECTIONS_API u32
    data_buffer_size_remaining(
        const data_buffer* db) {

        data_buffer_assert_valid(db);

        const u32 size_remaining = (db->size - db->length);
        return(size_remaining);
    }

    SLD_COLLECTIONS_API u32
    data_buffer_length(
        const data_buffer* db) {

        data_buffer_assert_valid(db);
        return(db->length);
    }

    SLD_COLLECTIONS_API u32
    data_buffer_copy_to_mem(
        const data_buffer* db,
        const u32          db_offset,
        const u32          db_size,
        byte*              mem_ptr,
        const u32          mem_size) {

        data_buffer_assert_valid(db);
        assert(
            db_offset <  db->length &&
            db_size   <= db->length &&
            mem_ptr   != NULL       &&
            mem_size  != 0          &&
            (db_offset + db_size) < db->size
        );

        const u32 bytes_available = (db->size - db->length);
        const u32 bytes_copied    = (db_size <= bytes_available)
            ? db_size
            : db_size - bytes_available;

        const errno_t error = memmove_s(
            mem_ptr,                    // dst mem
            mem_size,                   // dst size
            (vptr)&db->data[db_offset], // src mem
            bytes_copied                // src size
        );
        assert(error == 0);

        return(bytes_copied);
    }
    SLD_COLLECTIONS_API u32
    data_buffer_append_src_to_dst(
        const data_buffer* src_db,
        const u32          src_offset,
        const u32          src_size,
        data_buffer*       dst_db) {

        data_buffer_assert_valid(src_db);
        data_buffer_assert_valid(dst_db);

        assert(
            src_size > 0 &&
            (src_offset + src_size) < src_db->length; 
        );

        vptr       dst_mem            = (vptr)&dst_db->data[dst_db->length];
        const u32  dst_size_remaining = (dst_db->size - dst_db->length);
        const u32  dst_size           = (dst_size_remaining <= src_size) ? dst_size_remaining : (src_size - dst_size_remaining); 
        const vptr src_mem            = (vptr)&src_db->data[src_offset];

        const errno_t error = memmove_s(
            dst_mem,
            dst_size,
            src_mem,
            src_size
        );
        dst_db->length += dst_size;
        data_buffer_assert_valid(dst_db);

        return(dst_size);
    }

    SLD_COLLECTIONS_API u32
    data_buffer_copy_src_to_dst(
        const data_buffer* src_db,
        const u32          src_offset,
        const u32          src_size,
        data_buffer*       dst_db,
        const u32          dst_offset,
        const u32          dst_size) {

    }

    SLD_COLLECTIONS_API void
    data_buffer_reset(
        data_buffer* db) {

        data_buffer_assert_valid(db);
        db->length = 0;
        zero_memory((vptr)&db->data, db->size);
    }

    SLD_COLLECTIONS_API u32
    data_buffer_update(
        data_buffer* db,
        const u32    db_offset,
        const byte*  src_mem,
        const u32    src_size) {

        data_buffer_assert_valid(db);
        assert(
            db_offset <  db->length &&
            src_mem   != NULL       &&
            src_size  != 0
        );

        const u32 dst_size = (db->size - db->length);
        const u32 diff     = (db->length - db_offset);
        assert(diff <= dst_size);

        vptr dst_mem = (vptr)&db->data[db_offset];

        memmove_s(
            dst_mem,
            dst_size,
            src_mem,
            src_size
        );
    }   

    SLD_COLLECTIONS_API u32
    data_buffer_append_from_mem(
        data_buffer* db,
        const byte*  src_mem, 
        const u32    src_size) {
        
        data_buffer_assert_valid(db);
        assert(
            src_mem != NULL
        );

    }

};