#pragma once

#include "sld-collections.hpp"

namespace sld {

    struct map_64 {
        value* array_value;
        key*   array_key;
        h64*   array_hash; 
        u32    size_value;
        u32    size_key;
        u32    capacity;       
        u32    count;       
    };

};