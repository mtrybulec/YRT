#include <math.h>

#include "YRTTriangle.h"
#include "YRTUtils.h"

#pragma hdrstop

bool TYRTTriangle::GetIntersection(TYRTRay *ray, TYRTVector *point, TColor *color)
{
    if (_isDegenerate)
        return false;

    // Note: if the following instruction is moved down, we lose about 5% on speed...
    TYRTVector w0 = ray->Start - Points[0];

    // Check if the ray is parallel to the triangle plane:
    float b = dot(_norm, ray->Dir);
    if (fabs(b) < EPSILON)
        return false;

    // Check if the ray goes away from the triangle:
    float a = -dot(_norm, w0);
    if((a < 0 && b > 0) || (a > 0 && b < 0))
        return false;

    // The intersection point of the ray with the triangle plane:
    *point = ray->Start + (a / b * ray->Dir);

    // Check whether APoint is inside the triangle - get and test parametric coordinates:
    TYRTVector w = *point - Points[0];

    float wu = dot(w, _u);
    float wv = dot(w, _v);
    float s = (_uv * wv - _vv * wu);
    
    if (_d >= 0)
    {
        if (s < 0.0 || s > _d)
            return false;
        float t = (_uv * wu - _uu * wv);
        if (t < 0.0 || (s + t) > _d)
            return false;
    }
    else
    {
        if (s > 0.0 || s < _d)
            return false;
        float t = (_uv * wu - _uu * wv);
        if (t > 0.0 || (s + t) < _d)
            return false;
    }

    *color = this->Color;
    return true;
}

void TYRTTriangle::RunPrecalculations(void)
{
    // Get triangle edge vectors and the plane normal:
    _u = Points[1] - Points[0];
    _v = Points[2] - Points[0];

    _norm = _u * _v;
    _isDegenerate = _norm.IsNearZero();

    _uu = dot(_u, _u);
    _uv = dot(_u, _v);
    _vv = dot(_v, _v);

    _d = _uv * _uv - _uu * _vv;
}

