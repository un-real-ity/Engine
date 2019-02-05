#pragma once
#include <math.h>
#include <iostream>

struct Vector3
{
public:
    static const float EQUAL_TOLERANCE;
    float x, y, z;

    ///
    /// static functions
    ///

    static Vector3 multiply(const Vector3& v, float k)
    {
        return Vector3(v.x * k, v.y * k, v.z * k);
    }

    static Vector3 multiply(const Vector3& v1, const Vector3& v2)
    {
        return Vector3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
    }

    static Vector3 divide(const Vector3& v, float k)
    {
        return multiply(v, 1 / k);
    }

    static Vector3 divide(const Vector3& v, const Vector3& v2)
    {
        return multiply(v, { 1 / v2.x, 1 / v2.y, 1 / v2.z });
    }

    static Vector3 add(const Vector3& v1, const Vector3& v2)
    {
        return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }

    static Vector3 subtract(const Vector3& v1, const Vector3& v2)
    {
        return add(v1, negate(v2));
    }

    static Vector3 negate(const Vector3& v)
    {
        return multiply(v, -1);
    }

    static Vector3 dot(const Vector3& v1, const Vector3& v2)
    {
        return Vector3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
    }

    static Vector3 cross(const Vector3& v1, const Vector3& v2)
    {
        return Vector3(v1.y * v2.z - v1.z * v2.y,
            v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x);
    }

    static Vector3 normalize(const Vector3& v)
    {
        return divide(v, v.length());
    }

    static Vector3 lerp(const Vector3& v1, const Vector3& v2, float alpha)
    {
        return v1*(1 - alpha) + v2*alpha;
    }

    static bool equals(const Vector3& v1, const Vector3& v2)
    {
        return std::abs(v1.x - v2.x) <= EQUAL_TOLERANCE &&
            std::abs(v1.y - v2.y) <= EQUAL_TOLERANCE &&
            std::abs(v1.z - v2.z) <= EQUAL_TOLERANCE;
    }

    ///
    /// member functions
    ///

    Vector3(float x_, float y_, float z_)
        : x(x_), y(y_), z(z_) {}

    Vector3(float k_)
        : x(k_), y(k_), z(k_) {}

    float lengthSq() const
    {
        return x * x + y * y + z * z;
    }

    float length() const
    {
        return sqrt(lengthSq());
    }

    ///
    /// operators
    ///
    Vector3 operator*(const Vector3& v) const
    {
        return Vector3::multiply(*this, v);
    }

    Vector3 operator*(float k) const
    {
        return Vector3::multiply(*this, k);
    }

    Vector3 operator/(const Vector3& v) const
    {
        return Vector3::divide(*this, v);
    }

    Vector3 operator/(float k) const
    {
        return Vector3::divide(*this, k);
    }

    Vector3 operator+(const Vector3& v) const
    {
        return Vector3::add(*this, v);
    }

    Vector3 operator-(const Vector3& v) const
    {
        return Vector3::subtract(*this, v);
    }

    Vector3 operator-() const
    {
        return Vector3::negate(*this);
    }

    Vector3 operator|(const Vector3& v) const
    {
        return Vector3::dot(*this, v);
    }

    Vector3 operator^(const Vector3& v) const
    {
        return Vector3::cross(*this, v);
    }

    Vector3 operator!()
    {
        return Vector3::normalize(*this);
    }

    bool operator==(const Vector3& v) const
    {
        return Vector3::equals(*this, v);
    }

    bool operator!=(const Vector3& v) const
    {
        return !(*this == v);
    }
};

const float Vector3::EQUAL_TOLERANCE = 1e-4f;

Vector3 operator*(float k, Vector3 v)
{
    return v * k;
}

std::ostream& operator<<(std::ostream& stream, const Vector3& v)
{
    return stream << '(' << v.x << ',' << v.y << ',' << v.z << ')';
}