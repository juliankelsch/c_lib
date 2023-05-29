#ifndef __C_LIB_VECTOR3_H__
#define __C_LIB_VECTOR3_H__

#include "../common/types.h"

typedef struct Vector3 Vector3;

struct Vector3
{
    f32 x, y, z;
};

Vector3 vector3_add(Vector3 a, Vector3 b);
Vector3 vector3_subtract(Vector3 a, Vector3 b);
Vector3 vector3_multiply(Vector3 a, Vector3 b);
Vector3 vector3_divide(Vector3 a, Vector3 b);
Vector3 vector3_cross(Vector3 a, Vector3 b);
Vector3 vector3_multiply_scalar(Vector3 v, f32 s);
f32 vector3_dot(Vector3 a, Vector3 b);
f32 vector3_length(Vector3 v);
Vector3 vector3_normalized(Vector3 v);
f32 vector3_distance(Vector3 a, Vector3 b);

#endif // __C_LIB_VECTOR3_H__
