#ifndef __AML_PSDK_SAFONT_H
#define __AML_PSDK_SAFONT_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/RGBA.h>
#include <aml-psdk/gta_base/Rect.h>
#include <aml-psdk/gta_base/GxtChar.h>

#define MAX_FONT_SPRITES 2
#define MAX_FONT_BUTTON_SPRITES 15

struct tFontData
{
    char m_propValues[208];
    char m_spaceValue;
    char m_unpropValue;
};

enum eFontAlignment : unsigned char
{
    ALIGN_CENTER,
    ALIGN_LEFT,
    ALIGN_RIGHT 
};

enum eFontStyle : unsigned char
{
    FONT_GOTHIC = 0,
    FONT_SUBTITLES,
    FONT_MENU,
    FONT_PRICEDOWN
};

enum eFontStyleMobile : unsigned char
{
    FO_FONT_STYLE_BANK = 0,
    FO_FONT_STYLE_STANDARD,
    FO_FONT_STYLE_SPACEAGE,
    FO_FONT_STYLE_HEADING,
    FO_FONT_STYLE_JAPAN_BANK,
    FO_FONT_STYLE_HEADING_JAPAN,
    FO_FONT_STYLE_STANDARD_JAPAN,
    FO_FONT_STYLE_JAPAN = FO_FONT_STYLE_SPACEAGE,
};

struct CFontRenderState
{
    int32_t id;
    float x;
    float y;
    float ScaleX;
    float ScaleY;
    CRGBA Colour;
    float PixelsToAdd;
    float Slope;
    float SlopeRefX;
    float SlopeRefY;
    uint8_t Shadow;
    uint8_t ExtraFont;
    uint8_t Proportional;
    int16_t Style;
    int8_t EdgeAmount;
};

struct CFontDetails
{
    CRGBA Color;
    float ScaleX;
    float ScaleY;
    float Slope;
    float SlopeRefX;
    float SlopeRefY;
    u8 Justify;
    u8 Centre;
    u8 RightJustify;
    u8 Background;
    u8 BackgroundOutline;
    u8 Proportional;
    u8 Shadow;
    float AlphaFade;
    CRGBA BGColor;
    float WrapEnd;
    float Centrex;
    float RightJustifyWrap;
    u8 Style;
    u8 ExtraFont;
    i8 DropAmount;
    CRGBA DropColor;
    i8 EdgeAmount;
    i8 EdgeSpace;
};


DECL_CLASS(CFont)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN5CFont10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(ClearSpecialLanguages, _ZN5CFont21ClearSpecialLanguagesEv, void);
    DECL_FASTCALL_SIMPLE(AddJapaneseTexture, _ZN5CFont18AddJapaneseTextureEv, void);
    DECL_FASTCALL_SIMPLE(AddStandardTexture, _ZN5CFont18AddStandardTextureEv, void);
    DECL_FASTCALL_SIMPLE(AddEFIGSFont, _ZN5CFont12AddEFIGSFontEv, void);
    DECL_FASTCALL_SIMPLE(AddRussianTexture, _ZN5CFont17AddRussianTextureEv, void);
    DECL_FASTCALL_SIMPLE(GetCharacterSize, _ZN5CFont16GetCharacterSizeEtb, float, GxtChar Character, bool fromRenderState);
    DECL_FASTCALL_SIMPLE(FindSubFontCharacter, _ZN5CFont20FindSubFontCharacterEth, GxtChar, GxtChar Character, u8 subfont_type);
    DECL_FASTCALL_SIMPLE(RemapCharacterWithoutGraphicEt, _ZN5CFont28RemapCharacterWithoutGraphicEt, GxtChar, GxtChar Character);
    DECL_FASTCALL_SIMPLE(LoadFontValues, _ZN5CFont14LoadFontValuesEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN5CFont8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(InitPerFrame, _ZN5CFont12InitPerFrameEv, void);
    DECL_FASTCALL_SIMPLE(SetDropShadowPosition, _ZN5CFont21SetDropShadowPositionEa, void, i8 Amount);
    DECL_FASTCALL_SIMPLE(PrintChar, _ZN5CFont9PrintCharEfft, void, float x, float y, GxtChar Character);
    DECL_FASTCALL_SIMPLE(GetHeight, _ZN5CFont9GetHeightEb, float, bool UseRenderState);
    DECL_FASTCALL_SIMPLE(RenderFontBuffer, _ZN5CFont16RenderFontBufferEv, void);
    DECL_FASTCALL_SIMPLE(ComputeHeight, _ZN5CFont13ComputeHeightEf, float, float fHeight);
    DECL_FASTCALL_SIMPLE(ParseToken, _ZN5CFont10ParseTokenEPtR5CRGBAhPc, GxtChar*, GxtChar *pCharacters, CRGBA &color, u8 shadow, char *latest_token);
    DECL_FASTCALL_SIMPLE(RenderString, _ZN5CFont12RenderStringEffPtS0_f, void, float x, float y, GxtChar *pCharacterStart, GxtChar *pCharacterEnd, float PixelsToAdd);
    DECL_FASTCALL_SIMPLE(PrintStringFromBottom, _ZN5CFont21PrintStringFromBottomEffPt, void, float x, float Bottomy, GxtChar *pCharacters);
    DECL_FASTCALL_SIMPLE(GetNumberLines, _ZN5CFont14GetNumberLinesEffPt, size_t, float x, float y, GxtChar *pCharacters);
    DECL_FASTCALL_SIMPLE(PrintString1, _ZN5CFont11PrintStringEffPt, void, float x, float y, GxtChar *pCharacters);
    DECL_FASTCALL_SIMPLE(GetTextRect, _ZN5CFont11GetTextRectEP5CRectffPt, void, CRect *pRect, float x, float y, GxtChar *pCharacters);
    DECL_FASTCALL_SIMPLE(ProcessStringToDisplay, _ZN5CFont22ProcessStringToDisplayEffPt, void, float x, float y, GxtChar *pCharacters);
    DECL_FASTCALL_SIMPLE(ProcessCurrentString, _ZN5CFont20ProcessCurrentStringEhffPt, size_t, u8 PrintTheString, float x, float y, GxtChar *NewStringChars);
    DECL_FASTCALL_SIMPLE(GetStringWidth1, _ZN5CFont14GetStringWidthEPthh, float, GxtChar *pInCharacters, u8 bIncludeSpaces, u8 bUsingWithScriptValues);
    DECL_FASTCALL_SIMPLE(GetNextSpace, _ZN5CFont12GetNextSpaceEPt, GxtChar*, GxtChar *pCharacters);
    DECL_FASTCALL_SIMPLE(SetColor, _ZN5CFont8SetColorE5CRGBA, void, CRGBA& color);
    DECL_FASTCALL_SIMPLE(GetStringWidth2, _ZN5CFont14GetStringWidthEPthhh, float, GxtChar *pCharacters, u8 bIncludeSpaces, u8 bUsingWithScriptValues, u8 isAscii);
    DECL_FASTCALL_SIMPLE(FilterOutTokensFromString, _ZN5CFont25FilterOutTokensFromStringEPt, void, GxtChar *str);
    DECL_FASTCALL_SIMPLE(character_code, _ZN5CFont14character_codeEh, GxtChar, u8 a);
    DECL_FASTCALL_SIMPLE(SetScale1, _ZN5CFont8SetScaleEf, void, float fHeight);
    DECL_FASTCALL_SIMPLE(SetSlantRefPoint, _ZN5CFont16SetSlantRefPointEff, void, float x, float y);
    DECL_FASTCALL_SIMPLE(SetSlant, _ZN5CFont8SetSlantEf, void, float angle);
    DECL_FASTCALL_SIMPLE(SetFontStyle, _ZN5CFont12SetFontStyleEh, void, u8 style);
    DECL_FASTCALL_SIMPLE(SetWrapx, _ZN5CFont8SetWrapxEf, void, float x);
    DECL_FASTCALL_SIMPLE(SetCentreSize, _ZN5CFont13SetCentreSizeEf, void, float x);
    DECL_FASTCALL_SIMPLE(SetRightJustifyWrap, _ZN5CFont19SetRightJustifyWrapEf, void, float wrap);
    DECL_FASTCALL_SIMPLE(SetAlphaFade, _ZN5CFont12SetAlphaFadeEf, void, float alpha);
    DECL_FASTCALL_SIMPLE(SetDropColor, _ZN5CFont12SetDropColorE5CRGBA, void, CRGBA& dropcolor);
    DECL_FASTCALL_SIMPLE(SetEdge, _ZN5CFont7SetEdgeEa, void, i8 amount);
    DECL_FASTCALL_SIMPLE(SetProportional, _ZN5CFont15SetProportionalEh, void, u8 prop);
    DECL_FASTCALL_SIMPLE(SetBackground, _ZN5CFont13SetBackgroundEhh, void, u8 bg, u8 outline);
    DECL_FASTCALL_SIMPLE(SetBackgroundColor, _ZN5CFont18SetBackgroundColorE5CRGBA, void, CRGBA& bgcolor);
    DECL_FASTCALL_SIMPLE(SetJustify, _ZN5CFont10SetJustifyEh, void, u8 justify);
    DECL_FASTCALL_SIMPLE(SetOrientation, _ZN5CFont14SetOrientationEh, void, eFontAlignment orientation);

    // Helper functions
    static inline GxtChar tmpString[512];
    static inline float GetStringWidth(GxtChar *pInCharacters, u8 bIncludeSpaces, u8 bUsingWithScriptValues)
    {
        return GetStringWidth1(pInCharacters, bIncludeSpaces, bUsingWithScriptValues);
    }
    static inline float GetStringWidth(GxtChar *pCharacters, u8 bIncludeSpaces, u8 bUsingWithScriptValues, u8 isAscii)
    {
        return GetStringWidth2(pCharacters, bIncludeSpaces, bUsingWithScriptValues, isAscii);
    }
    static inline void SetOutlinePosition(i8 amount)
    {
        SetEdge(amount);
    }
    static inline void SetWrapX(float x)
    {
        SetWrapx(x);
    }
    static inline void PrintString(float x, float y, GxtChar *pCharacters)
    {
        PrintString1(x, y, pCharacters);
    }
    static inline void PrintString(float x, float y, const char* txt)
    {
        //memset(tmpString, 0, sizeof(tmpString));
        AsciiToGxtChar(txt, &tmpString[0]);
        PrintString1(x, y, tmpString);
    }
    static inline void SetScale(float fHeight)
    {
        SetScale1(fHeight);
    }
    static inline void SetScale(float x, float y)
    {
        Details().ScaleX = x;
        Details().ScaleY = y;
    }
    static inline void PCSetFontStyle(u8 style)
    {
        u8 bakRussian = UsingRussianLanguage();
        UsingRussianLanguage() = false;
        SetFontStyle(style);
        UsingRussianLanguage() = bakRussian;
    }

    // STATIC values
    //DECL_VALUE_PLT_U8(NewLine, BYBIT(0x, 0x));
    //DECL_VALUE_PLT_U8(PS2Symbol, BYBIT(0x, 0x));
    DECL_OBJECT_PLT(CFontDetails, Details, BYBIT(0x6797F4, 0x850FF0) );
    DECL_OBJECT_PLT(CFontRenderState, RenderState, BYBIT(0x6792E8, 0x8505E8) );
    //DECL_VALUE_PLT_U8(Sprite, BYBIT(0x, 0x));
    //DECL_VALUE_PLT_U8(PS2Sprite, BYBIT(0x, 0x));
    //DECL_VALUE_PLT_U8(Size, BYBIT(0x, 0x));
    DECL_VALUE_PLT_U8(UsingJapaneseLanguage, BYBIT(0x677838, 0x84D098));
    DECL_VALUE_PLT_U8(UsingRussianLanguage, BYBIT(0x678730, 0x84EE88));
    DECL_VALUE_PLT_U8(UsingKoreanLanguage, BYBIT(0x679158, 0x8502D8));
    DECL_VALUE_PLT_U8(UsingEFIGSLanguage, BYBIT(0x679CF0, 0x8519F8));
DECL_CLASS_END()

#define Details Details()
#define RenderState RenderState()
#define UsingJapaneseLanguage UsingJapaneseLanguage()
#define UsingRussianLanguage UsingRussianLanguage()
#define UsingKoreanLanguage UsingKoreanLanguage()
#define UsingEFIGSLanguage UsingEFIGSLanguage()

#endif // __AML_PSDK_SAFONT_H