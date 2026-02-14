#ifndef __AML_PSDK_GTAVECTOR_H
#define __AML_PSDK_GTAVECTOR_H

#include <aml-psdk/sdk_basetypes.h>

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

    inline bool InRange2D(float min, float max)
    {
        return (x <= max && x >= min &&
                y <= max && y >= min);
    }
    inline float Magnitude2D() const
    {
        return sqrtf(MagnitudeSqr2D());
    }
    inline float MagnitudeSqr2D() const
    {
        return SQ(x) + SQ(y);
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

    CVector() : x(0.0f), y(0.0f), z(0.0f) {}
    CVector(float V) : x(V), y(V), z(V) {}
    CVector(float X, float Y, float Z) : x(X), y(Y), z(Z) {}

    inline void operator+=(const CVector& right)
    {
        this->x += right.x;
        this->y += right.y;
        this->z += right.z;
    }
    inline void operator-=(const CVector& right)
    {
        this->x -= right.x;
        this->y -= right.y;
        this->z -= right.z;
    }
    inline CVector& operator*=(const float f)
    {
        this->x *= f;
        this->y *= f;
        this->z *= f;
        return *this;
    }
    inline CVector& operator/=(const float f)
    {
        this->x /= f;
        this->y /= f;
        this->z /= f;
        return *this;
    }
    inline CVector operator+(const CVector& vecTwo) const
    {
        return { x + vecTwo.x, y + vecTwo.y, z + vecTwo.z };
    }
    inline CVector operator-(const CVector& vecTwo) const
    {
        return { x - vecTwo.x, y - vecTwo.y, z - vecTwo.z };
    }
    inline CVector operator*(const float f) const
    {
        CVector result;
        result.x = this->x * f;
        result.y = this->y * f;
        result.z = this->z * f;
        return result;
    }
    inline CVector operator/(const float f) const
    {
        CVector result;
        result.x = this->x / f;
        result.y = this->y / f;
        result.z = this->z / f;
        return result;
    }
    float& operator[](int i)
    {
        if(i == 2) return this->z; else if(i) return this->y; else return this->x;
    }
    float operator[](int i) const
    {
        if(i == 2) return this->z; else if(i) return this->y; else return this->x;
    }

    operator CVector2D&() { return m_vec2D; }
    operator CVector2D*() { return &m_vec2D; }
    operator CVector2D() const { return m_vec2D; }
    operator CVector*() { return this; }

    inline bool InRange2D(float min, float max)
    {
        return (x <= max && x >= min &&
                y <= max && y >= min);
    }
    inline bool InRange(float min, float max)
    {
        return (x <= max && x >= min &&
                y <= max && y >= min &&
                z <= max && z >= min);
    }
    inline float DistSqr2D(CVector& v)
    {
        return (*this - v).MagnitudeSqr2D();
    }
    inline float Dist2D(CVector& v)
    {
        return sqrtf(DistSqr2D(v));
    }
    inline float DistSqr(CVector& v)
    {
        return (*this - v).MagnitudeSqr();
    }
    inline float Dist(CVector& v)
    {
        return sqrtf(DistSqr(v));
    }
    inline CVector Abs()
    {
        return { fabsf(x), fabsf(y), fabsf(z) };
    }
    inline bool IsNormalized()
    {
        return InRange(-1.0f, 1.0f);
    }
    inline void Normalise()
    {
        float lenSq = SQ(x) + SQ(y) + SQ(z);
        if(lenSq < FLT_EPSILON)
        {
            x = 1.0f;
            return;
        }
        float invsqrt = 1.0f / sqrtf(lenSq);
        x *= invsqrt;
        y *= invsqrt;
        z *= invsqrt;
    }
    inline float NormaliseAndMag()
    {
        float lenSq = SQ(x) + SQ(y) + SQ(z);
        if(lenSq < FLT_EPSILON)
        {
            x = 1.0f;
            return x;
        }
        float lenSqrt = sqrtf(lenSq);
        float invsqrt = 1.0f / lenSqrt;
        x *= invsqrt;
        y *= invsqrt;
        z *= invsqrt;
        return lenSqrt;
    }
    inline float Magnitude() const
    {
        return sqrtf(MagnitudeSqr());
    }
    inline float Magnitude2D() const
    {
        return sqrtf(MagnitudeSqr2D());
    }
    inline float MagnitudeSqr() const
    {
        return SQ(x) + SQ(y) + SQ(z);
    }
    inline float MagnitudeSqr2D() const
    {
        return SQ(x) + SQ(y);
    }
    inline CVector Cross(const CVector& o) const
    {
        return
        {
            y * o.z - z * o.y,
            z * o.x - x * o.z,
            x * o.y - y * o.x
        };
    }
    inline void Cross(const CVector& a, const CVector& b)
    {
        *this = a.Cross(b);
    }
    inline CVector Normalized() const
    {
        CVector ret = *this;
        ret.Normalise();
        return ret;
    }
};

const CVector vectorNull(0, 0, 0);
const CVector vectorAxisX(1, 0, 0);
const CVector vectorAxisY(0, 1, 0);
const CVector vectorAxisZ(0, 0, 1);

struct CompressedVector2D
{
    CompressedVector2D() { Set(0, 0); }
    CompressedVector2D(short X, short Y) { Set(X, Y); }
    short x, y;
    
    inline void Set(short X, short Y)
    {
        x = X;
        y = Y;
    }
    inline void Set(CVector2D const& vec, float resolution = 8.0f)
    {
        x = vec.x * resolution;
        y = vec.y * resolution;
    }
    inline CVector2D Uncompress(float resolution)
    {
        return CVector2D((float)x / resolution, (float)y / resolution);
    }
    inline CVector2D Uncompressed()
    {
        return Uncompress(8.0f);
    }
    inline void Uncompress(CVector2D& out)
    {
        out = Uncompressed();
    }
};

struct CompressedVector
{
    CompressedVector() { Set(0, 0, 0); }
    CompressedVector(short X, short Y, short Z) { Set(X, Y, Z); }
    union
    {
        CompressedVector2D m_vec2D;
        struct { short x, y; };
    };
    short z;
    
    inline void Set(short X, short Y, short Z)
    {
        x = X;
        y = Y;
        z = Z;
    }
    inline void Set(CVector const& vec, float resolution = 8.0f)
    {
        x = vec.x * resolution;
        y = vec.y * resolution;
        z = vec.z * resolution;
    }
    inline CVector Uncompress(float resolution)
    {
        return CVector((float)x / resolution, (float)y / resolution, (float)z / resolution);
    }
    inline CVector Uncompressed()
    {
        return Uncompress(8.0f);
    }
    inline void Uncompress(CVector& out)
    {
        out = Uncompressed();
    }
    operator CompressedVector2D&() { return m_vec2D; }
    operator CompressedVector2D*() { return &m_vec2D; }
    operator CompressedVector2D() const { return m_vec2D; }
};

inline float DistanceBetweenPoints(CVector const& v1, CVector const& v2)
{
    return (v1 - v2).Magnitude();
}
inline float DistanceBetweenPoints2D(CVector const& v1, CVector const& v2)
{
    return (v1 - v2).Magnitude2D();
}
inline float DistanceBetweenPoints(CVector2D const& v1, CVector2D const& v2)
{
    return (v1 - v2).Magnitude2D();
}
inline float DistanceBetweenPoints2D(CVector2D const& v1, CVector2D const& v2)
{
    return (v1 - v2).Magnitude2D();
}

#endif // __AML_PSDK_GTAVECTOR_H
