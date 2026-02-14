#ifndef __AML_PSDK_SASPRITE_H
#define __AML_PSDK_SASPRITE_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/renderware/RwVector.h>
#include <aml-psdk/renderware/RwRGBA.h>

struct RwIm2DVertex;

DECL_CLASS(CSprite)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN7CSprite10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Draw3DSprite, _ZN7CSprite12Draw3DSpriteEfffffffff, void, float x, float y, float z, float sizeX, float sizeY, float r, float g, float b, float a);
    DECL_FASTCALL_SIMPLE(CalcScreenCoors, _ZN7CSprite15CalcScreenCoorsERK5RwV3dPS0_PfS4_bb, bool, RwV3d const &In, RwV3d *pResult, float *pScaleX, float *pScaleY, bool ClipFarPlane, bool ClipNearPlane);
    DECL_FASTCALL_SIMPLE(CalcHorizonCoors, _ZN7CSprite16CalcHorizonCoorsEv, float);
    DECL_FASTCALL_SIMPLE(FlushSpriteBuffer, _ZN7CSprite17FlushSpriteBufferEv, void);
    DECL_FASTCALL_SIMPLE(InitSpriteBuffer, _ZN7CSprite16InitSpriteBufferEv, void);
    DECL_FASTCALL_SIMPLE(InitSpriteBuffer2D, _ZN7CSprite18InitSpriteBuffer2DEv, void);
    DECL_FASTCALL_SIMPLE(RenderBufferedOneXLUSprite, _ZN7CSprite26RenderBufferedOneXLUSpriteEfffffhhhsfh, void,
        float ScreenX, float ScreenY, float ScreenZ, float SizeX, float SizeY, u8 R, u8 G, u8 B, i16 Intensity16, float RecipZ, u8 Alpha);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite, _ZN7CSprite18RenderOneXLUSpriteEfffffhhhsfhhhff, void,
        float ScreenX, float ScreenY, float ScreenZ, float SizeX, float SizeY, u8 R, u8 G, u8 B, i16 Intensity16, float RecipZ, u8 Alpha, u8 FlipU, u8 FlipV, float uvPad1, float uvPad2);
    DECL_FASTCALL_SIMPLE(RenderBufferedOneXLUSprite_Rotate_Aspect, _ZN7CSprite40RenderBufferedOneXLUSprite_Rotate_AspectEfffffhhhsffh, void,
        float ScreenX, float ScreenY, float ScreenZ, float SizeX, float SizeY, u8 R, u8 G, u8 B, i16 Intensity16, float RecipZ, float Rotation, u8 Alpha);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite_Triangle, _ZN7CSprite27RenderOneXLUSprite_TriangleEfffffffhhhsfh, void,
        float ScreenX1, float ScreenY1, float ScreenX2, float ScreenY2, float ScreenX3, float ScreenY3, float ScreenZ, u8 R, u8 G, u8 B, i16 Intensity16, float RecipZ, u8 Alpha);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite_Rotate_Aspect, _ZN7CSprite32RenderOneXLUSprite_Rotate_AspectEfffffhhhsffh, void,
        float ScreenX, float ScreenY, float ScreenZ, float SizeX, float SizeY, u8 R, u8 G, u8 B, i16 Intensity16, float RecipZ, float Rotation, u8 Alpha);
    DECL_FASTCALL_SIMPLE(RenderBufferedOneXLUSprite_Rotate_Dimension, _ZN7CSprite43RenderBufferedOneXLUSprite_Rotate_DimensionEfffffhhhsffh, void,
        float ScreenX, float ScreenY, float ScreenZ, float SizeX, float SizeY, u8 R, u8 G, u8 B, i16 Intensity16, float RecipZ, float Rotation, u8 Alpha);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite_Rotate_Dimension, _ZN7CSprite35RenderOneXLUSprite_Rotate_DimensionEfffffhhhsffh, void,
        float ScreenX, float ScreenY, float ScreenZ, float SizeX, float SizeY, u8 R, u8 G, u8 B, i16 Intensity16, float RecipZ, float Rotation, u8 Alpha);
    DECL_FASTCALL_SIMPLE(RenderBufferedOneXLUSprite_Rotate_2Colours, _ZN7CSprite42RenderBufferedOneXLUSprite_Rotate_2ColoursEfffffhhhhhhffffh, void,
        float ScreenX, float ScreenY, float ScreenZ, float SizeX, float SizeY, u8 R1, u8 G1, u8 B1, u8 R2, u8 G2, u8 B2, float ToColour1X, float ToColour1Y, float RecipZ, u8 Alpha, float Rotation);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite_Rotate_2Colours, _ZN7CSprite34RenderOneXLUSprite_Rotate_2ColoursEfffffhhhhhhffffh, void,
        float ScreenX, float ScreenY, float ScreenZ, float SizeX, float SizeY, u8 R1, u8 G1, u8 B1, u8 R2, u8 G2, u8 B2, float ToColour1X, float ToColour1Y, float RecipZ, float Rotation, u8 Alpha);
    DECL_FASTCALL_SIMPLE(RenderBufferedOneXLUSprite2D, _ZN7CSprite28RenderBufferedOneXLUSprite2DEffffRK6RwRGBAsh, void,
        float ScreenX, float ScreenY, float SizeX, float SizeY, RwRGBA const &rgbaColor, i16 Intensity16, u8 Alpha);
    DECL_FASTCALL_SIMPLE(Set4Vertices2D1, _ZN7CSprite14Set4Vertices2DEP14RwOpenGLVertexRK5CRectRK5CRGBAS7_S7_S7_, void,
        RwIm2DVertex *maVertices, CRect const &Rectangle, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite2D, _ZN7CSprite20RenderOneXLUSprite2DEffffRK6RwRGBAsh, void,
        float ScreenX, float ScreenY, float SizeX, float SizeY, RwRGBA const &rgbaColor, i16 Intensity16, u8 Alpha);
    DECL_FASTCALL_SIMPLE(RenderBufferedOneXLUSprite2D_Rotate_Dimension, _ZN7CSprite45RenderBufferedOneXLUSprite2D_Rotate_DimensionEffffRK6RwRGBAsfh, void,
        float ScreenX, float ScreenY, float SizeX, float SizeY, RwRGBA const &rgbaColor, i16 Intensity16, float Rotation, u8 Alpha);
    DECL_FASTCALL_SIMPLE(Set4Vertices2D2, _ZN7CSprite14Set4Vertices2DEP14RwOpenGLVertexffffffffRK5CRGBAS4_S4_S4_, void,
        RwIm2DVertex *maVertices, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite2D_Rotate_Dimension, _ZN7CSprite37RenderOneXLUSprite2D_Rotate_DimensionEffffRK6RwRGBAsfh, void,
        float ScreenX, float ScreenY, float SizeX, float SizeY, RwRGBA const &rgbaColor, i16 Intensity16, float Rotation, u8 Alpha);

    // Helper functions
    static void Set4Vertices2D(RwIm2DVertex *maVertices, CRect const &Rectangle, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba)
    {
        Set4Vertices2D1(maVertices, Rectangle, TopLeftrgba, TopRightrgba, BottomLeftrgba, BottomRightrgba);
    }
    static void Set4Vertices2D(RwIm2DVertex *maVertices, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba)
    {
        Set4Vertices2D2(maVertices, x1, y1, x2, y2, x3, y3, x4, y4, TopLeftrgba, TopRightrgba, BottomLeftrgba, BottomRightrgba);
    }

    // STATIC values
    DECL_VALUE_PLT_FLT(m_f2DNearScreenZ, BYBIT(0x678688, 0x84ED38));
    DECL_VALUE_PLT_FLT(m_f2DFarScreenZ, BYBIT(0x6799B8, 0x851388));
    DECL_VALUE_PLT_FLT(m_fRecipNearClipPlane, BYBIT(0x678000, 0x84E020));
    DECL_VALUE_PLT_I32(m_bFlushSpriteBufferSwitchZTest, BYBIT(0x679538, 0x850A80));
DECL_CLASS_END()

#define m_f2DNearScreenZ m_f2DNearScreenZ()
#define m_f2DFarScreenZ m_f2DFarScreenZ()
#define m_fRecipNearClipPlane m_fRecipNearClipPlane()
#define m_bFlushSpriteBufferSwitchZTest m_bFlushSpriteBufferSwitchZTest()

#endif // __AML_PSDK_SASPRITE_H