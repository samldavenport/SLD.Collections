#ifndef SLD_COLLECTIONS_HPP
#define SLD_COLLECTIONS_HPP

#include <cstdint>
#include <assert.h>

namespace sld {

    static const u32 INVALID_INDEX = 0xFFFFFFFF;
    static const u32 MAX_COUNT     = 0xFFFFFFFE;
    static const u32 STRIDE_NONE   = 0;

    // signed integers
    typedef int8_t   s8;
    typedef int16_t  s16;
    typedef int32_t  s32;
    typedef int64_t  s64;

    // unsigned integers
    typedef uint8_t  u8;
    typedef uint16_t u16;
    typedef uint32_t u32;
    typedef uint64_t u64;

    // booleans
    typedef u8  b8;
    typedef u16 b16;
    typedef u32 b32;
    typedef u64 b64;

    // characters
    typedef char    c8;
    typedef wchar_t c16;

    // memory
    typedef u8       byte;
    typedef void*    vptr;
    typedef intptr_t addr;

    // collections
    class collection_manager;
    class buffer;
    class array;
    class array_list;
    class stack;
    class stack_list;
    class queue;
    class queue_list;
    class heap;
    class set;
    class hash_map;
    class sparse_array;
    class single_linked_list;
    class single_linked_node;
    class double_linked_list;
    class double_linked_node;

    //-------------------------------------------------------------------
    // COLLECTION MANAGER
    //-------------------------------------------------------------------

    class collection_manager {
        
    private:

        struct collection_block {
            collection_block* next;
            collection_block* prev;
        };

        struct {
            u32 total;
            u32 granularity;
        } _size;

        struct {
            collection_block* free;
            collection_block* used;
        } _block_list;
    
        collection_manager (const u32 size, const u32 granularity, vptr* memory);
        collection_manager (const u32 size, const u32 granularity);

        u32 size_total         (void) const;
        u32 size_free          (void) const;
        u32 size_used          (void) const;
        u32 size_block         (void) const;
        u32 count_blocks_total (void) const;
        u32 count_blocks_used  (void) const;
        u32 count_blocks_free  (void) const;

        void    reset         (void);
        buffer* create_buffer (const u32 size);
        array*  create_array  (const u32 size, const u32 stride = STRIDE_NONE);
        buffer* create_stack  (const u32 size, const u32 stride = STRIDE_NONE);
        

        template<typename t> array_list<t>*
        create_array_list(const u32 count);
        
        template<typename t> stack_list<t>*
        create_stack_list(const u32 count);
    
    };

    //-------------------------------------------------------------------
    // BUFFER
    //-------------------------------------------------------------------

    class buffer {
    
    private:

        byte* _data;
        u32   _size;
        u32   _length;
    
    public:

        buffer (const u32 size);
        buffer (const u32 size, byte* memory);

        void clear   (void);
        u32  append  (const buffer* src);
        u32  append  (const byte*   src_data, const u32 src_length);
        u32  copy_to (const buffer* dst) const;
        u32  copy_to (const byte*   dst_data, const u32 dst_size) const;

        byte&       operator[] (u32 index);
        const byte& operator[] (u32 index) const;
    };

    //-------------------------------------------------------------------
    // ARRAY
    //-------------------------------------------------------------------

    class array {
    
    private:
        byte* _data;
        u32   _size;
        u32   _length;
        u32   _stride;

    public:

        const buffer* to_buffer  (void) const;
        u32           size_total (void) const;
        u32           size_free  (void) const;
        u32           size_used  (void) const;
        u32           length     (void) const;
        u32           stride     (void) const;
        u32           capacity   (void) const;
        u32           count      (void) const;

        vptr  get      (const u32 index);
        u32   index_of (const vptr p);

        void  clear    (void);
        u32   add      (const vptr p);
        u32   add      (const vptr p, const u32 count);

        byte*       operator[] (u32 index);
        const byte* operator[] (u32 index) const;
    };

    //-------------------------------------------------------------------
    // ARRAY LIST
    //-------------------------------------------------------------------

    template<typename t>
    class array_list {
        
    private:
        t*  elements;
        u32 capacity;
        u32 count;

    public:

        buffer* to_buffer  (void) const;
        u32     size_total (void) const;
        u32     size_free  (void) const;
        u32     size_used  (void) const;
        u32     capacity   (void) const;
        u32     count      (void) const;
        t&      get        (void) const;
        t*      get        (void) const;
        u32     index_of   (const t* element) const;

        u32     add        (const t* element);
        u32     add        (const t* element, const u32 count);

        byte*       operator[] (u32 index);
        const byte* operator[] (u32 index) const;
        byte&       operator[] (u32 index);
        const byte& operator[] (u32 index) const;
    };




    //-------------------------------------------------------------------
    // STACK
    //-------------------------------------------------------------------

    class stack {
    
    private:
        byte* _data;
        u32   _size;
        u32   _stride;
        u32   _ptr;
    
    public:

        stack (const u32 size, const u32 stride);
        stack (const u32 size, const u32 stride, byte* mem);

        buffer*     to_buffer  (void)            const;
        u32         size_total (void)            const;
        u32         size_used  (void)            const;
        u32         size_free  (void)            const;
        const byte* peek       (const u32 count) const;
        const byte& peek       (const u32 count) const;

        void    reset       (void);
        u32     push        (const u32 size, const byte* data);
        byte*   pull        (const u32 size);
    };

    //-------------------------------------------------------------------
    // STACK LIST
    //-------------------------------------------------------------------

    template<typename t>
    class stack_list {
    
    private:
        t*  _elements;
        u32 _capacity;
        u32 _ptr;
    };


    //-------------------------------------------------------------------
    // QUEUE
    //-------------------------------------------------------------------

    class queue {

    private:

        byte* _data;
        u32   _size;
        u32   _stride;
        u32   _head;
        u32   _tail;

    public:

        queue (const u32 size, const u32 stride);
        queue (const u32 size, const u32 stride, byte* mem);

        const buffer* to_buffer  (void)            const;
        u32           size_total (void)            const;
        u32           size_used  (void)            const;
        u32           size_free  (void)            const;
        const byte*   peek       (const u32 count) const;
        const byte&   peek       (const u32 count) const;

        u32   enqueue (const u32 size, const byte* data);
        byte* dequeue (const u32 size);
    };


    //-------------------------------------------------------------------
    // QUEUE LIST
    //-------------------------------------------------------------------

    template<typename t>
    class queue_list {
        
    private:

        t*  _elements;
        u32 _capacity;
        u32 _head;
        u32 _tail;
    
    public:

        queue_list (const u32 size);
        queue_list (const u32 size, byte* mem);

        const buffer* to_buffer  (void)                const;
        u32           size_total (void)                const;
        u32           size_used  (void)                const;
        u32           size_free  (void)                const;
        u32           capacity   (void) const;
        u32           count      (void) const;
        const byte&   peek       (const u32 count = 0) const;

        u32 enqueue (const t* element, const u32 count = 0);
        u32 enqueue (const t& element);
        t*  dequeue (const u32 count = 0);
        t&  dequeue (const u32 count);
    };
};

#endif //SLD_COLLECTIONS_HPP