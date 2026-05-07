#pragma once

#include "sld-collections.hpp"

namespace sld {
    
    struct set_64 {
        element* elements;
        h64*     hashes;        
        u32      stride;
        u32      capacity;
        u32      count;
    };
};