#pragma once

#include "sld-collections.hpp"

namespace sld {

    struct buffer {
        byte* data;
        u32   size;
        u32   length;
    };

    static constexpr u32 BUFFER_STRUCT_SIZE = sizeof(data_buffer);

};