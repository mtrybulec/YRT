#include <math.h>

#include "YRTSphere.h"
#include "YRTUtils.h"

#pragma hdrstop
#pragma package(smart_init)

bool TYRTSphere::GetIntersection(TYRTRay *ray, TYRTVector *point, TColor *color)
{
    TYRTVector temp = ray->Start - Center;
    float a = dot(ray->Dir, ray->Dir);
    float b = 2 * dot(ray->Dir, temp);
    float c = dot(temp, temp) - _radiusSqr;
    float d = sqr(b) - 4 * a * c;

    if (d >= 0)
    {
        d = sqrt(d);
        float t;
        float t1 = -b + d;
        float t2 = -b - d;
        if (t1 < 0 && t2 < 0)
            return false;
        if (t1 < 0)
            t = t2;
        else if (t2 < 0)
            t = t1;
        else
            t = (t1 < t2 ? t1 : t2);

        *point = ray->Start + (t / 2) * ray->Dir;
        *color = Color;

        return true;
    }
    else
        return false;
}

void TYRTSphere::Move(float dx, float dy, float dz)
{
    Center.Move(dx, dy, dz);
}

void TYRTSphere::RunPrecalculations(void)
{
    _radiusSqr = sqr(Radius);
}

void TYRTSphere::Zoom(float factor)
{
    Center.Zoom(factor);
    Radius *= factor;
}
