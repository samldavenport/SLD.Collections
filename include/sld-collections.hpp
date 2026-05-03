#ifndef SLD_COLLECTIONS_HPP
#define SLD_COLLECTIONS_HPP

#include <Windows.h>
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
    struct buffer;
    struct array;
    struct stack;
    struct queue;
    struct array_li st;
    struct stack_list;
    struct queue_list;
    struct heap;
    struct set;
    struct hash_map;
    struct sparse_array;
    struct single_linked_list;
    struct single_linked_node;
    struct double_linked_list;
    struct double_linked_node;

    //-------------------------------------------------------------------
    // BUFFER
    //-------------------------------------------------------------------

    struct buffer {

        // properties  
        byte* data;
        u32   size;
        u32   length;

        // static methods
        static buffer* create      (const u32 size);
        static u32     memory_size (const u32 size);
        static void    init        (const u32 size, byte* data);
        static void    destroy     (buffer* b);

        // constant methods
        u32 size_free     (void)                                                         const;
        u32 size_used     (void)                                                         const;
        u32 copy_to       (const buffer*  to, const u32   offset = 0)                    const;
        u32 copy_to       (const buffer&  to, const u32   offset = 0)                    const;
        u32 copy_to       (const u32 to_size, const byte* to_data, const u32 offset = 0) const;
        u32 append_to     (const buffer*  to, const u32   offset = 0)                    const;
        u32 append_to     (const buffer&  to, const u32   offset = 0)                    const;
        u32 append_to     (const u32 to_size, const byte* to_data, const u32 offset = 0) const;
        u32 to_sub_buffer (buffer*        to, const u32   start,   const u32 length)     const;        
        u32 to_sub_buffer (buffer&        to, const u32   start,   const u32 length)     const;        
    
        // mutable methods    
        u32 copy_from   (const buffer* from, const u32 offset = 0);
        u32 copy_from   (const buffer& from, const u32 offset = 0);
        u32 copy_from   (const u32 from_size, const byte* from_data, const u32 offset = 0);
        u32 append_from (const buffer* from, const u32 offset = 0);
        u32 append_from (const buffer& from, const u32 offset = 0);
        u32 append_from (const u32 from_size, const byte* from_data, const u32 offset = 0);

        // operators
        byte&       operator[] (const u32 index);
        byte&       operator[] (const u32 index);
        const byte& operator[] (const u32 index) const;
        const byte& operator[] (const u32 index) const;
    };

    //-------------------------------------------------------------------
    // ARRAY
    //-------------------------------------------------------------------

    template<typename t>
    struct array {

        // properties  
        t*  elements;
        u32 capacity;
        u32 count;

        // static methods
        static array<t>* create      (const u32 size);
        static u32       memory_size (const u32 size);
        static void      init        (const u32 size, byte* data);
        static void      destroy     (array<t>* b);

        // constant methods
        u32 size_free   (void)                                                       const;
        u32 size_used   (void)                                                       const;
        u32 copy_to     (const array<t>* to, const u32 offset = 0)                   const;
        u32 copy_to     (const array<t>& to, const u32 offset = 0)                   const;
        u32 copy_to     (const u32 to_size,  const t* to_data, const u32 offset = 0) const;
        u32 append_to   (const array<t>* to, const u32 offset = 0)                   const;
        u32 append_to   (const array<t>& to, const u32 offset = 0)                   const;
        u32 append_to   (const u32 to_size,  const t* to_data, const u32 offset = 0) const;
        u32 to_sub_array (array<y>*        to, const u32   start,   const u32 length)     const;        
    
        // mutable methods    
        u32 copy_from   (const array<t>* from, const u32 offset = 0);
        u32 copy_from   (const array<t>& from, const u32 offset = 0);
        u32 copy_from   (const u32  from_size, const t* from_data, const u32 offset = 0);
        u32 append_from (const array<t>* from, const u32 offset = 0);
        u32 append_from (const array<t>& from, const u32 offset = 0);
        u32 append_from (const u32 from_size,  const t* from_data, const u32 offset = 0);

        // operators
        t& operator[] (const u32 index);
        t* operator[] (const u32 index);
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

    struct stack {

        // properties
        byte* data;
        u32   size;
        u32   ptr;

        // static methods
        static stack* create           (const u32 size);
        static u32    memory_size      (const u32 size);
        static void   init             (const u32 size, void* memory);
        static void   destroy          (stack* stack);

        // constant methods        
        bool          validate         (void)           const;
        void          assert_valid     (void)           const;
        u32           size_used        (void)           const;
        u32           size_free        (void)           const;
        void          to_buffer        (buffer* buffer) const;
        void          to_buffer        (buffer& buffer) const;
        
        // mutable methods
        void          reset            (void);
        const byte*   peek             (const u32 size);
        byte*         pull             (const u32 size);
        u32           push             (const u32 size, const byte* data);
    };


    //-------------------------------------------------------------------
    // STACK LIST
    //-------------------------------------------------------------------

    template<typename t> stack_list<t>* stack_list_create           (const u32 size);
    template<typename t> void           stack_list_destroy          (stack_list<t>* sl);
    template<typename t> u32            stack_list_memory_size      (const u32 size);
    template<typename t> stack_list<t>* stack_list_init_from_memory (void* memory, const u32 size);
    template<typename t> bool           stack_list_validate         (const stack_list<t>* sl);
    template<typename t> void           stack_list_assert_valid     (const stack_list<t>* sl);
    template<typename t> u32            stack_list_head             (const stack_list<t>* sl);
    template<typename t> buffer*        stack_list_to_buffer        (const stack_list<t>* sl);
    template<typename t> u32            stack_list_size_total       (const stack_list<t>* sl);
    template<typename t> u32            stack_list_size_used        (const stack_list<t>* sl);
    template<typename t> u32            stack_list_size_free        (const stack_list<t>* sl);
    template<typename t> const byte*    stack_list_peek             (const stack_list<t>* sl, const u32 size);
    template<typename t> void           stack_list_reset            (stack_list<t>* sl);
    template<typename t> byte*          stack_list_push             (stack_list<t>* sl, const u32 size);
    template<typename t> byte*          stack_list_pull             (stack_list<t>* sl, const u32 size);


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

    constexpr inline u64  size_kilobytes   (const u64 n_kilobytes)               { return (n_kilobytes * 1024);                               }
    constexpr inline u64  size_megabytes   (const u64 n_megabytes)               { return (n_megabytes * 1024 * 1024);                        }
    constexpr inline u64  size_gigabytes   (const u64 n_gigabytes)               { return (n_gigabytes * 1024 * 1024 * 1024);                 }
    constexpr inline u64  size_align       (const u64 size, const u64 alignment) { return ((size + alignment - 1) / (alignment * alignment)); }
    constexpr inline u64  size_align_pow_2 (const u64 size, const u64 alignment) { return ((size + alignment - 1) & ~(alignment - 1));        }
    constexpr inline bool size_is_pow_2    (const u64 size)                      { return (((size > 0) && ((size & (size - 1)) == 0)));       }               

};

#endif //SLD_COLLECTIONS_HPP