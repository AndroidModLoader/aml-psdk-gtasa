#ifndef __AML_PSDK_SACORONAEXTENDER_H
#define __AML_PSDK_SACORONAEXTENDER_H

#include <aml-psdk/game_sa/other/Coronas.h>
#include <aml-psdk/game_sa/entity/Camera.h>
#include <aml-psdk/game_sa/entity/Bike.h>
#include <aml-psdk/game_sa/engine/World.h>
#include <aml-psdk/game_sa/engine/Sprite.h>
#include <aml-psdk/game_sa/base/Timer.h>
#include <aml-psdk/renderware/RwRender.h>
#include "../Events.h"

#define MAX_EXT_CORONAS_STORAGE 16 // Set your value there. Keep it as low as possible to be optimised :)

struct CoronasExtender
{
    CoronasExtender()
    {
        Events::renderCoronasEvent.after += DrawExtCoronasCB;
        Events::gameProcessEvent.after += UpdateExtCoronasCB;
    }
    static inline void DrawExtCoronasCB()
    {
        RwRenderStateSet(rwRENDERSTATEZWRITEENABLE,      (void*)false);
        RwRenderStateSet(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);
        RwRenderStateSet(rwRENDERSTATESRCBLEND,          (void*)rwBLENDONE);
        RwRenderStateSet(rwRENDERSTATEDESTBLEND,         (void*)rwBLENDONE);
        RwRenderStateSet(rwRENDERSTATEZTESTENABLE,       (void*)true);

        for(int i = 0; i < MAX_EXT_CORONAS_STORAGE; ++i)
        {
            CRegisteredCorona& c = m_aCoronas[i];
            if(!c.m_dwId || (!c.m_nFadeState && !c.m_Color.a) ) continue;

            CVector cpos = c.m_vPosn;
            if(c.m_pAttachedTo || !c.m_pAttachedTo->GetMatrix())
            {
                CMatrix* mat = c.m_pAttachedTo->GetMatrix();
                if(c.m_pAttachedTo->IsVehicle() && c.m_pAttachedTo->AsVehicle()->IsSubBike())
                {
                    mat = &c.m_pAttachedTo->AsVehicle()->AsBike()->m_mLeanMatrix;
                }
                cpos = *mat * cpos + mat->GetPosition();
            }

            CVector2D onScrSize;
            CVector   onScrPos;
            if(( c.m_bOffScreen = !CSprite::CalcScreenCoors(cpos, &onScrPos, &onScrSize.x, &onScrSize.y, true, true) ))
            {
                continue;
            }

            // TODO:
        }
        CSprite::FlushSpriteBuffer();
    }
    static inline void UpdateExtCoronasCB()
    {
        CVector& camPos = TheCamera.GetPosition();
        const float timeStep = CTimer::GetTimeStep();

        for(int i = 0; i < MAX_EXT_CORONAS_STORAGE; ++i)
        {
            CRegisteredCorona& c = m_aCoronas[i];
            if(c.m_dwId)
            {
                // NOT using m_aCoronas[i].Update() as it's using CCoronas' values inside

                if(!c.m_bRegisteredThisFrame) c.m_Color.a = 0;
                if(c.m_bAttached && !c.m_pAttachedTo)
                {
                    c.m_dwId = 0;
                    --m_nCoronasNum;
                    continue;
                }

                const float fadeStep = timeStep * c.m_fFadeSpeed;
                if(!c.m_bCheckObstacles || CWorld::GetIsLineOfSightClear(c.m_vPosn, camPos, true, false, false, false, false, false, false) )
                {
                    if(c.m_bOffScreen || (c.m_bOnlyFromBelow && camPos.z > c.m_vPosn.z) )
                    {
                        c.m_nFadeState = (u8)(std::max(0.f, (float)c.m_nFadeState - fadeStep));
                    }
                    else
                    {
                        if(CCoronas::bChangeBrightnessImmediately)
                        {
                            c.m_nFadeState = c.m_Color.a;
                        }
                        else if(c.m_nFadeState != c.m_Color.a)
                        {
                            if(c.m_nFadeState > c.m_Color.a)
                            {
                                c.m_nFadeState = (u8)(std::max((float)c.m_Color.a, (float)c.m_nFadeState - fadeStep));
                            }
                            else
                            {
                                c.m_nFadeState = (u8)(std::min((float)c.m_Color.a, (float)c.m_nFadeState + fadeStep));
                            }
                        }
                    }
                }
                else
                {
                    c.m_nFadeState = (u8)(std::max(0.f, (float)c.m_nFadeState - fadeStep));
                }

                if(!c.m_nFadeState && !c.m_bJustCreated)
                {
                    c.m_dwId = 0;
                    --m_nCoronasNum;
                }

                c.m_bJustCreated = false;
                c.m_bRegisteredThisFrame = false;
            }
        }
    }
    static inline CRegisteredCorona m_aCoronas[MAX_EXT_CORONAS_STORAGE] { 0 };
    static inline int m_nCoronasNum = 0;
} g_CoronasExtender;

#endif // __AML_PSDK_SACORONAEXTENDER_H