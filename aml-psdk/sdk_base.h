#ifndef __AML_PSDK_BASE_H
#define __AML_PSDK_BASE_H

#define BASE_GAME_LIBRARY "libGTASA.so"

#include <mod/amlmod.h>
#include <stdint.h>

#define SQ(_v) (_v * _v)
#define CLASS_OFFSET(_cls, _var) (intptr_t)(&(((_cls*)(NULL))->_var))
#define VA_ARGS(...) , ##__VA_ARGS__

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

inline void* g_hMainGameLibrary = NULL;
inline uptr g_pMainGameAddress = 0;

inline void* GetMainLibrary()
{
    if(!g_hMainGameLibrary)
    {
        g_hMainGameLibrary = aml->GetLibHandle(BASE_GAME_LIBRARY);
    }
    return g_hMainGameLibrary;
}

inline uptr GetMainLibraryAddress()
{
    if(!g_pMainGameAddress)
    {
        g_pMainGameAddress = aml->GetLib(BASE_GAME_LIBRARY);
    }
    return g_pMainGameAddress;
}

template<typename Type>
inline Type GetMainLibrarySymbol(const char* sym)
{
    return (Type)aml->GetSym(GetMainLibrary(), sym);
}

#define DECL_VALUE_HEAD(_type, _name) \
    struct ValueProxy_##_name { \
        static inline _type* m_Pointer = NULL;

#define DECL_VALUE_SYM_BASE(_type, _name, _sym) \
        static inline _type& Get() { \
            if(!m_Pointer) m_Pointer = GetMainLibrarySymbol<_type*>(_sym); \
            return *m_Pointer; \
        }

#define DECL_VALUE_PLT_BASE(_type, _name, _addr) \
        static inline _type& Get() { \
            if(!m_Pointer) m_Pointer = *(_type**)(GetMainLibraryAddress() + _addr); \
            return *m_Pointer; \
        }

#define DECL_VALUE_NUMBER_BASE(_type) \
        template<class C> \
        const _type& operator=(const C& v) { return Set( (const _type)v ); } \
        template<class C> \
        const _type& operator+=(const C& v) { return Set( Get() + (const _type)v ); } \
        template<class C> \
        const _type& operator-=(const C& v) { return Set( Get() - (const _type)v ); } \
        template<class C> \
        const _type& operator/=(const C& v) { return Set( Get() / (const _type)v ); } \
        template<class C> \
        const _type& operator*=(const C& v) { return Set( Get() * (const _type)v ); } \
        template<class C> \
        const _type& operator++(const C& v) { return Set( Get() + (const _type)1 ); } \
        template<class C> \
        const _type& operator--(const C& v) { return Set( Get() - (const _type)1 ); } \
        const bool operator!() { return (Get() != (const _type)0); } \
        template<class C> \
        _type operator++(int unusedVar) { \
            _type tVal = Get(); \
            Set( Get() + (const _type)1 ); \
            return tVal; \
        } \
        template<class C> \
        _type operator--(int unusedVar) { \
            _type tVal = Get(); \
            Set( Get() - (const _type)1 ); \
            return tVal; \
        }

#define DECL_VALUE_BITOPS_BASE(_type) \
        template<class C> \
        const _type& operator^=(const C& v) { return Set( Get() ^ (const _type)v ); } \
        template<class C> \
        const _type& operator|=(const C& v) { return Set( Get() | (const _type)v ); } \
        template<class C> \
        const _type& operator&=(const C& v) { return Set( Get() & (const _type)v ); }

#define DECL_VALUE_RETURN_BASE(_type) \
        operator _type() { return (_type)Get(); }

#define DECL_VALUE_RETURN_BASE_REF(_type) \
        operator _type&() { return (_type&)Get(); } \
        operator _type() { return (_type)Get(); }

#define DECL_VALUE_TAIL(_type, _name) \
        static inline _type* Ptr() { return &Get(); } \
        static inline _type& Set(const _type& v) { Get() = v; return Get(); } \
    }; static inline ValueProxy_##_name _name

#define DECL_VALUE_TAIL_GLOBAL(_type, _name) \
        static inline _type* Ptr() { return &Get(); } \
        static inline _type& Set(const _type& v) { Get() = v; return Get(); } \
    }; inline ValueProxy_##_name _name

// Values

#define DECL_VALUE_PLT_I32(_name, _addr) \
    DECL_VALUE_HEAD(i32, _name) \
        DECL_VALUE_PLT_BASE(i32, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(i32) \
        DECL_VALUE_BITOPS_BASE(i32) \
        DECL_VALUE_RETURN_BASE(int) \
    DECL_VALUE_TAIL(i32, _name)

#define DECL_VALUE_PLT_BOOL(_name, _addr) \
    DECL_VALUE_HEAD(bool, _name) \
        DECL_VALUE_PLT_BASE(bool, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(bool) \
        DECL_VALUE_BITOPS_BASE(bool) \
        DECL_VALUE_RETURN_BASE(int) \
    DECL_VALUE_TAIL(bool, _name)

#define DECL_VALUE_PLT_U32(_name, _addr) \
    DECL_VALUE_HEAD(u32, _name) \
        DECL_VALUE_PLT_BASE(u32, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(u32) \
        DECL_VALUE_BITOPS_BASE(u32) \
        DECL_VALUE_RETURN_BASE(unsigned int) \
    DECL_VALUE_TAIL(u32, _name)

#define DECL_VALUE_PLT_FLT(_name, _addr) \
    DECL_VALUE_HEAD(float, _name) \
        DECL_VALUE_PLT_BASE(float, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(float) \
        DECL_VALUE_RETURN_BASE(float) \
        DECL_VALUE_RETURN_BASE(int) \
    DECL_VALUE_TAIL(float, _name)
    
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
// Class functions

#define DECL_CTORCALL_ARG_HEAD(_clsName, _sym, ...) \
    static inline auto FuncProxy_ctor##_clsName = GetMainLibrarySymbol<void(*)(ThisClass* VA_ARGS(__VA_ARGS__))>(#_sym); \
    _clsName(__VA_ARGS__) { FuncProxy_ctor##_clsName(

#define DECL_CTORCALL_ARG_TAIL(...) \
    this VA_ARGS(__VA_ARGS__)); }

#define DECL_CTORCALL(_clsName, _sym) \
    DECL_CTORCALL_ARG_HEAD(_clsName, _sym) \
    DECL_CTORCALL_ARG_TAIL()

#define DECL_DTORCALL(_clsName, _sym) \
    static inline auto FuncProxy_dtor##_clsName = GetMainLibrarySymbol<void(*)(ThisClass*)>(#_sym); \
    ~_clsName() { FuncProxy_dtor##_clsName(this); }

#define DECL_THISCALL_HEAD(_name, _sym, _ret, ...) \
    static inline auto FuncProxy_##_name = GetMainLibrarySymbol<_ret(*)(ThisClass* VA_ARGS(__VA_ARGS__))>(#_sym); \
    inline _ret _name(__VA_ARGS__) {

#define DECL_THISCALL_NAMED_HEAD(_name, _alias, _sym, _ret, ...) \
    static inline auto FuncProxy_##_name = GetMainLibrarySymbol<_ret(*)(ThisClass* VA_ARGS(__VA_ARGS__))>(#_sym); \
    inline _ret _alias(__VA_ARGS__) {

#define DECL_THISCALL_ADDR_HEAD(_name, _addr, _ret, ...) \
    static inline auto FuncProxy_##_name = (_ret(*)(ThisClass* VA_ARGS(__VA_ARGS__)))(GetMainLibraryAddress() + _addr); \
    inline _ret _name(__VA_ARGS__) {

#define DECL_THISCALL_ADDR_NAMED_HEAD(_name, _alias, _addr, _ret, ...) \
    static inline auto FuncProxy_##_name = (_ret(*)(ThisClass* VA_ARGS(__VA_ARGS__)))(GetMainLibraryAddress() + _addr); \
    inline _ret _alias(__VA_ARGS__) {

#define DECL_THISCALL_TAIL(_name, ...) \
        return FuncProxy_##_name(this VA_ARGS(__VA_ARGS__)); \
    }

#define DECL_THISCALL_SIMPLE(_name, _sym, _ret) \
    DECL_THISCALL_HEAD(_name, _sym, _ret) \
    DECL_THISCALL_TAIL(_name)

#define DECL_FASTCALL_SIMPLE(_name, _sym, _ret, ...) \
    static inline auto _name = GetMainLibrarySymbol<_ret(*)(__VA_ARGS__)>(#_sym)

#define DECL_FASTCALL_SIMPLE_GLO(_name, _sym, _ret, ...) \
    inline auto _name = GetMainLibrarySymbol<_ret(*)(__VA_ARGS__)>(#_sym)

#ifdef AML64
    #define CHECKSIZE(_cls, _s32, _s64) static_assert(sizeof(_cls)==_s64, "Validating size of " #_cls " is failed! " #_cls "'s size is not " #_s64)
    #define B64MACRO(...) __VA_ARGS__
    #define B32MACRO(...)
    #define ALIGN_8_4 8
#else
    #define CHECKSIZE(_cls, _s32, _s64) static_assert(sizeof(_cls)==_s32, "Validating size of " #_cls " is failed! " #_cls "'s size is not " #_s32)
    #define B32MACRO(...) __VA_ARGS__
    #define B64MACRO(...)
    #define ALIGN_8_4 4
#endif

#endif // __AML_PSDK_BASE_H