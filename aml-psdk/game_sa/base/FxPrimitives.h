#ifndef __AML_PSDK_SAFXPRIMITIVES_H
#define __AML_PSDK_SAFXPRIMITIVES_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/renderware/RwRGBA.h>

struct FxSystem_c;

struct FxBox_c
{
    FxBox_c()
    {
        m_fCornerA_x = m_fCornerA_y = m_fCornerA_z = 999999.0f;
        m_fCornerB_x = m_fCornerB_y = m_fCornerB_z = -999999.0f;
    }

    float m_fCornerA_x;
    float m_fCornerB_x;
    float m_fCornerA_y;
    float m_fCornerB_y;
    float m_fCornerA_z;
    float m_fCornerB_z;
};

struct FxPlane_c
{
    RwV3d m_vecNormal;
    float m_fDistance;
};

struct Particle_c : ListItem_c {};

struct FxEmitterPrt_c : Particle_c
{
    float         m_life;
    float         m_currLife;
    RwV3d         m_pos;
    RwV3d         m_vel;
    FxSystem_c   *m_fxSysPtr;
    unsigned char m_multR;
    unsigned char m_multG;
    unsigned char m_multB;
    unsigned char m_multA;
    unsigned char m_multSize;
    unsigned char m_multRot;
    unsigned char m_randR;
    unsigned char m_randG;
    unsigned char m_randB;
    unsigned char m_brightness;
    unsigned char m_zRot;
    unsigned char m_localToSystem;
    float         m_currRot;
};

struct FxPrtMult_c
{
    FxPrtMult_c()
    {
        m_color.red = m_color.green = m_color.blue = m_color.alpha = 1.0f;
        m_fSize = m_fRotation = m_fLife = 1.0f;
    }

    RwRGBAReal m_color;
    float m_fSize;
    float m_fRotation;
    float m_fLife;
};




DECL_CLASS(FxSphere_c)
    // Construct/Deconstruct functions
    FxSphere_c() { m_nNumPlanesPassed = 0; }
    DECL_NEWCALL(FxSphere_c, BYBIT(_ZN10FxSphere_cnwEji, _ZN10FxSphere_cnwEmi))
    DECL_DLCALL(FxSphere_c, _ZN10FxSphere_cdlEPv)

    // Member functions
    DECL_THISCALL_HEAD(IsCollision, _ZN10FxSphere_c11IsCollisionEPS_, u8, FxSphere_c *sphere)
    DECL_THISCALL_TAIL(IsCollision, sphere)
    
    DECL_THISCALL_HEAD(GetDistToPlane, _ZN10FxSphere_c14GetDistToPlaneEP9FxPlane_c, float, FxPlane_c *plane)
    DECL_THISCALL_TAIL(GetDistToPlane, plane)

    // Member values
    RwV3d        m_vecCenter;
    float        m_fRadius;
    unsigned int m_nNumPlanesPassed;
DECL_CLASS_END()



DECL_CLASS(FxFrustumInfo_c)
    // Member functions
    DECL_THISCALL_HEAD(IsCollision, _ZN15FxFrustumInfo_c11IsCollisionEP10FxSphere_c, int, FxSphere_c *sphere)
    DECL_THISCALL_TAIL(IsCollision, sphere)

    // Member values
    FxSphere_c m_sphere;
    FxPlane_c m_planes[4];
DECL_CLASS_END()

#endif // __AML_PSDK_SAFXPRIMITIVES_H