#include "vector3.h"

#include <math.h>

Vector3 vector3_add(Vector3 a, Vector3 b)
{
    Vector3 result = {
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
    };
    return result;
}

Vector3 vector3_subtract(Vector3 a, Vector3 b)
{
    Vector3 result = {
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
    };
    return result;
}

Vector3 vector3_multiply(Vector3 a, Vector3 b)
{
    Vector3 result = {
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
    };
    return result;
}

Vector3 vector3_divide(Vector3 a, Vector3 b)
{
    Vector3 result = {
        a.x / b.x,
        a.y / b.y,
        a.z / b.z,
    };
    return result;
}

Vector3 vector3_cross(Vector3 a, Vector3 b)
{
    Vector3 result = {
        a.y * b.z - b.y * a.z,
        a.z * b.x - b.z * a.x,
        a.x * b.y - b.x * a.y,
    };
    return result;
}

Vector3 vector3_multiply_scalar(Vector3 v, f32 s)
{
    Vector3 result = {
        v.x * s,
        v.y * s,
        v.z * s,
    };
    return result;
}

f32 vector3_dot(Vector3 a, Vector3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

f32 vector3_length(Vector3 v)
{
    return sqrtf(vector3_dot(v, v));
}

Vector3 vector3_normalized(Vector3 v)
{
    f32 len = vector3_length(v);
    if (len != 0.0f)
    {
        return vector3_multiply_scalar(v, 1.0f / len);
    }
    return v;
}

f32 vector3_distance(Vector3 a, Vector3 b)
{
    return vector3_length(vector3_subtract(a, b));
}