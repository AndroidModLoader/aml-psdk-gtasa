#ifndef __AML_PSDK_GTAGXTCHAR_H
#define __AML_PSDK_GTAGXTCHAR_H

union GxtChar
{
    struct { char s1, s2; };
    unsigned short s;
};

inline unsigned short* AsUINT(GxtChar* self) { return (unsigned short*)self; }
inline void AsciiToGxtChar(const char* src, GxtChar* dst)
{
    int i = 0;
    while(src[i])
    {
        dst[i].s = src[i];
        ++i;
    }
    dst[i].s = 0;
    dst[i+1].s = 0;
}
inline void AsciiToGxtChar(const char* src, unsigned short* dst)
{
    AsciiToGxtChar(src, (GxtChar*)dst);
}

#endif // __AML_PSDK_GTAGXTCHAR_H