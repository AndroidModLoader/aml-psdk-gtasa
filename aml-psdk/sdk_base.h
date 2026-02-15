#ifndef __AML_PSDK_BASE_H
#define __AML_PSDK_BASE_H

#ifndef BASE_GAME_LIBRARY
    #error Please include <aml-psdk/game_*/plugin.h>!
    #define BASE_GAME_LIBRARY "" // Suppress an error
#endif

#include <mod/amlmod.h>
#include <stdint.h>
#include <math.h>

#include "sdk_basetypes.h"

inline void* g_hMainGameLibrary = NULL;
inline uptr g_pMainGameAddress = 0;

inline void* GetMainLibrary()
{
    if(!g_hMainGameLibrary)
    {
        g_hMainGameLibrary = aml->GetLibHandle( BASE_GAME_LIBRARY );
    }
    return g_hMainGameLibrary;
}

inline uptr GetMainLibraryAddress()
{
    if(!g_pMainGameAddress)
    {
        g_pMainGameAddress = aml->GetLib( BASE_GAME_LIBRARY );
    }
    return g_pMainGameAddress;
}

template<typename Type = void*>
inline Type GetMainLibrarySymbol(const char* sym)
{
    return (Type)aml->GetSym(GetMainLibrary(), sym);
}

#define DECL_VALUE_HEAD(_type, _name) \
    struct ValueProxy_##_name { \
        static inline _type* m_Pointer = NULL;

#define DECL_VALUE_SYM_BASE(_type, _name, _sym) \
        _type& operator()() { return Get(); } \
        static inline _type& Get() { \
            if(!m_Pointer) m_Pointer = GetMainLibrarySymbol<_type*>(_sym); \
            return *m_Pointer; \
        }

#define DECL_VALUE_PLT_BASE(_type, _name, _addr) \
        _type& operator()() { return Get(); } \
        static inline _type& Get() { \
            if(!m_Pointer) m_Pointer = *(_type**)(GetMainLibraryAddress() + _addr); \
            return *m_Pointer; \
        }

#define DECL_VALUE_PLTPTR_BASE(_type, _name, _addr) \
        _type& operator()() { return Get(); } \
        static inline _type& Get() { \
            if(!m_Pointer) m_Pointer = (_type*)(GetMainLibraryAddress() + _addr); \
            return *m_Pointer; \
        }

#define DECL_VALUE_NUMBER_BASE(_type) \
        DECL_VALUE_SETTER_BASE(_type) \
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

#define DECL_VALUE_SETTER_BASE(_type) \
        static inline _type& Set(const _type& v) { Get() = v; return Get(); } \

#define DECL_VALUE_GETTER_BASE(_type) \
        static inline _type* Ptr() { return &Get(); } \

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
        DECL_VALUE_GETTER_BASE(_type) \
    }; static inline ValueProxy_##_name _name

#define DECL_VALUE_TAIL_GLOBAL(_type, _name) \
        DECL_VALUE_GETTER_BASE(_type) \
    }; inline ValueProxy_##_name _name

#define DECL_VALUE_OBJECT_BASE(_type) \
        _type* operator->() { return &Get(); }

#define DECL_VALUE_OBJECT_ARRAY_BASE(_type) \
        _type& operator[](int i) { return Get()[i]; }

// Values

#define DECL_VALUE_PLT_I32(_name, _addr) \
    DECL_VALUE_HEAD(i32, _name) \
        DECL_VALUE_PLT_BASE(i32, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(i32) \
        DECL_VALUE_BITOPS_BASE(i32) \
        DECL_VALUE_RETURN_BASE(int) \
    DECL_VALUE_TAIL(i32, _name)

#define DECL_VALUE_PLT_I32_GLOBAL(_name, _addr) \
    DECL_VALUE_HEAD(i32, _name) \
        DECL_VALUE_PLT_BASE(i32, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(i32) \
        DECL_VALUE_BITOPS_BASE(i32) \
        DECL_VALUE_RETURN_BASE(int) \
    DECL_VALUE_TAIL_GLOBAL(i32, _name)

#define DECL_VALUE_PLT_BOOL(_name, _addr) \
    DECL_VALUE_HEAD(bool, _name) \
        DECL_VALUE_PLT_BASE(bool, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(bool) \
        DECL_VALUE_BITOPS_BASE(bool) \
        DECL_VALUE_RETURN_BASE(int) \
    DECL_VALUE_TAIL(bool, _name)

#define DECL_VALUE_PLT_BOOL_GLOBAL(_name, _addr) \
    DECL_VALUE_HEAD(bool, _name) \
        DECL_VALUE_PLT_BASE(bool, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(bool) \
        DECL_VALUE_BITOPS_BASE(bool) \
        DECL_VALUE_RETURN_BASE(int) \
    DECL_VALUE_TAIL_GLOBAL(bool, _name)

#define DECL_VALUE_PLT_U32(_name, _addr) \
    DECL_VALUE_HEAD(u32, _name) \
        DECL_VALUE_PLT_BASE(u32, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(u32) \
        DECL_VALUE_BITOPS_BASE(u32) \
        DECL_VALUE_RETURN_BASE(unsigned int) \
    DECL_VALUE_TAIL(u32, _name)

#define DECL_VALUE_PLT_U32_GLOBAL(_name, _addr) \
    DECL_VALUE_HEAD(u32, _name) \
        DECL_VALUE_PLT_BASE(u32, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(u32) \
        DECL_VALUE_BITOPS_BASE(u32) \
        DECL_VALUE_RETURN_BASE(unsigned int) \
    DECL_VALUE_TAIL_GLOBAL(u32, _name)

#define DECL_VALUE_PLT_I8(_name, _addr) \
    DECL_VALUE_HEAD(i8, _name) \
        DECL_VALUE_PLT_BASE(i8, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(i8) \
        DECL_VALUE_BITOPS_BASE(i8) \
        DECL_VALUE_RETURN_BASE(char) \
        DECL_VALUE_RETURN_BASE(int) \
    DECL_VALUE_TAIL(i8, _name)

#define DECL_VALUE_PLT_I16(_name, _addr) \
    DECL_VALUE_HEAD(i16, _name) \
        DECL_VALUE_PLT_BASE(i16, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(i16) \
        DECL_VALUE_BITOPS_BASE(i16) \
        DECL_VALUE_RETURN_BASE(short) \
        DECL_VALUE_RETURN_BASE(int) \
    DECL_VALUE_TAIL(i16, _name)

#define DECL_VALUE_PLT_U16(_name, _addr) \
    DECL_VALUE_HEAD(u16, _name) \
        DECL_VALUE_PLT_BASE(u16, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(u16) \
        DECL_VALUE_BITOPS_BASE(u16) \
        DECL_VALUE_RETURN_BASE(unsigned short) \
        DECL_VALUE_RETURN_BASE(unsigned int) \
    DECL_VALUE_TAIL(u16, _name)

#define DECL_VALUE_PLT_I8_GLOBAL(_name, _addr) \
    DECL_VALUE_HEAD(i8, _name) \
        DECL_VALUE_PLT_BASE(i8, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(i8) \
        DECL_VALUE_BITOPS_BASE(i8) \
        DECL_VALUE_RETURN_BASE(char) \
        DECL_VALUE_RETURN_BASE(int) \
    DECL_VALUE_TAIL_GLOBAL(i8, _name)

#define DECL_VALUE_PLT_U8(_name, _addr) \
    DECL_VALUE_HEAD(u8, _name) \
        DECL_VALUE_PLT_BASE(u8, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(u8) \
        DECL_VALUE_BITOPS_BASE(u8) \
        DECL_VALUE_RETURN_BASE(unsigned char) \
        DECL_VALUE_RETURN_BASE(unsigned int) \
    DECL_VALUE_TAIL(u8, _name)

#define DECL_VALUE_PLT_U8_GLOBAL(_name, _addr) \
    DECL_VALUE_HEAD(u8, _name) \
        DECL_VALUE_PLT_BASE(u8, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(u8) \
        DECL_VALUE_BITOPS_BASE(u8) \
        DECL_VALUE_RETURN_BASE(unsigned char) \
        DECL_VALUE_RETURN_BASE(unsigned int) \
    DECL_VALUE_TAIL_GLOBAL(u8, _name)

#define DECL_VALUE_PLT_FLT(_name, _addr) \
    DECL_VALUE_HEAD(float, _name) \
        DECL_VALUE_PLT_BASE(float, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(float) \
        DECL_VALUE_RETURN_BASE(float) \
        DECL_VALUE_RETURN_BASE(int) \
    DECL_VALUE_TAIL(float, _name)

#define DECL_VALUE_PLT_FLT_GLOBAL(_name, _addr) \
    DECL_VALUE_HEAD(float, _name) \
        DECL_VALUE_PLT_BASE(float, _name, _addr) \
        DECL_VALUE_NUMBER_BASE(float) \
        DECL_VALUE_RETURN_BASE(float) \
        DECL_VALUE_RETURN_BASE(int) \
    DECL_VALUE_TAIL_GLOBAL(float, _name)

#define DECL_VALUE_PLT_CHAR(_name, _addr) \
    DECL_VALUE_HEAD(char*, _name) \
        DECL_VALUE_PLT_BASE(char*, _name, _addr) \
        DECL_VALUE_RETURN_BASE(char*) \
        DECL_VALUE_RETURN_BASE(const char*) \
        DECL_VALUE_RETURN_BASE(uintptr_t) \
    DECL_VALUE_TAIL(char*, _name)

#define DECL_VALUE_PLT_CHAR_GLOBAL(_name, _addr) \
    DECL_VALUE_HEAD(char*, _name) \
        DECL_VALUE_PLT_BASE(char*, _name, _addr) \
        DECL_VALUE_RETURN_BASE(char*) \
        DECL_VALUE_RETURN_BASE(const char*) \
        DECL_VALUE_RETURN_BASE(uintptr_t) \
    DECL_VALUE_TAIL_GLOBAL(char*, _name)

#define DECL_OBJECT_PLT(_type, _name, _addr) \
    DECL_VALUE_HEAD(_type, _name) \
        DECL_VALUE_PLT_BASE(_type, _name, _addr) \
        DECL_VALUE_OBJECT_BASE(_type) \
        DECL_VALUE_RETURN_BASE(_type&) \
    DECL_VALUE_TAIL(_type, _name)

#define DECL_OBJECT_ARRAY_PLT(_type, _name, _addr) \
    DECL_VALUE_HEAD(_type*, _name) \
        DECL_VALUE_PLTPTR_BASE(_type*, _name, _addr) \
        DECL_VALUE_OBJECT_BASE(_type*) \
        DECL_VALUE_OBJECT_ARRAY_BASE(_type) \
        DECL_VALUE_RETURN_BASE(_type*&) \
    DECL_VALUE_TAIL(_type*, _name)

#define DECL_OBJECT_ARRAY_PLT_GLOBAL(_type, _name, _addr) \
    DECL_VALUE_HEAD(_type*, _name) \
        DECL_VALUE_PLTPTR_BASE(_type*, _name, _addr) \
        DECL_VALUE_OBJECT_BASE(_type*) \
        DECL_VALUE_OBJECT_ARRAY_BASE(_type) \
        DECL_VALUE_RETURN_BASE(_type*&) \
    DECL_VALUE_TAIL_GLOBAL(_type*, _name)

#define DECL_OBJECT_PLT_GLOBAL(_type, _name, _addr) \
    DECL_VALUE_HEAD(_type, _name) \
        DECL_VALUE_PLT_BASE(_type, _name, _addr) \
        DECL_VALUE_OBJECT_BASE(_type) \
        DECL_VALUE_RETURN_BASE(_type&) \
    DECL_VALUE_TAIL_GLOBAL(_type, _name)
    
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

#define DECL_DTORCALL_PLT(_clsName, _addr) \
    static inline auto FuncProxy_dtor##_clsName = (void(*)(ThisClass*))(GetMainLibraryAddress() + _addr); \
    ~_clsName() { FuncProxy_dtor##_clsName(this); }

#define DECL_NEWCALL(_clsName, _sym) \
    static inline auto FuncProxy_opnew##_clsName = GetMainLibrarySymbol<_clsName*(*)(size_t size)>(#_sym); \
    inline static _clsName* Instantiate(size_t size = sizeof(_clsName)) { return FuncProxy_opnew##_clsName(size); }
    
#define DECL_DLCALL(_clsName, _sym) \
    static inline auto FuncProxy_opdel##_clsName = GetMainLibrarySymbol<void(*)(void* ptr)>(#_sym); \
    inline void DeInstantiate() { FuncProxy_opdel##_clsName(this); }

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

#define CLASS_CONSTRUCT(_clsName, ...) \
    _clsName::FuncProxy_ctor##_clsName(__VA_ARGS__)

#define CLASS_DECONSTRUCT(_clsName, ...) \
    _clsName::FuncProxy_dtor##_clsName(__VA_ARGS__)

#define DECL_THISCALL_SIMPLE(_name, _sym, _ret) \
    DECL_THISCALL_HEAD(_name, _sym, _ret) \
    DECL_THISCALL_TAIL(_name)

#define DECL_FASTCALL_SIMPLE(_name, _sym, _ret, ...) \
    static inline auto _name = GetMainLibrarySymbol<_ret(*)(__VA_ARGS__)>(#_sym)

#define DECL_FASTCALL_SIMPLE_PLT(_name, _addr, _ret, ...) \
    static inline auto _name = (_ret(*)(__VA_ARGS__))(GetMainLibraryAddress() + _addr)

#define DECL_FASTCALL_SIMPLE_GLO(_name, _sym, _ret, ...) \
    inline auto _name = GetMainLibrarySymbol<_ret(*)(__VA_ARGS__)>(#_sym)

#define DECL_FASTCALL_SIMPLE_GLO_PLT(_name, _sym, _ret, ...) \
    inline auto _name = (_ret(*)(__VA_ARGS__))(GetMainLibraryAddress() + _addr)

#define GET_THISCALL_ADDR(_clsName, _name) \
    ( (uintptr_t)( _clsName::FuncProxy_##_name ) )

#define GET_CTOR_ADDR(_clsName) \
    ( (uintptr_t)( _clsName::FuncProxy_ctor##_clsName ) )

#define GET_DTOR_ADDR(_clsName) \
    ( (uintptr_t)( _clsName::FuncProxy_dtor##_clsName ) )

#endif // __AML_PSDK_BASE_H
