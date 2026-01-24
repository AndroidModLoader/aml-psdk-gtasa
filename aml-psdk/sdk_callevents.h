#ifndef __AML_PSDK_CALLEVENTS_H
#define __AML_PSDK_CALLEVENTS_H

#include "sdk_base.h"
#include <type_traits>
#include <vector>

#define DECL_EVENT_BASE(_name) \
    struct CallEvent_##_name {

#define DECL_EVENT_SYM(_ret, _sym, ...) \
        typedef _ret (MyType)(__VA_ARGS__); \
        static inline MyType* m_pOriginalFunc = NULL; \
        struct { \
            std::vector<MyType*> m_list; \
            void operator+=(MyType* newFn) { \
                m_list.push_back(newFn); StartEvent(); \
            } \
            void operator-=(MyType* newFn) { \
                for(auto it = m_list.begin(); it != m_list.end(); ++it) { if(*it == newFn) { m_list.erase(it); break; } } \
            } \
        } before, after; \
        void operator+=(MyType* newFn) { after += newFn; } \
        static inline void StartEvent() { \
            if(!m_pOriginalFunc) { \
                aml->Hook(GetMainLibrarySymbol(#_sym), (void*)(&EventExecuted), (void**)(&m_pOriginalFunc)); \
            } \
        }

#define DECL_EVENT_PLT(_ret, _addr, ...) \
        typedef _ret (MyType)(__VA_ARGS__); \
        static inline MyType* m_pOriginalFunc = NULL; \
        struct { \
            std::vector<MyType*> m_list; \
            void operator+=(MyType* newFn) { \
                m_list.push_back(newFn); StartEvent(); \
            } \
            void operator-=(MyType* newFn) { \
                for(auto it = m_list.begin(); it != m_list.end(); ++it) { if(*it == newFn) { m_list.erase(it); break; } } \
            } \
        } before, after; \
        void operator+=(MyType* newFn) { after += newFn; } \
        static inline void StartEvent() { \
            if(!m_pOriginalFunc) { \
                aml->HookPLT((void*)(GetMainLibraryAddress() + _addr), (void*)(&EventExecuted), (void**)(&m_pOriginalFunc)); \
            } \
        }

#define DECL_EVENT_BASE_END(_name) \
    }; static inline CallEvent_##_name _name

#define DECL_EVENT_SYM_ARG0(_ret, _name, _sym) \
    DECL_EVENT_BASE(_name) \
        DECL_EVENT_SYM(_ret, _sym) \
        inline void CallBefore() { \
            for(auto fn : before.m_list) fn(); \
        } \
        inline void CallAfter() { \
            for(auto fn : after.m_list) fn(); \
        } \
        template<typename RetType = _ret> \
        static inline RetType EventExecutedImpl() { \
            _name.CallBefore(); \
            if constexpr (std::is_same_v<RetType, void>) { \
                _name.m_pOriginalFunc(); \
                _name.CallAfter(); \
            } else { \
                RetType ret = _name.m_pOriginalFunc(); \
                _name.CallAfter(); \
                return ret; \
            } \
        } \
        static inline _ret EventExecuted() { \
            return EventExecutedImpl(); \
        } \
    DECL_EVENT_BASE_END(_name)

#define DECL_EVENT_PLT_ARG0(_ret, _name, _addr) \
    DECL_EVENT_BASE(_name) \
        DECL_EVENT_PLT(_ret, _addr) \
        inline void CallBefore() { \
            for(auto fn : before.m_list) fn(); \
        } \
        inline void CallAfter() { \
            for(auto fn : after.m_list) fn(); \
        } \
        template<typename RetType = _ret> \
        static inline RetType EventExecutedImpl() { \
            _name.CallBefore(); \
            if constexpr (std::is_same_v<RetType, void>) { \
                _name.m_pOriginalFunc(); \
                _name.CallAfter(); \
            } else { \
                RetType ret = _name.m_pOriginalFunc(); \
                _name.CallAfter(); \
                return ret; \
            } \
        } \
        static inline _ret EventExecuted() { \
            return EventExecutedImpl(); \
        } \
    DECL_EVENT_BASE_END(_name)

#define DECL_EVENT_PLT_ARG1(_ret, _name, _addr, _t1, _v1) \
    DECL_EVENT_BASE(_name) \
        DECL_EVENT_PLT(_ret, _addr, _t1 _v1) \
        inline void CallBefore(_t1 _v1) { \
            for(auto fn : before.m_list) fn(_v1); \
        } \
        inline void CallAfter(_t1 _v1) { \
            for(auto fn : after.m_list) fn(_v1); \
        } \
        template<typename RetType = _ret> \
        static inline RetType EventExecutedImpl(_t1 _v1) { \
            _name.CallBefore(_v1); \
            if constexpr (std::is_same_v<RetType, void>) { \
                _name.m_pOriginalFunc(_v1); \
                _name.CallAfter(_v1); \
            } else { \
                RetType ret = _name.m_pOriginalFunc(_v1); \
                _name.CallAfter(_v1); \
                return ret; \
            } \
        } \
        static inline _ret EventExecuted(_t1 _v1) { \
            return EventExecutedImpl(_v1); \
        } \
    DECL_EVENT_BASE_END(_name)

#endif // __AML_PSDK_CALLEVENTS_H