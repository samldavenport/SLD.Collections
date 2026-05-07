#pragma once

#include "sld-collections.hpp"

namespace sld {

    struct queue_list {
        void*  elements;
        u32   stride;
        u32   capacity;
        u32   count;
    };

};