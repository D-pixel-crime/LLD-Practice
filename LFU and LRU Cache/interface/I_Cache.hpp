#include <optional>
#pragma once

class I_Cache
{
public:
    I_Cache() = default;
    virtual ~I_Cache() = default;

    virtual void insert(int, int) = 0;
    virtual std::optional<int> get(int) = 0;
};