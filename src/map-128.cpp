#pragma once

#include "sld-collections.hpp"

namespace sld {

    struct map_128 {
        value* array_value;
        key*   array_key;
        h128*  array_hash; 
        u128   size_value;
        u128   size_key;
        u128   capacity;       
        u128   count;       
    };

};