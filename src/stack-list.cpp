#pragma once

#include "sld-collections.hpp"

#define STACK_LIST_STATIC_FUNC template<typename type> static auto stack_list<type>::


namespace sld {
    
    STACK_LIST_STATIC_FUNC
    create(
        const u32 capacity) -> stack_list<type>* {

        
    }

    STACK_LIST_STATIC_FUNC
    memory_size(
        const u32 capacity) -> u32 {

    }

    STACK_LIST_STATIC_FUNC
    init(
        const u32 size,
        void*     memory) -> stack_list<type>* {

    }

    STACK_LIST_STATIC_FUNC
    destroy(
        stack_list<type>* sl) -> void {

    }

    // constant methods        
    bool          validate     (void)            const;
    void          assert_valid (void)            const;
    const t*      peek         (const u32 count) const;
    u32           size_used    (void)            const;
    u32           size_free    (void)            const;
    void          to_buffer    (buffer* buffer)  const;
    void          to_buffer    (buffer& buffer)  const;

    // mutable methods
    void          reset        (void);
    type*         pull         (const u32 count);
    u32           push         (const u32 count, const type* elements);

};