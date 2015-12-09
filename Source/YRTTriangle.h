#ifndef YRTTriangleH
#define YRTTriangleH

#include <vcl.h>

#include "YRTShape.h"

class TYRTTriangle : public TYRTShape
{
private:
    bool _isDegenerate;
    TYRTVector _u, _v, _norm;
    float _uu, _uv, _vv, _d;
public:
    TColor Color;
    TYRTVector Points[3];
    virtual bool GetIntersection(TYRTRay *ray, TYRTVector &point, TColor &color);
    virtual void Move(float dx, float dy, float dz);
    virtual void RunPrecalculations(void);
    virtual void Zoom(float factor);
};

#endif
