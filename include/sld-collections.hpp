#ifndef SLD_COLLECTIONS_HPP
#define SLD_COLLECTIONS_HPP

#include <Windows.h>
#include <cstdint>
#include <assert.h>

#ifdef SLD_COLLECTIONS_DLL
#   define SLD_COLLECTIONS_API __declspec(dllexport)
#else
#   define SLD_COLLECTIONS_API __declspec(dllimport)
#endif

#ifndef    SLD_COLLECTIONS_DEFAULT_HASH
#   define SLD_COLLECTIONS_DEFAULT_HASH 32
#endif

#define SLD_TEMPLATE_TYPE      template<typename type>
#define SLD_TEMPLATE_KEY_VALUE template<typename key, typename value>

namespace sld {

    //-------------------------------------------------------------------
    // CONSTANTS
    //-------------------------------------------------------------------

    static constexpr u32 INVALID_INDEX = 0xFFFFFFFF;
    static constexpr u32 MAX_CAPACITY  = 0xFFFFFFFE;
    static constexpr u32 STRIDE_NONE   = 0;

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
    class data_buffer;
    class stack_buffer;
    class queue_buffer;
    
    // list collections
    SLD_TEMPLATE_TYPE class array_list;
    SLD_TEMPLATE_TYPE class stack_list;
    SLD_TEMPLATE_TYPE class queue_list;

    // linked collections
    SLD_TEMPLATE_TYPE class single_linked_list;
    SLD_TEMPLATE_TYPE class single_linked_node;
    SLD_TEMPLATE_TYPE class double_linked_list;
    SLD_TEMPLATE_TYPE class double_linked_node;

    // hash collections
    SLD_TEMPLATE_TYPE      class set_32;
    SLD_TEMPLATE_TYPE      class set_64;
    SLD_TEMPLATE_TYPE      class set_128;
    SLD_TEMPLATE_KEY_VALUE class map_32;
    SLD_TEMPLATE_KEY_VALUE class map_64; 
    SLD_TEMPLATE_KEY_VALUE class map_128;
    SLD_TEMPLATE_KEY_VALUE class sparse_set_32;
    SLD_TEMPLATE_KEY_VALUE class sparse_set_64;
    SLD_TEMPLATE_KEY_VALUE class sparse_set_128;

#if SLD_COLLECTIONS_DEFAULT_HASH == 64
    using set        = set_64;
    using map        = map_64;
    using sparse_set = sparse_set_64;
#elif SLD_COLLECTIONS_DEFAULT_HASH == 128
    using set        = set_128;
    using map        = map_128;
    using sparse_set = sparse_set_128;
#else
    using set        = set_32;
    using map        = map_32;
    using sparse_set = sparse_set_32;
#endif

    //-------------------------------------------------------------------
    // DATA BUFFER
    //-------------------------------------------------------------------
    
    struct buffer {
        byte* data;
        u32   size;
        u32   length;
    };

    // create/destroy methods
    SLD_COLLECTIONS_API buffer* buffer_create             (const u32 buffer_size);
    SLD_COLLECTIONS_API buffer* buffer_memory_init        (vptr mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void    buffer_destroy            (buffer* b);

    // constant methods
    SLD_COLLECTIONS_API bool    buffer_is_valid           (const buffer* b);
    SLD_COLLECTIONS_API bool    buffer_assert_valid       (const buffer* b);
    SLD_COLLECTIONS_API u32     buffer_memory_size        (const u32 buffer_size);
    SLD_COLLECTIONS_API u32     buffer_size_remaining     (const buffer* b);
    SLD_COLLECTIONS_API u32     buffer_append_from_a_to_b (const buffer* ba, const u32   ba_offset,  buffer*       bb);
    SLD_COLLECTIONS_API u32     buffer_copy_to_dst        (const buffer* b,  const u32   b_offset,   const byte*   dst_memory, const u32 dst_size);
    SLD_COLLECTIONS_API u32     buffer_copy_from_a_to_b   (const buffer* ba, const u32   ba_offset,  const buffer* bb,         const u32 bb_offset);

    // mutable methods
    SLD_COLLECTIONS_API void    buffer_reset              (buffer* b);
    SLD_COLLECTIONS_API u32     buffer_append_from_src    (buffer* b, const byte* src_memory, const u32   src_size);
    SLD_COLLECTIONS_API u32     buffer_copy_from_src      (buffer* b, const u32   b_offset,   const byte* src_memory, const u32 src_size);

    //-------------------------------------------------------------------
    // STACK BUFFER
    //-------------------------------------------------------------------

    struct stack_buffer {
        byte* data;
        u32   size;
        u32   ptr;        
    };

    // create/destroy methods
    SLD_COLLECTIONS_API stack_buffer* stack_buffer_create         (const u32 size);
    SLD_COLLECTIONS_API stack_buffer* stack_buffer_memory_init    (vptr mem_ptr, const u32 mem_size);
    SLD_COLLECTIONS_API void          stack_buffer_destroy        (stack_buffer* sb);    

    // constant methods
    SLD_COLLECTIONS_API u32           stack_buffer_memory_size    (const u32 size);
    SLD_COLLECTIONS_API bool          stack_buffer_is_valid       (const stack_buffer* sb);
    SLD_COLLECTIONS_API void          stack_buffer_assert_valid   (const stack_buffer* sb);
    SLD_COLLECTIONS_API u32           stack_buffer_size_remaining (const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*   stack_buffer_head           (const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*   stack_buffer_tail           (const stack_buffer* sb);
    SLD_COLLECTIONS_API const byte*   stack_buffer_peek           (const stack_buffer* sb, const u32 size);

    // mutable methods
    SLD_COLLECTIONS_API void          stack_buffer_reset          (stack_buffer* sb);
    SLD_COLLECTIONS_API u32           stack_buffer_push_data      (stack_buffer* sb, const u32 size, const byte* data);
    SLD_COLLECTIONS_API byte*         stack_buffer_pull_data      (stack_buffer* sb, const u32 size);

    //-------------------------------------------------------------------
    // QUEUE BUFFER
    //-------------------------------------------------------------------

    struct queue_buffer {
        byte* data;
        u32   size;
        u32   head;
        u32   tail;
    };

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
    class array_list {
        
    private:
    
        // properties
        type* _elements;
        u32   _capacity;
        u32   _count;
        b64   _internal;

    public:

        // static methods
        static u32 memory_size (const u32 capacity);

        // constructors
        array_list (const u32 capacity);
        array_list (const u32 capacity, type* elements);
        array_list (const u32 mem_size, vptr  mem_ptr);

        // destructors
        ~array_list();

        // constant methods
        u32 size_total        (void)                                                           const;
        u32 size_free         (void)                                                           const;
        u32 size_used         (void)                                                           const;
        u32 index_of          (const t* element)                                               const;
        u32 to_buffer         (buffer*           to, const u32 index = 0, const u32 count = 0) const;
        u32 to_buffer         (buffer&           to, const u32 index = 0, const u32 count = 0) const;
        u32 to_sub_array_list (array_list<type>* to, const u32 index = 0, const u32 count = 0) const;
        u32 to_sub_array_list (array_list<type>& to, const u32 index = 0, const u32 count = 0) const;

        // mutable methods
        void reset            (void);
        void reverse          (void);
        u32  remove           (const type* element);
        u32  remove_at        (const u32   index,    const u32 index = 0);
        u32  push_back        (const type* elements, const u32 count = 1);
        u32  push_front       (const type* elements, const u32 count = 1);
        void insert_at        (const type* elements, const u32 index, const u32 count = 1);

        // inline methods
        inline const u32 capacity (void) { return(this->_capacity); }
        inline const u32 count    (void) { return(this->_count);    }
        inline const u32 internal (void) { return(this->_internal); }        
        
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
    class stack_list {

    private:
        
        // properties
        type* _elements;
        u32   _capacity;
        u32   _count;
        b64   _internal;

    public:

        // static methods
        static u32 memory_size (const u32 capacity);

        // constructors
        stack_list (const u32 capacity);        
        stack_list (const u32 capacity, type* elements);        
        stack_list (const u32 mem_size, vptr  mem_ptr);        

        // destructors
        ~stack_list();

        // constant methods        
        bool          is_valid       (void)                const;
        void          assert_valid   (void)                const;
        const type*   peek           (const u32 count)     const;
        const type&   peek           (const u32 count)     const;
        const type*   head           (void)                const;
        const type&   head           (void)                const;
        const type*   tail           (void)                const;
        const type&   tail           (void)                const;
        u32           size_total     (void)                const;
        u32           size_used      (void)                const;
        u32           size_free      (void)                const;
        void          to_data_buffer (data_buffer* buffer) const;
        void          to_data_buffer (data_buffer& buffer) const;

        // mutable methods
        void          reset        (void);
        type*         pull         (const u32 count);
        bool          pull         (type& element);
        u32           push         (const u32 count, const type* elements);
        bool          push         (const type& element);

        // inline methods
        inline u32 capacity (void) { return(this->capacity); }
        inline u32 count    (void) { return(this->count);    }
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
    class double_linked_list {

    public:
        struct node : type {
            double_linked_list<type>* list;
            node*                     next;
            node*                     prev;
        };
        
    private:

        // properties
        node* _first;        
        node* _last;

    public:

        static u32 list_size();    
        static u32 node_size();    

        double_linked_list();
        ~double_linked_list();

        node* first ();
        node* last  ();

        node* create_node (const u32 count = 1);
        bool  delete_node (node* n, const u32 count = 1);

        insert_first  (node* n);
        insert_last   (node* n);
        insert_before (node* n);
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
    // MEMORY UTILITIES
    //-------------------------------------------------------------------

    inline void zero_memory(const u32 size, vptr memory) { memset(vptr, 0, size); }

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