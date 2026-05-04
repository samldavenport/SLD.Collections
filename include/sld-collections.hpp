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
    struct array_list;
    struct stack_list;
    struct queue_list;
    struct heap;
    struct set;
    struct dictionary;
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
        u32 append_to     (const buffer*  to, const u32   offset = 0)                    const;
        u32 append_to     (const buffer&  to, const u32   offset = 0)                    const;
        u32 copy_to       (const u32 to_size, const byte* to_data, const u32 offset = 0) const;
        u32 append_to     (const u32 to_size, const byte* to_data, const u32 offset = 0) const;
        u32 to_sub_buffer (buffer*        to, const u32   start,   const u32 length)     const;        
        u32 to_sub_buffer (buffer&        to, const u32   start,   const u32 length)     const;        
    
        // mutable methods    
        u32 copy_from   (const buffer* from,  const u32   offset = 0);
        u32 append_from (const buffer* from,  const u32   offset = 0);
        u32 copy_from   (const buffer& from,  const u32   offset = 0);
        u32 append_from (const buffer& from,  const u32   offset = 0);
        u32 copy_from   (const u32 from_size, const byte* from_data, const u32 offset = 0);
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

        // static methods
        static array<t>* create      (const u32 capacity);
        static u32       memory_size (const u32 capacity);
        static void      init        (const u32 capacity, vptr data);
        static void      destroy     (array<t>* b);

        // constant methods
        u32              size_free    (void)                                                            const;
        u32              size_used    (void)                                                            const;
        u32              copy_to      (const array<t>* to, const u32 offset = 0)                        const;
        u32              copy_to      (const array<t>& to, const u32 offset = 0)                        const;
        u32              append_to    (const array<t>* to, const u32 offset = 0)                        const;
        u32              append_to    (const array<t>& to, const u32 offset = 0)                        const;
        u32              copy_to      (const u32  to_size, const t*  to_elements, const u32 offset = 0) const;
        u32              append_to    (const u32  to_size, const t*  to_elements, const u32 offset = 0) const;
        u32              to_sub_array (array<y>*       to, const u32 start,       const u32 count)      const;        
    
        // mutable methods    
        u32              copy_from   (const array<t>* from, const u32 offset = 0);
        u32              copy_from   (const array<t>& from, const u32 offset = 0);
        u32              copy_from   (const u32  from_size, const t* from_elements, const u32 offset = 0);
        u32              append_from (const array<t>* from, const u32 offset = 0);
        u32              append_from (const array<t>& from, const u32 offset = 0);
        u32              append_from (const u32  from_size, const t* from_elements, const u32 offset = 0);

        // operators
        t&       operator[] (const u32 index);
        t*       operator[] (const u32 index);
        const t* operator[] (const u32 index) const;
        const t& operator[] (const u32 index) const;
    };

    //-------------------------------------------------------------------
    // ARRAY LIST
    //-------------------------------------------------------------------

    template<typename t>
    struct array_list {
        
        // properties
        t*  elements;
        u32 capacity;
        u32 count;

        // static methods
        static array_list<t>* create      (const u32 capacity);
        static u32            memory_size (const u32 capacity);
        static void           init        (const u32 capacity, vptr data);
        static void           destroy     (array_list<t>* al);

        // constant methods
        u32 size_total        (void)                                                        const;
        u32 size_free         (void)                                                        const;
        u32 size_used         (void)                                                        const;
        u32 index_of          (const t* element)                                            const;
        u32 to_buffer         (buffer*        to, const u32 index = 0, const u32 count = 0) const;
        u32 to_buffer         (buffer&        to, const u32 index = 0, const u32 count = 0) const;
        u32 to_array          (array<t>*      to, const u32 index = 0, const u32 count = 0) const;
        u32 to_array          (array<t>&      to, const u32 index = 0, const u32 count = 0) const;
        u32 to_sub_array_list (array_list<t>* to, const u32 index = 0, const u32 count = 0) const;
        u32 to_sub_array_list (array_list<t>& to, const u32 index = 0, const u32 count = 0) const;

        // mutable methods
        void reset      (void);
        void reverse    (void);
        u32  remove     (const t* element);
        u32  remove_at  (const u32 index, const u32 count = 0);
        u32  push_back  (const t* elements, const u32 count = 1);
        u32  push_front (const t* elements, const u32 count = 1);
        void insert_at  (const t* elements, const u32 index, const u32 count = 1);

        // operators
        t*       operator[] (u32 index);
        const t* operator[] (u32 index) const;
        t&       operator[] (u32 index);
        const t& operator[] (u32 index) const;
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
        static stack* create       (const u32 size);
        static u32    memory_size  (const u32 size);
        static void   init         (const u32 size, void* memory);
        static void   destroy      (stack* stack);

        // constant methods        
        bool          validate     (void)           const;
        void          assert_valid (void)           const;
        u32           size_used    (void)           const;
        u32           size_free    (void)           const;
        const byte*   peek         (const u32 size) const;
        void          to_buffer    (buffer* to)     const;
        void          to_buffer    (buffer& to)     const;
        
        // mutable methods
        void          reset        (void);
        const byte*   peek         (const u32 size);
        byte*         pull         (const u32 size);
        u32           push         (const u32 size, const byte* data);
    };


    //-------------------------------------------------------------------
    // STACK LIST
    //-------------------------------------------------------------------

    template<typename t>
    struct stack_list {

        // properties
        t*  elements;
        u32 capacity;
        u32 count;

        // static methods
        static stack* create       (const u32 capacity);
        static u32    memory_size  (const u32 capacity);
        static void   init         (const u32 size, void* memory);
        static void   destroy      (stack_list<t>* sl);

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
        t*            pull         (const u32 count);
        u32           push         (const u32 count, const t* elements);

    };

    //-------------------------------------------------------------------
    // QUEUE
    //-------------------------------------------------------------------

    struct queue {

        // properties
        byte* data;
        u32   size;
        u32   head;
        u32   tail;

        // static methods
        static stack*              create       (const u32 capacity);
        static u32                 memory_size  (const u32 capacity);
        static void                init         (const u32 size, void* memory);
        static void                destroy      (queue q);
        
        // constant methods
        bool                       validate     (void)           const;
        void                       assert_valid (void)           const;
        u32                        size_used    (void)           const;
        u32                        size_free    (void)           const;
        void                       to_buffer    (buffer* buffer) const;
        void                       to_buffer    (buffer& buffer) const;
        template<typename t> void  to_array     (array<t>* buffer) const;
        template<typename t> void  to_array     (array<t>& buffer) const;

        // mutable methods
        void        reset        (void);
        const byte* peek         (void);
        byte*       dequeue      (const u32 size);
        u32         enqueue      (const u32 size, const byte* data,);
    };

    //-------------------------------------------------------------------
    // QUEUE LIST
    //-------------------------------------------------------------------

    template<typename t>
    struct queue_list {

        // properties
        t*    elements;
        u32   capacity;
        u32   head;
        u32   tail;

        // static methods
        static stack* create           (const u32 capacity);
        static u32    memory_size      (const u32 capacity);
        static void   init             (const u32 size, void* memory);
        static void   destroy          (queue q);
        
        // constant methods
        bool                       validate     (void)             const;
        void                       assert_valid (void)             const;
        u32                        size_used    (void)             const;
        u32                        size_free    (void)             const;
        const t*                   peek         (const u32 size)   const;
        void                       to_buffer    (buffer*   buffer) const;
        void                       to_buffer    (buffer&   buffer) const;
        template<typename t> void  to_array     (array<t>* array)  const;
        template<typename t> void  to_array     (array<t>& array)  const;

        // mutable methods
        void        reset   (void);
        const byte* peek    (void);
        t*          dequeue (const u32 count);
        u32         enqueue (const t* elements, const u32 count = 1);
    };


    //-------------------------------------------------------------------
    // MAP
    //-------------------------------------------------------------------

    template<typename key, typename value>
    struct map {

        // properties
        key*   keys;
        value* values;
        u32*   hashes;
        u32    capacity;
        u32    count;

        // static methods
        static stack* create       (const u32 capacity);
        static u32    memory_size  (const u32 capacity);
        static void   init         (const u32 size, void* memory);
        static void   destroy      (map<key,value>* m);
        static u32    hash_of      (const key& k);   
        static void   hash_of      (const key& k*, const u32 count, u32* hashes);

        // constant methods
        bool          validate     (void)                              const;
        void          assert_valid (void)                              const;
        u32           size_used    (void)                              const;
        u32           size_free    (void)                              const;
        bool          exists       (const k& key)                      const;
        bool          exists       (const k* key, const u32 count = 1) const;

        // mutable methods
        void          reset        (void);
        bool          remove       (const key& k);
        u32           remove       (const key* k, const u32 count = 1);
        bool          insert       (const key& k, const value v&); 
        u32           insert       (const key* k, const value v*, const u32 count = 1); 

        // operators
        value*        operator[]   (const key* k);
        value&        operator[]   (const key* k);
        value*        operator[]   (const key& k);
        value&        operator[]   (const key& k);
        const value*  operator[]   (const key* k) const;
        const value&  operator[]   (const key* k) const;
        const value*  operator[]   (const key& k) const;
        const value&  operator[]   (const key& k) const;
    };

    //-------------------------------------------------------------------
    // SET
    //-------------------------------------------------------------------

    template<typename t>
    struct set {
        
        // properties
        t*   elements;
        u32* hashes
        u32  capacity;
        u32  count;

        // static methods
        static array_list<t>* create      (const u32 capacity);
        static u32            memory_size (const u32 capacity);
        static void           init        (const u32 capacity, vptr data);
        static void           destroy     (array_list<t>* al);
        static u32            hash_of     (const t* element);

        // constant methods
        u32 size_total        (void)                                                        const;
        u32 size_free         (void)                                                        const;
        u32 size_used         (void)                                                        const;
        u32 index_of          (const t* element)                                            const;
        u32 to_buffer         (buffer*        to, const u32 index = 0, const u32 count = 0) const;
        u32 to_buffer         (buffer&        to, const u32 index = 0, const u32 count = 0) const;
        u32 to_array          (array<t>*      to, const u32 index = 0, const u32 count = 0) const;
        u32 to_array          (array<t>&      to, const u32 index = 0, const u32 count = 0) const;
        u32 to_sub_array_list (array_list<t>* to, const u32 index = 0, const u32 count = 0) const;
        u32 to_sub_array_list (array_list<t>& to, const u32 index = 0, const u32 count = 0) const;

        // mutable methods
        void reset      (void);
        void reverse    (void);
        u32  remove     (const t* element);
        u32  remove_at  (const u32 index, const u32 count = 0);
        u32  push_back  (const t* elements, const u32 count = 1);
        u32  push_front (const t* elements, const u32 count = 1);
        void insert_at  (const t* elements, const u32 index, const u32 count = 1);

        // operators
        t*       operator[] (u32 index);
        t&       operator[] (u32 index);
        const t* operator[] (u32 index) const;
        const t& operator[] (u32 index) const;
    };

    //-------------------------------------------------------------------
    // SPARSE ARRAY
    //-------------------------------------------------------------------

    template<typename t>
    struct sparse_array {

        // properties
        t*   sparse_elements;
        u32* dense_indexes;
        u32* dense_hashes;
        f32  percentage_max;
        u32  capacity;
        u32  count;

    };

    //-------------------------------------------------------------------
    // UTILITIES
    //-------------------------------------------------------------------

    constexpr inline u64  size_kilobytes   (const u64 n_kilobytes)               { return (n_kilobytes * 1024);                               }
    constexpr inline u64  size_megabytes   (const u64 n_megabytes)               { return (n_megabytes * 1024 * 1024);                        }
    constexpr inline u64  size_gigabytes   (const u64 n_gigabytes)               { return (n_gigabytes * 1024 * 1024 * 1024);                 }
    constexpr inline u64  size_align       (const u64 size, const u64 alignment) { return ((size + alignment - 1) / (alignment * alignment)); }
    constexpr inline u64  size_align_pow_2 (const u64 size, const u64 alignment) { return ((size + alignment - 1) & ~(alignment - 1));        }
    constexpr inline bool size_is_pow_2    (const u64 size)                      { return (((size > 0) && ((size & (size - 1)) == 0)));       }               

};

#endif //SLD_COLLECTIONS_HPP