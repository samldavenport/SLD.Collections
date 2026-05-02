#include "sld-collections.hpp"

namespace sld {


        buffer::buffer (const u32 size);
        buffer::buffer (const u32 size, byte* memory);

        void
        buffer::clear(
            void){

            memset(
                this->_data,
                0,
                this->_size
            );
        }

        u32
        buffer::append(
            const buffer* src) {

        }

        u32
        buffer::append(
            const byte* src_data,
            const u32   src_length) {

        }
        
        u32
        buffer::copy_to(
            const buffer* dst) const {

        }
        
        u32
        buffer::copy_to(
            const byte* dst_data,
            const u32   dst_size) const {

        }

        byte&       buffer::operator[] (u32 index);
        const byte& buffer::operator[] (u32 index) const;


};