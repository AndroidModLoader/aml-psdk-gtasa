#ifndef __AML_PSDK_SAVECTOR_H
#define __AML_PSDK_SAVECTOR_H

#include <aml-psdk/sdk_base.h>

struct CVector2D
{
    float x, y;
    CVector2D() : x(0.0f), y(0.0f) {}
    CVector2D(float V) : x(V), y(V) {}
    CVector2D(float X, float Y) : x(X), y(Y) {}

    operator CVector2D*() { return this; }
    inline void operator+=(const CVector2D& right)
    {
        this->x += right.x;
        this->y += right.y;
    }
    inline void operator-=(const CVector2D& right)
    {
        this->x -= right.x;
        this->y -= right.y;
    }
    inline CVector2D& operator*=(const float f)
    {
        this->x *= f;
        this->y *= f;
        return *this;
    }
    inline CVector2D& operator/=(const float f)
    {
        this->x /= f;
        this->y /= f;
        return *this;
    }
    inline CVector2D operator+(const CVector2D& vecTwo) const
    {
        return { x + vecTwo.x, y + vecTwo.y };
    }
    inline CVector2D operator-(const CVector2D& vecTwo) const
    {
        return { x - vecTwo.x, y - vecTwo.y };
    }
    inline CVector2D operator*(const float f) const
    {
        CVector2D result;
        result.x = this->x * f;
        result.y = this->y * f;
        return result;
    }
    inline CVector2D operator/(const float f) const
    {
        CVector2D result;
        result.x = this->x / f;
        result.y = this->y / f;
        return result;
    }
    float& operator[](int i)
    {
        if(i) return this->y; else return this->x;
    }
    float operator[](int i) const
    {
        if(i) return this->y; else return this->x;
    }
};

struct CVector
{
    union
    {
        CVector2D m_vec2D;
        struct { float x, y; };
    };
    float z;

    operator CVector2D&() { return m_vec2D; }
    operator CVector2D*() { return &m_vec2D; }
    operator CVector2D() const { return m_vec2D; }
    operator CVector*() { return this; }
};

#endif // __AML_PSDK_SAVECTOR_H