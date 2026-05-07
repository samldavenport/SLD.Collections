#pragma once

#include "sld-collections.hpp"

namespace sld {


    struct stack_buffer {
        byte* data;
        u32   size;
        u32   ptr;        
    };

    constexpr u32 STRUCT_SIZE_STACK_BUFFER = sizeof(stack_buffer);

};