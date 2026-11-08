#include "../interface/I_Cache.hpp"
#include "LFU_Cache.hpp"
#include "LRU_Cache.hpp"
#include <memory>
#include <cstdint>
#pragma once

enum class Cache_Type : uint8_t
{
    LRU,
    LFU
};

class Cache_Factory
{
public:
    Cache_Factory() = default;

    inline static std::unique_ptr<I_Cache> createCache(Cache_Type type, int size)
    {
        std::unique_ptr<I_Cache> ret;

        switch (type)
        {
        case Cache_Type::LRU:
            ret = std::make_unique<LRU_Cache>(size);

        case Cache_Type::LFU:
            ret = std::make_unique<LFU_Cache>(size);

        default:
            ret = nullptr;
        }

        return ret;
    }
};