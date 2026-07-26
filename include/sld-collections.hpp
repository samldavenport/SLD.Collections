#ifndef SLD_COLLECTIONS_HPP
#define SLD_COLLECTIONS_HPP

#include "sld.hpp"

#ifdef SLD_COLLECTIONS_DLL
#   define SLD_COLLECTIONS_API __declspec(dllexport)
#else
#   define SLD_COLLECTIONS_API __declspec(dllimport)
#endif

#define SLD_COLLECTIONS_UTILITY  inline
#define SLD_COLLECTIONS_CONSTANT 

namespace sld {

    //--------------------------------------------------------------------
    // CONSTANTS
    //--------------------------------------------------------------------

    static constexpr u32 INVALID_INDEX = 0xFFFFFFFF;
    static constexpr u32 MAX_CAPACITY  = 0xFFFFFFFE;

    //--------------------------------------------------------------------
    // COLLECTIONS
    //--------------------------------------------------------------------

    class buffer;
    class stack;
    class queue;
    template<typename t> class array_list;
    template<typename t> class stack_list;
    template<typename t> class queue_list;

    //--------------------------------------------------------------------
    // BUFFER
    //--------------------------------------------------------------------

    class SLD_COLLECTIONS_API buffer {
        
    private:

        byte* _data;
        u32   _size;
        u32   _length;

    public:

        void        init            (void* mem_ptr, const u32 mem_size);
        void        reset           (buffer* b);
        void        assert_valid    (void) const;
        const byte* data            (void) const;
    };

    //--------------------------------------------------------------------
    // STACK
    //--------------------------------------------------------------------

    class stack {
        
    private:

        byte* _data;
        u32   _size;
        u32   _position;
    
    public:
       
        void        init      (void* mem_ptr, const u32 mem_size);
        void        reset     (void);
        u32         push_data (const u32 size, const byte* data);
        byte*       pull_data (const u32 size);
        const byte* head      (void)           const;
        const byte* tail      (void)           const;
        const byte* peek      (const u32 size) const;
        const u32   size_total(void);
        const u32   size_free (void);
        const u32   size_used (void);

        template<typename t> t* push_struct(u32 count = 1);
        template<typename t> t* pull_struct(u32 count = 1);
    };
    //--------------------------------------------------------------------
    // QUEUE BUFFER
    //--------------------------------------------------------------------

    struct queue {
    
    private:
    
        byte* _data;
        u32   _size;
        u32   _head;
        u32   _tail;
        
    public:

        void        assert_valid (void);
        byte*       data         (void);
        u32         size_total   (void);
        u32         size_free    (void);
        u32         size_used    (void);
        const byte* head         (void);
        const byte* tail         (void);
        const byte* peek         (void);
        void        reset        (void);
        u32         push_data    (const u32 size, const byte* data);
        byte*       pop_data     (const u32 size);
    };



    //--------------------------------------------------------------------
    // ARRAY LIST
    //--------------------------------------------------------------------

    template<typename t>
    class SLD_COLLECTIONS_API array_list {
    
    private:
        
        t*  _elmnt;
        u32 _capacity;
        u32 _count;

    public:

        void init      (t* elmnts, const u32 capacity);
        void validate  (void)                        const;
        u32  capacity  (void)                        const;
        u32  count     (void)                        const;
        bool is_full   (void)                        const;
        bool index_of  (const t& elmnt, u32& index)  const;
        bool contains  (const t& elmnt)              const;
        void reset     (void);
        t&   get       (const u32 index);
        bool add       (const t&  elmnt);
        void remove    (const t&  elmnt);
        void remove_at (const u32 index);

        inline t& operator[] (const u32 index) {
            assert(index < _count);
            return(_elmnt[index]);
        }
    };

    //--------------------------------------------------------------------
    // STACK LIST
    //--------------------------------------------------------------------

    template<typename t>
    class SLD_COLLECTIONS_API stack_list{
    
    private:
        
        t*  _elmnt;
        u32 _capacity;
        u32 _position;

    public:

        void      init         (t* elmnt, const u32 count);
        void      reset        (void);
        u32       push         (const t& elmnt);
        t&        pull         (void);
        void      assert_valid (void)            const;
        const u32 stride       (void)            const;
        const u32 capacity     (void)            const;
        const u32 count        (void)            const;
        u32       size_total   (void)            const;
        u32       size_used    (void)            const;
        u32       size_free    (void)            const;
        const t&  head         (void)            const;
        const t&  tail         (void)            const;
        const t&  peek         (const u32 count) const;
    };

    //--------------------------------------------------------------------
    // QUEUE LIST
    //--------------------------------------------------------------------

    template<typename t>
    class SLD_COLLECTIONS_API queue_list {
    
    private:
        
        t*  _elmnt;
        u32 _capacity;
        u32 _head;
        u32 _tail;

    public:

        void      init         (t* elmnt, const u32 count);
        void      reset        (void);
        u32       enqueue      (const t& elmnt);
        element*  dequeue      (void);
        const u32 stride       (void)            const;
        void      assert_valid (void)            const;
        const u32 stride       (void)            const;
        const u32 capacity     (void)            const;
        const u32 count        (void)            const;
        u32       size_total   (void)            const;
        u32       size_used    (void)            const;
        u32       size_free    (void)            const;
        const t&  head         (void)            const;
        const t&  tail         (void)            const;
        const t&  peek         (const u32 count) const;
    };
};

#endif //SLD_COLLECTIONS_HPP
