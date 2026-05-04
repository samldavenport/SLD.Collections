#ifndef SLD_COLLECTIONS_HPP
#define SLD_COLLECTIONS_HPP

#include <Windows.h>
#include <cstdint>
#include <assert.h>

#ifndef    SLD_COLLECTIONS_DEFAULT_HASH
#   define SLD_COLLECTIONS_DEFAULT_HASH 32
#endif

namespace sld {

    //-------------------------------------------------------------------
    // CONSTANTS
    //-------------------------------------------------------------------

    static const u32 INVALID_INDEX = 0xFFFFFFFF;
    static const u32 MAX_CAPACITY  = 0xFFFFFFFE;
    static const u32 STRIDE_NONE   = 0;

    //-------------------------------------------------------------------
    // TYPES
    //-------------------------------------------------------------------

    // signed integers
    typedef int8_t   s8;
    typedef int16_t  s16;
    typedef int32_t  s32;
    typedef int64_t  s64;

    struct s128 {
        union {
            struct {
                s64 hi;
                s64 lo;
            };
            s64 val[2];
        };
    };


    // unsigned integers
    typedef uint8_t  u8;
    typedef uint16_t u16;
    typedef uint32_t u32;
    typedef uint64_t u64;

    struct u128 {
        union {
            struct {
                u64 hi;
                u64 lo;
            };
            u64 val[2];
        };
    };

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

    //-------------------------------------------------------------------
    // COLLECTIONS
    //-------------------------------------------------------------------

    // buffer collections
    struct data_buffer;
    struct stack_buffer;
    struct queue_buffer;
    
    // list collections
    template<typename t> struct array_list;
    template<typename t> struct stack_list;
    template<typename t> struct queue_list;

    // linked collections
    template<typename type> struct single_linked_list;
    template<typename type> struct single_linked_node;
    template<typename type> struct double_linked_list;
    template<typename type> struct double_linked_node;
    // nodes
    template<typename type>
    struct single_linked_node {
        single_linked_node<type>* next;
        type                      element;        
    };

    template<typename type>
    struct double_linked_node {
        single_linked_node<type>* next;
        single_linked_node<type>* prev;
        type                      element;        
    };




    // hash collections
    template<typename value>               struct set_32;
    template<typename value>               struct set_64;
    template<typename value>               struct set_128;
    template<typename key, typename value> struct map_32;
    template<typename key, typename value> struct map_64; 
    template<typename key, typename value> struct map_128;
    template<typename key, typename value> struct sparse_array_32;
    template<typename key, typename value> struct sparse_array_64;
    template<typename key, typename value> struct sparse_array_128;

#if SLD_COLLECTIONS_DEFAULT_HASH == 64
    using set          = set_64;
    using map          = map_64;
    using sparse_array = sparse_array_64;
#elif SLD_COLLECTIONS_DEFAULT_HASH == 128
    using set          = set_128;
    using map          = map_128;
    using sparse_array = sparse_array_128;
#else
    using set          = set_32;
    using map          = map_32;
    using sparse_array = sparse_array_32;
#endif

    //-------------------------------------------------------------------
    // DATA BUFFER
    //-------------------------------------------------------------------

    struct data_buffer {

        // properties  
        byte* data;
        u32   size;
        u32   length;

        // static methods
        static buffer* create      (const u32 size);
        static u32     memory_size (const u32 size);
        static void    init        (const u32 size, byte* data);
        static void    destroy     (data_buffer* db);

        // constant methods
        u32 size_free     (void)                                                              const;
        u32 size_used     (void)                                                              const;
        u32 copy_to       (const data_buffer*  to, const u32   offset = 0)                    const;
        u32 copy_to       (const data_buffer&  to, const u32   offset = 0)                    const;
        u32 append_to     (const data_buffer*  to, const u32   offset = 0)                    const;
        u32 append_to     (const data_buffer&  to, const u32   offset = 0)                    const;
        u32 copy_to       (const u32      to_size, const byte* to_data, const u32 offset = 0) const;
        u32 append_to     (const u32      to_size, const byte* to_data, const u32 offset = 0) const;
        u32 to_sub_buffer (data_buffer*        to, const u32   start,   const u32 length)     const;        
        u32 to_sub_buffer (data_buffer&        to, const u32   start,   const u32 length)     const;        
    
        // mutable methods    
        u32 copy_from   (const data_buffer* from, const u32   offset = 0);
        u32 append_from (const data_buffer* from, const u32   offset = 0);
        u32 copy_from   (const data_buffer& from, const u32   offset = 0);
        u32 append_from (const data_buffer& from, const u32   offset = 0);
        u32 copy_from   (const u32     from_size, const byte* from_data, const u32 offset = 0);
        u32 append_from (const u32     from_size, const byte* from_data, const u32 offset = 0);

        // operators
        byte&       operator[] (const u32 index);
        byte&       operator[] (const u32 index);
        const byte& operator[] (const u32 index) const;
        const byte& operator[] (const u32 index) const;
    };

    //-------------------------------------------------------------------
    // STACK BUFFER
    //-------------------------------------------------------------------

    struct stack_buffer {

        // properties
        byte* data;
        u32   size;
        u32   ptr;

        // static methods
        static stack* create       (const u32 size);
        static u32    memory_size  (const u32 size);
        static void   init         (const u32 size, void* memory);
        static void   destroy      (stack_buffer* stack);

        // constant methods        
        bool          validate       (void)            const;
        void          assert_valid   (void)            const;
        u32           size_used      (void)            const;
        u32           size_free      (void)            const;
        const byte*   peek           (const u32 size)  const;
        void          to_data_buffer (data_buffer* to) const;
        void          to_data_buffer (data_buffer& to) const;
        
        // mutable methods
        void          reset        (void);
        const byte*   peek         (const u32 size);
        byte*         pull         (const u32 size);
        u32           push         (const u32 size, const byte* data);
    };

    //-------------------------------------------------------------------
    // QUEUE BUFFER
    //-------------------------------------------------------------------

    struct queue_buffer {

        // properties
        byte* data;
        u32   size;
        u32   head;
        u32   tail;

        // static methods
        static stack*              create       (const u32 capacity);
        static u32                 memory_size  (const u32 capacity);
        static void                init         (const u32 size, void* memory);
        static void                destroy      (queue_buffer* qb);
        
        // constant methods
        bool                       validate      (void)             const;
        void                       assert_valid  (void)             const;
        u32                        size_used     (void)             const;
        u32                        size_free     (void)             const;
        void                       to_buffer     (data_buffer*   to) const;
        void                       to_buffer     (data_buffer&   to) const;
        template<typename t> void  to_array_list (array_list<t>* to) const;
        template<typename t> void  to_array_list (array_list<t>& to) const;

        // mutable methods
        void        reset        (void);
        const byte* peek         (void);
        byte*       dequeue      (const u32 size);
        u32         enqueue      (const u32 size, const byte* data,);
    };

    //-------------------------------------------------------------------
    // ARRAY LIST
    //-------------------------------------------------------------------

    template<typename type>
    struct array_list {
        
        // properties
        type* elements;
        u32   capacity;
        u32   count;

        // static methods
        static array_list<t>* create      (const u32 capacity);
        static u32            memory_size (const u32 capacity);
        static void           init        (const u32 capacity, vptr data);
        static void           destroy     (array_list<type>* al);

        // constant methods
        u32 size_total        (void)                                                        const;
        u32 size_free         (void)                                                        const;
        u32 size_used         (void)                                                        const;
        u32 index_of          (const t* element)                                            const;
        u32 to_buffer         (buffer*           to, const u32 index = 0, const u32 count = 0) const;
        u32 to_buffer         (buffer&           to, const u32 index = 0, const u32 count = 0) const;
        u32 to_sub_array_list (array_list<type>* to, const u32 index = 0, const u32 count = 0) const;
        u32 to_sub_array_list (array_list<type>& to, const u32 index = 0, const u32 count = 0) const;

        // mutable methods
        void reset      (void);
        void reverse    (void);
        u32  remove     (const type* element);
        u32  remove_at  (const u32 index, const u32 count = 0);
        u32  push_back  (const type* elements, const u32 count = 1);
        u32  push_front (const type* elements, const u32 count = 1);
        void insert_at  (const type* elements, const u32 index, const u32 count = 1);

        // operators
        type*       operator[] (u32 index);
        type&       operator[] (u32 index);
        const type* operator[] (u32 index) const;
        const type& operator[] (u32 index) const;
    };

    //-------------------------------------------------------------------
    // STACK LIST
    //-------------------------------------------------------------------

    template<typename type>
    struct stack_list {

        // properties
        type* elements;
        u32   capacity;
        u32   count;

        // static methods
        static stack* create       (const u32 capacity);
        static u32    memory_size  (const u32 capacity);
        static void   init         (const u32 size, void* memory);
        static void   destroy      (stack_list<type>* sl);

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

    //-------------------------------------------------------------------
    // QUEUE LIST
    //-------------------------------------------------------------------

    template<typename type>
    struct queue_list {

        // properties
        type* elements;
        u32   capacity;
        u32   head;
        u32   tail;

        // static methods
        static queue_list<type>* create           (const u32 capacity);
        static u32               memory_size      (const u32 capacity);
        static void              init             (const u32 size, void* memory);
        static void              destroy          (queue_list<type>* ql);
        
        // constant methods
        bool                       validate     (void)                     const;
        void                       assert_valid (void)                     const;
        u32                        size_used    (void)                     const;
        u32                        size_free    (void)                     const;
        const t*                   peek         (const u32 size)           const;
        void                       to_buffer     (buffer* buffer)          const;
        void                       to_buffer     (buffer& buffer)          const;
        template<typename t> void  to_array_list (array_list<type>* array) const;
        template<typename t> void  to_array_list (array_list<type>& array) const;

        // mutable methods
        void        reset   (void);
        const byte* peek    (void);
        type*       dequeue (const u32 count);
        u32         enqueue (const type* elements, const u32 count = 1);
    };

    //-------------------------------------------------------------------
    // SINGLE LINKED LIST
    //-------------------------------------------------------------------

    template<typename type>
    struct single_linked_node {
        single_linked_node<type>* next;
        type                      element;        
    };

    template<typename type>
    struct single_linked_list {

        using node = single_linked_node<type>; 

        node* first;        
        node* last;
    };

    //-------------------------------------------------------------------
    // DOUBLE LINKED LIST
    //-------------------------------------------------------------------

    template<typename type>
    struct double_linked_node {

        double_linked_node<type>* next;
        double_linked_node<type>* prev;
        type                      element;        
    };

    template<typename type>
    struct double_linked_list {

        using node = double_linked_node<type>;
        
        node* first;        
        node* last;        
    };

    //-------------------------------------------------------------------
    // MAP 32
    //-------------------------------------------------------------------

    template<typename key, typename value>
    struct map_32 {

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
    // MAP 64
    //-------------------------------------------------------------------

    template<typename key, typename value>
    struct map_64 {

        // properties
        key*   keys;
        value* values;
        u64*   hashes;
        u32    capacity;
        u32    count;

        // static methods
        static stack* create       (const u32 capacity);
        static u32    memory_size  (const u32 capacity);
        static void   init         (const u32 size, void* memory);
        static void   destroy      (map<key,value>* m);

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
    // MAP 128
    //-------------------------------------------------------------------

    template<typename key, typename value>
    struct map_128 {

        // properties
        key*   keys;
        value* values;
        u128*  hashes;
        u32    capacity;
        u32    count;

        // static methods
        static stack* create       (const u32 capacity);
        static u32    memory_size  (const u32 capacity);
        static void   init         (const u32 size, void* memory);
        static void   destroy      (map<key,value>* m);

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
    // SET 32
    //-------------------------------------------------------------------

    template<typename t>
    struct set_32 {
        
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
    // SET 64
    //-------------------------------------------------------------------

    template<typename t>
    struct set_64 {
        
        // properties
        t*   elements;
        u64* hashes
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
    // SET 128
    //-------------------------------------------------------------------

    template<typename type>
    struct set_128 {
        
        // properties
        type* elements;
        u128* hashes
        u32   capacity;
        u32   count;

        // static methods
        static array_list<type>* create      (const u32 capacity);
        static u32               memory_size (const u32 capacity);
        static void              init        (const u32 capacity, vptr data);
        static void              destroy     (set_128<type>* al);
        static u32               hash_of     (const t* element);

        // constant methods
        u32 size_total        (void)                                                        const;
        u32 size_free         (void)                                                        const;
        u32 size_used         (void)                                                        const;
        u32 index_of          (const t* element)                                            const;
        u32 to_buffer         (buffer*        to, const u32 index = 0, const u32 count = 0) const;
        u32 to_buffer         (buffer&        to, const u32 index = 0, const u32 count = 0) const;
        u32 to_sub_set        (set_128<type>* to, const u32 index = 0, const u32 count = 0) const;
        u32 to_sub_set        (set_128<type>& to, const u32 index = 0, const u32 count = 0) const;

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
    // SPARSE ARRAY 32
    //-------------------------------------------------------------------

    template<typename key, typename value>
    struct sparse_array {

        // properties
        t*   sparse_elements;
        u32* dense_indexes;
        u32* dense_hashes;
        f32  percentage_max;
        u32  capacity;
        u32  count;

        // static methods
        static stack* create       (const u32 capacity, const f32 percentage_max);
        static u32    memory_size  (const u32 capacity, const f32 percentage_max);
        static void   init         (const u32 size, const f32 percentage_max, void* memory);
        static void   destroy      (sparse_array<key,value>* m);
        static u32    hash_of      (const key& k);   
        static void   hash_of      (const key& k*, const u32 count, u32* hashes);

        // constant methods
        bool          validate     (void)                              const;
        void          assert_valid (void)                              const;
        u32           size_used    (void)                              const;
        u32           size_free    (void)                              const;
        bool          exists       (const key& k)                      const;
        bool          exists       (const key* k, const u32 count = 1) const;
        u32           index_of     (const key* k)                      const;
        u32           index_of     (const key& k)                      const;

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
        const value*  operator[]   (const key* k)     const;
        const value&  operator[]   (const key* k)     const;
        const value*  operator[]   (const key& k)     const;
        const value&  operator[]   (const key& k)     const;
        const value&  operator[]   (const u32& index) const;

    };

    //-------------------------------------------------------------------
    // SPARSE ARRAY 64
    //-------------------------------------------------------------------

    template<typename key, typename value>
    struct sparse_array {

        // properties
        t*   sparse_elements;
        u32* dense_indexes;
        u64* dense_hashes;
        f32  percentage_max;
        u32  capacity;
        u32  count;

        // static methods
        static stack* create       (const u32 capacity, const f32 percentage_max);
        static u32    memory_size  (const u32 capacity, const f32 percentage_max);
        static void   init         (const u32 size, const f32 percentage_max, void* memory);
        static void   destroy      (sparse_array<key,value>* m);
        static u32    hash_of      (const key& k);   
        static void   hash_of      (const key& k*, const u32 count, u32* hashes);

        // constant methods
        bool          validate     (void)                              const;
        void          assert_valid (void)                              const;
        u32           size_used    (void)                              const;
        u32           size_free    (void)                              const;
        bool          exists       (const key& k)                      const;
        bool          exists       (const key* k, const u32 count = 1) const;
        u32           index_of     (const key* k)                      const;
        u32           index_of     (const key& k)                      const;

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
        const value*  operator[]   (const key* k)     const;
        const value&  operator[]   (const key* k)     const;
        const value*  operator[]   (const key& k)     const;
        const value&  operator[]   (const key& k)     const;
        const value&  operator[]   (const u32& index) const;

    };

    //-------------------------------------------------------------------
    // SPARSE ARRAY 128
    //-------------------------------------------------------------------

    template<typename key, typename value>
    struct sparse_array {

        // properties
        t*    sparse_elements;
        u32*  dense_indexes;
        u128* dense_hashes;
        f32   percentage_max;
        u32   capacity;
        u32   count;

        // static methods
        static stack* create       (const u32 capacity, const f32 percentage_max);
        static u32    memory_size  (const u32 capacity, const f32 percentage_max);
        static void   init         (const u32 size, const f32 percentage_max, void* memory);
        static void   destroy      (sparse_array<key,value>* m);
        static u32    hash_of      (const key& k);   
        static void   hash_of      (const key& k*, const u32 count, u32* hashes);

        // constant methods
        bool          validate     (void)                              const;
        void          assert_valid (void)                              const;
        u32           size_used    (void)                              const;
        u32           size_free    (void)                              const;
        bool          exists       (const key& k)                      const;
        bool          exists       (const key* k, const u32 count = 1) const;
        u32           index_of     (const key* k)                      const;
        u32           index_of     (const key& k)                      const;

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
        const value*  operator[]   (const key* k)     const;
        const value&  operator[]   (const key* k)     const;
        const value*  operator[]   (const key& k)     const;
        const value&  operator[]   (const key& k)     const;
        const value&  operator[]   (const u32& index) const;

    };

    //-------------------------------------------------------------------
    // SIZE UTILITIES
    //-------------------------------------------------------------------

    constexpr inline u64  size_kilobytes   (const u64 n_kilobytes)               { return (n_kilobytes * 1024);                               }
    constexpr inline u64  size_megabytes   (const u64 n_megabytes)               { return (n_megabytes * 1024 * 1024);                        }
    constexpr inline u64  size_gigabytes   (const u64 n_gigabytes)               { return (n_gigabytes * 1024 * 1024 * 1024);                 }
    constexpr inline u64  size_align       (const u64 size, const u64 alignment) { return ((size + alignment - 1) / (alignment * alignment)); }
    constexpr inline u64  size_align_pow_2 (const u64 size, const u64 alignment) { return ((size + alignment - 1) & ~(alignment - 1));        }
    constexpr inline bool size_is_pow_2    (const u64 size)                      { return (((size > 0) && ((size & (size - 1)) == 0)));       }               

    //-------------------------------------------------------------------
    // DATA HASHING
    //-------------------------------------------------------------------

    // data hash
    u32  hash32         (const vptr data, const u32 size);
    u64  hash64         (const vptr data, const u32 size);
    u128 hash128        (const vptr data, const u32 size);
    
    // data search
    u32  hash32_search  (const vptr data, const u32 size, const u32* hashes, const u32 count);
    u32  hash64_search  (const vptr data, const u32 size, const u32* hashes, const u32 count);
    u32  hash128_search (const vptr data, const u32 size, const u32* hashes, const u32 count);


    //-------------------------------------------------------------------
    // TYPE HASHING
    //-------------------------------------------------------------------

    // element hash
    template<typename t> u32  hash32         (const t* type);
    template<typename t> u32  hash32         (const t& type);
    template<typename t> u64  hash64         (const t* type);
    template<typename t> u64  hash64         (const t& type);
    template<typename t> u128 hash128        (const t* type);
    template<typename t> u128 hash128        (const t& type);

    // element search    
    template<typename t> u32  hash32_search  (const t* type, const u32*  hashes, const u32 count);
    template<typename t> u32  hash32_search  (const t& type, const u32*  hashes, const u32 count);
    template<typename t> u64  hash64_search  (const t* type, const u64*  hashes, const u32 count);
    template<typename t> u64  hash64_search  (const t& type, const u64*  hashes, const u32 count);
    template<typename t> u128 hash128_search (const t* type, const u128* hashes, const u32 count);
    template<typename t> u128 hash128_search (const t& type, const u128* hashes, const u32 count);
};

#endif //SLD_COLLECTIONS_HPP