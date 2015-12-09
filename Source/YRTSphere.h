#ifndef YRTSphereH
#define YRTSphereH

#include <vcl.h>

#include "YRTShape.h"

class TYRTSphere : public TYRTShape
{
private:
    float _radiusSqr;
public:
    TColor Color;
    TYRTVector Center;
    float Radius;
    virtual bool GetIntersection(TYRTRay *ray, TYRTVector &point, TColor &color);
    virtual void Move(float dx, float dy, float dz);
    virtual void RunPrecalculations(void);
    virtual void Zoom(float factor);
};

#endif
