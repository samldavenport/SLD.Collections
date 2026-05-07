#pragma once

#include "sld-collections.hpp"

namespace sld {
    
    struct set_32 {
        element* elements;
        h32*     hashes;        
        u32      stride;
        u32      capacity;
        u32      count;
    };
};