#pragma once

#include "sld-collections.hpp"

namespace sld {

    //-------------------------------------------------------------------
    // BUFFER
    //-------------------------------------------------------------------

    struct buffer {
        byte* data;
        u32   size;
        u32   length;
    };

    //-------------------------------------------------------------------
    // METHODS
    //-------------------------------------------------------------------

    bool
    buffer_validate(
        const buffer* b) {

        bool is_valid = (b != NULL);
        if (is_valid) {
            b &= (
                (b->data   != NULL) ||
                (b->size   != 0)    ||
                (b->length <= b->size)
            );
        }
        return(is_valid);
    }

    void
    buffer_assert_valid(
        const buffer* b) {

        const bool is_valid = buffer_validate(b);
        assert(is_valid);
    }

    u32
    buffer_size(
        const buffer* b) {

        buffer_validate(b);
        return(b->size);
    }

    u32
    buffer_length(
        const buffer* b) {

        buffer_validate(b);
        return(b->length);
    }

    byte*
    buffer_data(
        const buffer* b,
        const u32     index) {

        buffer_assert_valid(b);

        byte* data = (index < b->length)
            ? &b->data[index]
            : NULL;

        return(data);
    }

    void
    buffer_clear(
        buffer* b) {

        buffer_assert_valid(b);

        memset(b->data, 0, b->size);
    }

    u32
    buffer_append(
        buffer*       b,
        const buffer* src) {

        assert(
            buffer_validate(b) &&
            buffer_validate(src)
        );

        const u32 size_free    = (b->size - b->length);
        const u32 size_to_copy = (src->length <= size_free)
            ? size_free
            : (src->length - size_free);

        (void)memccpy(
            b->data,
            src->data,
            size_to_copy
        );

        return(size_to_copy);
    }
    
    u32
    buffer_append(
        buffer*     b,
        const byte* src_mem,
        const u32   src_length) {

    }
    
    u32
    buffer_copy_to(
        buffer*       b,
        const buffer* dst) {

    }
    
    u32
    buffer_copy_to(
        buffer*     b,
        const byte* dst_data,
        const u32   dst_size) {

    }
    
    byte*
    buffer_get(
        buffer*   b,
        const u32 index) {

    }
};