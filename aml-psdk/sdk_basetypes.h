#ifndef __AML_PSDK_BASETYPES_H
#define __AML_PSDK_BASETYPES_H

#define SQ(_v) (_v * _v)
#define CLASS_OFFSET(_cls, _var) (intptr_t)(&(((_cls*)(NULL))->_var))
#define VA_ARGS(...) , ##__VA_ARGS__

template<typename A1>
A1 std_min(A1 val, A1 minval)
{
    if(val < minval) return minval;
    return val;
}

template<typename A1>
A1 std_max(A1 val, A1 maxval)
{
    if(val > maxval) return maxval;
    return val;
}

template<typename A1>
A1 std_minmax(A1 val, A1 minval, A1 maxval)
{
    if(val < minval) return minval;
    if(val > maxval) return maxval;
    return val;
}

struct SimpleVTable
{
    virtual void BaseDestructor();
    virtual void MyDestructor();

    inline void* ptr() { return (void*)this; }
    inline uintptr_t addr() { return (uintptr_t)this; }
    inline uintptr_t& vtable() { return *(uintptr_t*)this; }
    inline void setvtable(uintptr_t addr) { *(uintptr_t*)this = addr; }

    inline operator uintptr_t() const { return (uintptr_t)this; }
};

typedef int8_t i8;
typedef uint8_t u8;
typedef uint8_t b8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef intptr_t iptr;
typedef uintptr_t uptr;
typedef uintptr_t FILESTREAM;

#ifdef AML64
    #define CHECKSIZE(_cls, _s32, _s64) static_assert(sizeof(_cls)==_s64, "Validating size of " #_cls " is failed! " #_cls "'s size is not " #_s64)
    #define SELBYBIT(__32val, __64val) __64val
    #define B64MACRO(...) __VA_ARGS__
    #define B32MACRO(...)
    #define ALIGN_8_4 8
#else
    #define CHECKSIZE(_cls, _s32, _s64) static_assert(sizeof(_cls)==_s32, "Validating size of " #_cls " is failed! " #_cls "'s size is not " #_s32)
    #define SELBYBIT(__32val, __64val) __32val
    #define B32MACRO(...) __VA_ARGS__
    #define B64MACRO(...)
    #define ALIGN_8_4 4
#endif
    
// Class

#define DECL_CLASS(_clsName, ...) \
    struct __VA_ARGS__ _clsName { \
        typedef _clsName ThisClass; \
        typedef _clsName BaseClass;

#define DECL_CLASS_VTABLE(_clsName, ...) \
    struct __VA_ARGS__ _clsName : SimpleVTable { \
        typedef _clsName ThisClass; \
        typedef _clsName BaseClass;

#define DECL_CLASS_BASED(_clsName, _clsBaseName, ...) \
    struct __VA_ARGS__ _clsName : _clsBaseName { \
        typedef _clsName ThisClass; \
        typedef _clsBaseName BaseClass;

#define DECL_CLASS_END() \
    };

#endif // __AML_PSDK_BASETYPES_H