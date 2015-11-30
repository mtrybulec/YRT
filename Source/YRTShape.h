#ifndef YRTShapeH
#define YRTShapeH

#include <vcl.h>

#include "YRTRay.h"
#include "YRTVector.h"

class TYRTShape : public TObject
{
public:
    virtual bool GetIntersection(TYRTRay *ray, TYRTVector *point, TColor *color) = 0;
    virtual void Move(float dx, float dy, float dz) { };
    virtual void RunPrecalculations(void) { };
    virtual void Zoom(float factor) { };
};

#endif
