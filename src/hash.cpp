#pragma once

#include "sld-collections.hpp"

namespace sld {

    SLD_COLLECTIONS_API u32             hash_32                          (const void* data, const u32 size);
    SLD_COLLECTIONS_API u64             hash_64                          (const void* data, const u32 size);
    SLD_COLLECTIONS_API u128            hash_128                         (const void* data, const u32 size);
    SLD_COLLECTIONS_API u32             h32_search                       (const void* data, const u32 size, const u32* hash, const u32 count = 1);
    SLD_COLLECTIONS_API u32             h64_search                       (const void* data, const u32 size, const u32* hash, const u32 count = 1);
    SLD_COLLECTIONS_API u32             hash128_search                   (const void* data, const u32 size, const u32* hash, const u32 count = 1);
};