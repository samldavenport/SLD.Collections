#pragma once

#include "sld-collections.hpp"

namespace sld {
       
    void
    stack::init(
        void*     mem_ptr,
        const u32 mem_size) {

        assert(mem_ptr  != NULL);
        assert(mem_size != 0);

        _data     = (byte*)mem_ptr;
        _size     = mem_size;
        _position = 0;
    }

    void
    stack::reset(
        void) {

        validate();
        _position = 0;
    }

    u32 
    stack::push(
        const u32   size,
        const byte* data) {

        validate();
        return(0);
    }
    
    byte*
    stack::pull(
        const u32 size) {

        return(NULL);
    }

    void
    stack::validate(
        void) const {

        assert(_data != NULL);
        assert(_size != 0);
        assert(_position <= _size);
    }

    const byte*
    stack::head(
        void) const {

        return(NULL);
    }

    const byte*
    stack::tail(
        void) const {

        return(NULL);
    }

    const byte*
    stack::peek(
        const u32 size) const {

        return(NULL);
    }

    const u32
    stack::size_total (
        void) const {

        return(0);
    }

    const u32
    stack::size_free  (
        void) const {

        return(0);
    }

    const u32
    stack::size_used  (
        void) const {

        return(0);
    }

    template<typename t> t*
    push_struct(
        u32 count) {

        return(NULL);
    }

    template<typename t>
    t* pull_struct(
        u32 count) {

        return(NULL);
    }
};
