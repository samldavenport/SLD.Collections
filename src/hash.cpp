#pragma once

#include <meow_hash_x64_aesni.h>

#include "sld-collections.hpp"

namespace sld {

    SLD_COLLECTIONS_API u32
    hash_32(
        const void* data,
        const u32   size) {

        assert(data != NULL && size != 0);

        u128 hash;
        hash.simd_reg = MeowHash(MeowDefaultSeed, size, data);

        return(hash.u32_0);
    }

    SLD_COLLECTIONS_API u64
    hash_64(
        const void* data,
        const u32   size) {

        assert(data != NULL && size != 0);

        u128 hash;
        hash.simd_reg = MeowHash(MeowDefaultSeed, size, data);
        
        return(hash.u64_lo);
    }

    SLD_COLLECTIONS_API u128
    hash_128(
        const void* data,
        const u32   size) {

        assert(data != NULL && size != 0);

        u128 hash;
        hash.simd_reg = MeowHash(MeowDefaultSeed, size, data);

        return(hash);
    }

    SLD_COLLECTIONS_API u32
    hash_32_search(
        const void* data,
        const u32   size,
        const u32*  hash,
        const u32   count) {

        assert(data != NULL && size != 0);

        u32 result = INVALID_INDEX;

        u128 hash;
        hash.simd_reg = MeowHash(MeowDefaultSeed, size, data);

        for (
            u32 index = 0;
                index < count;
              ++index) {

            if (hash.u32_0 == hash[index].u32_0) {
                result = index;
                break;
            }
        }

        return(result);
    }
    
    SLD_COLLECTIONS_API u32
    hash_64_search(
        const void* data,
        const u32   size,
        const u64*  hash,
        const u32   count) {

        assert(data != NULL && size != 0);

        u32 result = INVALID_INDEX;

        u128 hash;
        hash.simd_reg = MeowHash(MeowDefaultSeed, size, data);

        for (
            u32 index = 0;
                index < count;
              ++index) {

            if (hash.u64_lo == hash[index].u64_lo) {
                result = index;
                break;
            }
        }

        return(result);
    }
    
    SLD_COLLECTIONS_API u32
    hash_128_search(
        const void* data,
        const u32   size,
        const u128* hash,
        const u32   count) {

        assert(data != NULL && size != 0);

        u32 result = INVALID_INDEX;

        u128 hash;
        hash.simd_reg = MeowHash(MeowDefaultSeed, size, data);

        for (
            u32 index = 0;
                index < count;
              ++index) {

            if (
                hash.u64_lo == hash[index].u64_lo &&
                hash.u64_hi == hash[index].u64_hi) {
                
                result = index;
                break;
            }
        }

        return(result);
    }
    
};