#ifndef __AML_PSDK_SAEVENTEDITABLERESPONSE_H
#define __AML_PSDK_SAEVENTEDITABLERESPONSE_H

#include "Event.h"

DECL_CLASS_BASED(CEventEditableResponse, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CEventEditableResponse, _ZN22CEventEditableResponseC2Ev);
    DECL_DTORCALL(CEventEditableResponse, _ZN22CEventEditableResponseD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(WillRespond, _ZN4CPed27PedIsInvolvedInConversationEv, bool);
    
    DECL_THISCALL_HEAD(ComputeResponseTaskType, _ZN22CEventEditableResponse23ComputeResponseTaskTypeEP9CPedGroup, void, CPedGroup* pPedGroup);
    DECL_THISCALL_TAIL(ComputeResponseTaskType, pPedGroup)
    

    /*
DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)


    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)
    
    DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)
    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)
    
    DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)
    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)
    
    DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)
    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)
    
    DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)
    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)
    
    DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)
    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)
    
    DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)
    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)*/

    // Member values
    bool m_bWitnessedFirstHand;
    short m_iTaskType;
    short m_iFacialTaskType;
DECL_CLASS_END()

#endif // __AML_PSDK_SAEVENTEDITABLERESPONSE_H
