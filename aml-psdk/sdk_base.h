#ifndef __AML_PSDK_BASE_H
#define __AML_PSDK_BASE_H

#define BASE_GAME_LIBRARY "libGTASA.so"

#include <mod/amlmod.h>
#include <stdint.h>

typedef int8_t i8;
typedef uint8_t u8;
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
            Set( Get() + 1 ); \
            return tVal; \
        } \
        template<class C> \
        _type operator--(int unusedVar) { \
            _type tVal = Get(); \
            Set( Get() - 1 ); \
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
        operator _type() const { return (_type)Get(); }

#define DECL_VALUE_RETURN_BASE_REF(_type) \
        operator _type&() { return (_type&)Get(); } \
        operator _type() const { return (_type)Get(); }

#define DECL_VALUE_TAIL(_type, _name) \
        static inline _type* Ptr() { return &Get(); } \
        static inline _type& Set(const _type& v) { Get() = v; return Get(); } \
    }; static inline ValueProxy_##_name _name

#define DECL_VALUE_TAIL_GLOBAL(_type, _name) \
        static inline _type* Ptr() { return &Get(); } \
        static inline _type& Set(const _type& v) { Get() = v; return Get(); } \
    }; inline ValueProxy_##_name _name


#define DECL_VALUE_PLT_I32(_name, _addr) \
    DECL_VALUE_HEAD(i32, _name) \
        DECL_VALUE_PLT_BASE(i32, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(i32) \
        DECL_VALUE_BITOPS_BASE(i32) \
    DECL_VALUE_TAIL(i32, _name)

#define DECL_VALUE_PLT_BOOL(_name, _addr) \
    DECL_VALUE_HEAD(bool, _name) \
        DECL_VALUE_PLT_BASE(bool, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(bool) \
        DECL_VALUE_BITOPS_BASE(bool) \
    DECL_VALUE_TAIL(bool, _name)

#define DECL_VALUE_PLT_U32(_name, _addr) \
    DECL_VALUE_HEAD(u32, _name) \
        DECL_VALUE_PLT_BASE(u32, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(u32) \
        DECL_VALUE_BITOPS_BASE(u32) \
    DECL_VALUE_TAIL(u32, _name)

#define DECL_VALUE_PLT_FLT(_name, _addr) \
    DECL_VALUE_HEAD(float, _name) \
        DECL_VALUE_PLT_BASE(float, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(float) \
        DECL_VALUE_RETURN_BASE(i32) \
        DECL_VALUE_RETURN_BASE(u32) \
    DECL_VALUE_TAIL(float, _name)

#endif // __AML_PSDK_BASE_H