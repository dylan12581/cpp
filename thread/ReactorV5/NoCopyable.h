#ifndef _NOCOPYABLE_H_
#define _NOCOPYABLE_H_

class NoCopyable
{
public:
    NoCopyable() {}
    ~NoCopyable() {}

private:
    NoCopyable(const NoCopyable&) = delete;
    NoCopyable& operator=(const NoCopyable&) = delete;

};

#endif
