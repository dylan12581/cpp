#pragma once

class NoCopyable
{
public:
    NoCopyable() {}
    ~NoCopyable() {}
    NoCopyable(const NoCopyable& rhs) = delete;
    NoCopyable& operator=(const NoCopyable& rhs) = delete;
};

