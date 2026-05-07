#include "sld-collections.hpp"

namespace sld {

    struct queue_buffer {
        byte* data;
        u32   size;
        u32   head;
        u32   tail;
    };

};