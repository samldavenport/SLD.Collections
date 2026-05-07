
    struct sparse_set_64 {
        struct  {
            element* sparse_elements;
            index*   dense_indexes;
            h64*     dense_hashes;
        } array;
        struct {
            u32 element;
            u32 key;
        } size;
        u32      capacity;
        u32      count;
        f32      percentage_max;
    };