#ifndef __AML_PSDK_CALLEVENTS_H
#define __AML_PSDK_CALLEVENTS_H

#include "sdk_base.h"
#include <type_traits>
#include <vector>

// Yeah, this all below looks real bad lol.

#define DECL_EVENT_BASE(_name) \
    struct CallEvent_##_name {

#define DECL_EVENT_SYM(_ret, _sym, ...) \
        typedef _ret (MyType)(__VA_ARGS__); \
        static inline MyType* m_pOriginalFunc = NULL; \
        struct { \
            std::vector<EventType*> m_list; \
            void operator+=(EventType* newFn) { \
                m_list.push_back(newFn); StartEvent(); \
            } \
            void operator-=(EventType* newFn) { \
                for(auto it = m_list.begin(); it != m_list.end(); ++it) { if(*it == newFn) { m_list.erase(it); break; } } \
            } \
        } before, after; \
        void operator+=(EventType* newFn) { after += newFn; } \
        static inline void StartEvent() { \
            if(!m_pOriginalFunc) { \
                aml->Hook(GetMainLibrarySymbol(#_sym), (void*)(&EventExecuted), (void**)(&m_pOriginalFunc)); \
            } \
        }

#define DECL_EVENT_PLT(_ret, _addr, ...) \
        typedef _ret (MyType)(__VA_ARGS__); \
        static inline MyType* m_pOriginalFunc = NULL; \
        struct { \
            std::vector<EventType*> m_list; \
            void operator+=(EventType* newFn) { \
                m_list.push_back(newFn); StartEvent(); \
            } \
            void operator-=(EventType* newFn) { \
                for(auto it = m_list.begin(); it != m_list.end(); ++it) { if(*it == newFn) { m_list.erase(it); break; } } \
            } \
        } before, after; \
        void operator+=(EventType* newFn) { after += newFn; } \
        static inline void StartEvent() { \
            if(!m_pOriginalFunc) { \
                aml->HookPLT((void*)(GetMainLibraryAddress() + _addr), (void*)(&EventExecuted), (void**)(&m_pOriginalFunc)); \
            } \
        }

#define DECL_EVENT_BASE_END(_name) \
    }; static inline CallEvent_##_name _name

#define DECL_EVENT_SYM_ARG0_PICK0(_ret, _name, _sym) \
    DECL_EVENT_BASE(_name) \
        typedef void (EventType)(); \
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

#define DECL_EVENT_PLT_ARG0_PICK0(_ret, _name, _addr) \
    DECL_EVENT_BASE(_name) \
        typedef void (EventType)(); \
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

#define DECL_EVENT_SYM_ARG1_PICK0(_ret, _name, _sym, _t1, _v1) \
    DECL_EVENT_BASE(_name) \
        typedef void (EventType)(); \
        DECL_EVENT_SYM(_ret, _sym, _t1 _v1) \
        inline void CallBefore() { \
            for(auto fn : before.m_list) fn(); \
        } \
        inline void CallAfter() { \
            for(auto fn : after.m_list) fn(); \
        } \
        template<typename RetType = _ret> \
        static inline RetType EventExecutedImpl(_t1 _v1) { \
            _name.CallBefore(); \
            if constexpr (std::is_same_v<RetType, void>) { \
                _name.m_pOriginalFunc(_v1); \
                _name.CallAfter(); \
            } else { \
                RetType ret = _name.m_pOriginalFunc(_v1); \
                _name.CallAfter(); \
                return ret; \
            } \
        } \
        static inline _ret EventExecuted(_t1 _v1) { \
            return EventExecutedImpl(_v1); \
        } \
    DECL_EVENT_BASE_END(_name)

#define DECL_EVENT_PLT_ARG1_PICK0(_ret, _name, _addr, _t1, _v1) \
    DECL_EVENT_BASE(_name) \
        typedef void (EventType)(); \
        DECL_EVENT_PLT(_ret, _addr, _t1 _v1) \
        inline void CallBefore() { \
            for(auto fn : before.m_list) fn(); \
        } \
        inline void CallAfter() { \
            for(auto fn : after.m_list) fn(); \
        } \
        template<typename RetType = _ret> \
        static inline RetType EventExecutedImpl(_t1 _v1) { \
            _name.CallBefore(); \
            if constexpr (std::is_same_v<RetType, void>) { \
                _name.m_pOriginalFunc(_v1); \
                _name.CallAfter(); \
            } else { \
                RetType ret = _name.m_pOriginalFunc(_v1); \
                _name.CallAfter(); \
                return ret; \
            } \
        } \
        static inline _ret EventExecuted(_t1 _v1) { \
            return EventExecutedImpl(_v1); \
        } \
    DECL_EVENT_BASE_END(_name)

#define DECL_EVENT_PLT_ARG1_PICK1(_ret, _name, _addr, _t1, _v1) \
    DECL_EVENT_BASE(_name) \
        typedef void (EventType)(_t1 _v1); \
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

#define DECL_EVENT_SYM_ARG1_PICK1(_ret, _name, _sym, _t1, _v1) \
    DECL_EVENT_BASE(_name) \
        typedef void (EventType)(_t1 _v1); \
        DECL_EVENT_SYM(_ret, _sym, _t1 _v1) \
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

#define DECL_EVENT_SYM_ARG2_PICK1(_ret, _name, _sym, _t1, _v1, _t2, _v2) \
    DECL_EVENT_BASE(_name) \
        typedef void (EventType)(_t1 _v1); \
        DECL_EVENT_SYM(_ret, _sym, _t1 _v1, _t2 _v2) \
        inline void CallBefore(_t1 _v1) { \
            for(auto fn : before.m_list) fn(_v1); \
        } \
        inline void CallAfter(_t1 _v1) { \
            for(auto fn : after.m_list) fn(_v1); \
        } \
        template<typename RetType = _ret> \
        static inline RetType EventExecutedImpl(_t1 _v1, _t2 _v2) { \
            _name.CallBefore(_v1); \
            if constexpr (std::is_same_v<RetType, void>) { \
                _name.m_pOriginalFunc(_v1, _v2); \
                _name.CallAfter(_v1); \
            } else { \
                RetType ret = _name.m_pOriginalFunc(_v1, _v2); \
                _name.CallAfter(_v1); \
                return ret; \
            } \
        } \
        static inline _ret EventExecuted(_t1 _v1, _t2 _v2) { \
            return EventExecutedImpl(_v1, _v2); \
        } \
    DECL_EVENT_BASE_END(_name)

#define DECL_EVENT_SYM_ARG2_PICK2(_ret, _name, _sym, _t1, _v1, _t2, _v2) \
    DECL_EVENT_BASE(_name) \
        typedef void (EventType)(_t1 _v1, _t2 _v2); \
        DECL_EVENT_SYM(_ret, _sym, _t1 _v1, _t2 _v2) \
        inline void CallBefore(_t1 _v1, _t2 _v2) { \
            for(auto fn : before.m_list) fn(_v1, _v2); \
        } \
        inline void CallAfter(_t1 _v1, _t2 _v2) { \
            for(auto fn : after.m_list) fn(_v1, _v2); \
        } \
        template<typename RetType = _ret> \
        static inline RetType EventExecutedImpl(_t1 _v1, _t2 _v2) { \
            _name.CallBefore(_v1, _v2); \
            if constexpr (std::is_same_v<RetType, void>) { \
                _name.m_pOriginalFunc(_v1, _v2); \
                _name.CallAfter(_v1, _v2); \
            } else { \
                RetType ret = _name.m_pOriginalFunc(_v1, _v2); \
                _name.CallAfter(_v1, _v2); \
                return ret; \
            } \
        } \
        static inline _ret EventExecuted(_t1 _v1, _t2 _v2) { \
            return EventExecutedImpl(_v1, _v2); \
        } \
    DECL_EVENT_BASE_END(_name)

#define DECL_EVENT_SYM_ARG4_PICK4(_ret, _name, _sym, _t1, _v1, _t2, _v2, _t3, _v3, _t4, _v4) \
    DECL_EVENT_BASE(_name) \
        typedef void (EventType)(_t1 _v1, _t2 _v2, _t3 _v3, _t4 _v4); \
        DECL_EVENT_SYM(_ret, _sym, _t1 _v1, _t2 _v2, _t3 _v3, _t4 _v4) \
        inline void CallBefore(_t1 _v1, _t2 _v2, _t3 _v3, _t4 _v4) { \
            for(auto fn : before.m_list) fn(_v1, _v2, _v3, _v4); \
        } \
        inline void CallAfter(_t1 _v1, _t2 _v2, _t3 _v3, _t4 _v4) { \
            for(auto fn : after.m_list) fn(_v1, _v2, _v3, _v4); \
        } \
        template<typename RetType = _ret> \
        static inline RetType EventExecutedImpl(_t1 _v1, _t2 _v2, _t3 _v3, _t4 _v4) { \
            _name.CallBefore(_v1, _v2, _v3, _v4); \
            if constexpr (std::is_same_v<RetType, void>) { \
                _name.m_pOriginalFunc(_v1, _v2, _v3, _v4); \
                _name.CallAfter(_v1, _v2, _v3, _v4); \
            } else { \
                RetType ret = _name.m_pOriginalFunc(_v1, _v2, _v3, _v4); \
                _name.CallAfter(_v1, _v2, _v3, _v4); \
                return ret; \
            } \
        } \
        static inline _ret EventExecuted(_t1 _v1, _t2 _v2, _t3 _v3, _t4 _v4) { \
            return EventExecutedImpl(_v1, _v2, _v3, _v4); \
        } \
    DECL_EVENT_BASE_END(_name)

#endif // __AML_PSDK_CALLEVENTS_H