#include <math.h>

#include "YRTShape.h"
#include "YRTUtils.h"
#include "YRTVector.h"

#pragma hdrstop

TYRTVector::TYRTVector() : X(0.0f), Y(0.0f), Z(0.0f)
{
}

TYRTVector::TYRTVector(float a) : X(a), Y(a), Z(a)
{
}

TYRTVector::TYRTVector(float x, float y, float z) : X(x), Y(y), Z(z)
{
}

TYRTVector TYRTVector::operator+ (const TYRTVector& arg)
{
    return TYRTVector(X + arg.X, Y + arg.Y, Z + arg.Z);
}

TYRTVector TYRTVector::operator- (const TYRTVector& arg)
{
    return TYRTVector(X - arg.X, Y - arg.Y, Z - arg.Z);
}

TYRTVector TYRTVector::operator* (const TYRTVector& arg)
{
    return TYRTVector(Y * arg.Z - Z * arg.Y, Z * arg.X - X * arg.Z, X * arg.Y - Y * arg.X);
}

float TYRTVector::GetDistance(TYRTVector& arg)
{
    return sqrt(GetDistanceSqr(arg));
}

float TYRTVector::GetDistanceSqr(TYRTVector& arg)
{
    return sqr(X - arg.X) + sqr(Y - arg.Y) + sqr(Z - arg.Z);
}

bool TYRTVector::IsNearZero(void)
{
    return fabs(X) < EPSILON && fabs(Y) < EPSILON && fabs(Z) < EPSILON;
}

bool operator == (const TYRTVector& v1, const TYRTVector& v2)
{
    return (v1.X == v2.X) && (v1.Y == v2.Y) && (v1.Z == v2.Z);
}

TYRTVector operator* (float s, const TYRTVector& arg)
{
    return TYRTVector(arg.X * s, arg.Y * s, arg.Z * s);
}


