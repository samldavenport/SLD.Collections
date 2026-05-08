#include "sld-collections.hpp"

namespace sld {

    struct queue_buffer {
        byte* data;
        u32   size;
        u32   head;
        u32   tail;
    };

    
    SLD_COLLECTIONS_API u32             queue_memory_size                (const u32 queue_size);
    SLD_COLLECTIONS_API queue_buffer*   queue_buffer_create              (const u32 queue_size);
    SLD_COLLECTIONS_API queue_buffer*   queue_buffer_memory_init         (const u32 queue_size, void* mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void            queue_buffer_destroy             (queue_buffer* qb);    
    SLD_COLLECTIONS_API bool            queue_buffer_is_valid            (const queue_buffer* qb);
    SLD_COLLECTIONS_API void            queue_buffer_assert_valid        (const queue_buffer* qb);
    SLD_COLLECTIONS_API byte*           queue_buffer_data                (const queue_buffer* qb);
    SLD_COLLECTIONS_API u32             queue_buffer_size_total          (const queue_buffer* qb);
    SLD_COLLECTIONS_API u32             queue_buffer_size_free           (const queue_buffer* qb);
    SLD_COLLECTIONS_API u32             queue_buffer_size_used           (const queue_buffer* qb);
    SLD_COLLECTIONS_API const byte*     queue_buffer_head                (const queue_buffer* qb, const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*     queue_buffer_tail                (const queue_buffer* qb, const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*     queue_buffer_peek                (const queue_buffer* qb, const stack_buffer* sb, const u32 size);
    SLD_COLLECTIONS_API void            queue_buffer_reset               (queue_buffer* qb);
    SLD_COLLECTIONS_API const byte*     queue_buffer_peek                (queue_buffer* qb);
    SLD_COLLECTIONS_API u32             queue_buffer_push_data           (queue_buffer* qb, const u32 size, const byte* data);
    SLD_COLLECTIONS_API byte*           queue_buffer_pop_data            (queue_buffer* qb, const u32 size);

};