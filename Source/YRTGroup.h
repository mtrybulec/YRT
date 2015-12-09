#ifndef YRTGroupH
#define YRTGroupH

#include "YRTShape.h"

class TYRTGroup : public TYRTShape
{
private:
    TObjectList *_shapes;
public:
    __fastcall TYRTGroup(void);
    __fastcall ~TYRTGroup(void);
    void Add(TYRTShape *shape);
    void Clear();
    int GetCount(void);
    virtual bool GetIntersection(TYRTRay *ray, TYRTVector &point, TColor &color);
    TYRTShape* GetShape(int index);
    virtual void Move(float dx, float dy, float dz);
    virtual void RunPrecalculations(void);
    virtual void Zoom(float factor);
};

#endif
