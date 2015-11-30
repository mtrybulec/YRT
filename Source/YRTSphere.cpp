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
        double t = b - d;
        if (t < 0)
            t = -b - d;
        if (t < 0)
            return false;

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
