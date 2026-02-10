#ifndef __AML_PSDK_SAWEATHER_H
#define __AML_PSDK_SAWEATHER_H

#include <aml-psdk/game_sa/plugin.h>
#include "../audio/AEAudioEntity.h"

enum eWeatherType
{
    WEATHER_EXTRASUNNY_LA = 0,
    WEATHER_SUNNY_LA = 1,
    WEATHER_EXTRASUNNY_SMOG_LA = 2,
    WEATHER_SUNNY_SMOG_LA = 3,
    WEATHER_CLOUDY_LA = 4,
    WEATHER_SUNNY_SF = 5,
    WEATHER_EXTRASUNNY_SF = 6,
    WEATHER_CLOUDY_SF = 7,
    WEATHER_RAINY_SF = 8,
    WEATHER_FOGGY_SF = 9,
    WEATHER_SUNNY_VEGAS = 10,
    WEATHER_EXTRASUNNY_VEGAS = 11,
    WEATHER_CLOUDY_VEGAS = 12,
    WEATHER_EXTRASUNNY_COUNTRYSIDE = 13,
    WEATHER_SUNNY_COUNTRYSIDE = 14,
    WEATHER_CLOUDY_COUNTRYSIDE = 15,
    WEATHER_RAINY_COUNTRYSIDE = 16,
    WEATHER_EXTRASUNNY_DESERT = 17,
    WEATHER_SUNNY_DESERT = 18,
    WEATHER_SANDSTORM_DESERT = 19,
    WEATHER_UNDERWATER = 20,
    WEATHER_EXTRACOLOURS_1 = 21,
    WEATHER_EXTRACOLOURS_2 = 22
};

enum eWeatherRegion
{
    WEATHER_REGION_DEFAULT = 0,
    WEATHER_REGION_LA = 1,
    WEATHER_REGION_SF = 2,
    WEATHER_REGION_LV = 3,
    WEATHER_REGION_DESERT = 4
};

DECL_CLASS(CWeather)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN8CWeather4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN8CWeather6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(UpdateWeatherRegion, _ZN8CWeather19UpdateWeatherRegionEP7CVector, void, CVector *pCoors);
    DECL_FASTCALL_SIMPLE(FindWeatherTypesList, _ZN8CWeather20FindWeatherTypesListEv, i8*);
    DECL_FASTCALL_SIMPLE(AddRain, _ZN8CWeather7AddRainEv, void);
    DECL_FASTCALL_SIMPLE(UpdateInTunnelness, _ZN8CWeather18UpdateInTunnelnessEv, void);
    DECL_FASTCALL_SIMPLE(ForceWeather, _ZN8CWeather12ForceWeatherEs, void, i16 type);
    DECL_FASTCALL_SIMPLE(ForceWeatherNow, _ZN8CWeather15ForceWeatherNowEs, void, i16 type);
    DECL_FASTCALL_SIMPLE(SetWeatherToAppropriateTypeNow, _ZN8CWeather30SetWeatherToAppropriateTypeNowEv, void);
    DECL_FASTCALL_SIMPLE(ReleaseWeather, _ZN8CWeather14ReleaseWeatherEv, void);
    DECL_FASTCALL_SIMPLE(AddSandStormParticles, _ZN8CWeather21AddSandStormParticlesEv, void);
    DECL_FASTCALL_SIMPLE(RenderRainStreaks, _ZN8CWeather17RenderRainStreaksEv, void);
    DECL_FASTCALL_SIMPLE(ForecastWeather, _ZN8CWeather15ForecastWeatherEii, bool, i32 WeatherType, i32 HoursAhead);

    // STATIC values
    DECL_VALUE_PLT_I32(StreamAfterRainTimer, BYBIT(0x677208, 0x84C448));
    DECL_OBJECT_PLT(CAEWeatherAudioEntity, m_WeatherAudioEntity, BYBIT(0x677644, 0x84CCB8));
    DECL_VALUE_PLT_I16(OldWeatherType, BYBIT(0x677004, 0x84C040));
    DECL_VALUE_PLT_I16(NewWeatherType, BYBIT(0x676E78, 0x84BD30));
    DECL_VALUE_PLT_I16(ForcedWeatherType, BYBIT(0x6788E4, 0x84F1E8));
    DECL_VALUE_PLT_I16(WeatherRegion, BYBIT(0x678778, 0x84EF18));
    DECL_VALUE_PLT_I32(WeatherTypeInList, BYBIT(0x677B78, 0x84D710));
    DECL_VALUE_PLT_FLT(InterpolationValue, BYBIT(0x6783B4, 0x84E780));
    DECL_VALUE_PLT_FLT(WetRoads, BYBIT(0x6771EC, 0x84C410));
    DECL_VALUE_PLT_FLT(CloudCoverage, BYBIT(0x679A1C, 0x851450));
    DECL_VALUE_PLT_FLT(Foggyness, BYBIT(0x679790, 0x850F28));
    DECL_VALUE_PLT_FLT(Foggyness_SF, BYBIT(0x676090, 0x84A190));
    DECL_VALUE_PLT_FLT(ExtraSunnyness, BYBIT(0x678380, 0x84E718));
    DECL_VALUE_PLT_FLT(UnderWaterness, BYBIT(0x67610C, 0x84A278));
    DECL_VALUE_PLT_FLT(WaterDepth, BYBIT(0x677E48, 0x84DCB0));
    DECL_VALUE_PLT_FLT(InTunnelness, BYBIT(0x676C94, 0x84B970));
    DECL_VALUE_PLT_FLT(Rain, BYBIT(0x679F50, 0x851EA8));
    DECL_VALUE_PLT_FLT(Sandstorm, BYBIT(0x678B10, 0x84F648));
    DECL_VALUE_PLT_FLT(Wind, BYBIT(0x67617C, 0x84A358));
    DECL_OBJECT_PLT(CVector, WindDir, BYBIT(0x678C48, 0x84F8B8));
    DECL_VALUE_PLT_FLT(WindClipped, BYBIT(0x67923C, 0x850498));
    DECL_VALUE_PLT_FLT(Wavyness, BYBIT(0x676A68, 0x84B518));
    DECL_VALUE_PLT_FLT(Rainbow, BYBIT(0x6764EC, 0x84AA30));
    DECL_VALUE_PLT_FLT(SunGlare, BYBIT(0x6760A8, 0x84A1C0));
    DECL_VALUE_PLT_FLT(HeatHaze, BYBIT(0x6766F4, 0x84AE40));
    DECL_VALUE_PLT_FLT(HeatHazeFXControl, BYBIT(0x676C0C, 0x84B860));
    DECL_VALUE_PLT_FLT(WaterFogFXControl, BYBIT(0x6781A4, 0x84E360));
    DECL_VALUE_PLT_FLT(HeadLightsSpectrum, BYBIT(0x676FE0, 0x84BFF8));
    DECL_VALUE_PLT_BOOL(LightningBurst, BYBIT(0x678318, 0x84E648));
    DECL_VALUE_PLT_BOOL(LightningFlash, BYBIT(0x6779E0, 0x84D3E8));
    DECL_VALUE_PLT_U32(LightningStart, BYBIT(0x6770AC, 0x84C190));
    DECL_VALUE_PLT_U32(LightningDuration, BYBIT(0x678500, 0x84EA18));
    DECL_VALUE_PLT_U32(WhenToPlayLightningSound, BYBIT(0x679578, 0x850B00));
    DECL_VALUE_PLT_U32(LightningFlashLastChange, BYBIT(0x677160, 0x84C2F8));
    DECL_VALUE_PLT_I32(LightningStartX, BYBIT(0x679B68, 0x8516F0));
    DECL_VALUE_PLT_I32(LightningStartY, BYBIT(0x679120, 0x850268));
    DECL_VALUE_PLT_I32(CurrentRainParticleStrength, BYBIT(0x677BC4, 0x84D7A8));
    DECL_VALUE_PLT_FLT(Earthquake, BYBIT(0x677C50, 0x84D8C0));
    DECL_VALUE_PLT_BOOL(bScriptsForceRain, BYBIT(0x6798D4, 0x8511C8));
    DECL_VALUE_PLT_FLT(TrafficLightsBrightness, BYBIT(0x6789F0, 0x84F400));
DECL_CLASS_END()

#define StreamAfterRainTimer StreamAfterRainTimer()
#define m_WeatherAudioEntity m_WeatherAudioEntity()
#define OldWeatherType OldWeatherType()
#define NewWeatherType NewWeatherType()
#define ForcedWeatherType ForcedWeatherType()
#define WeatherRegion WeatherRegion()
#define WeatherTypeInList WeatherTypeInList()
#define InterpolationValue InterpolationValue()
#define WetRoads WetRoads()
#define CloudCoverage CloudCoverage()
#define Foggyness Foggyness()
#define Foggyness_SF Foggyness_SF()
#define ExtraSunnyness ExtraSunnyness()
#define UnderWaterness UnderWaterness()
#define WaterDepth WaterDepth()
#define InTunnelness InTunnelness()
#define Rain Rain()
#define Sandstorm Sandstorm()
#define Wind Wind()
#define WindDir WindDir()
#define WindClipped WindClipped()
#define Wavyness Wavyness()
#define Rainbow Rainbow()
#define SunGlare SunGlare()
#define HeatHaze HeatHaze()
#define HeatHazeFXControl HeatHazeFXControl()
#define WaterFogFXControl WaterFogFXControl()
#define HeadLightsSpectrum HeadLightsSpectrum()
#define LightningBurst LightningBurst()
#define LightningFlash LightningFlash()
#define LightningStart LightningStart()
#define LightningDuration LightningDuration()
#define WhenToPlayLightningSound WhenToPlayLightningSound()
#define LightningFlashLastChange LightningFlashLastChange()
#define LightningStartX LightningStartX()
#define LightningStartY LightningStartY()
#define CurrentRainParticleStrength CurrentRainParticleStrength()
#define Earthquake Earthquake()
#define bScriptsForceRain bScriptsForceRain()
#define TrafficLightsBrightness TrafficLightsBrightness()

#endif // __AML_PSDK_SAWEATHER_H