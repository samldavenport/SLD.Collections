#pragma once

#include "sld-collections.hpp"

namespace sld {

    struct stack_list {
        element*  elements;
        u32       stride;
        u32       capacity;
        u32       count;
    };

};