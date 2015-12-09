#include "YRTGroup.h"
#include "YRTUtils.h"

#pragma hdrstop
#pragma package(smart_init)

__fastcall TYRTGroup::TYRTGroup(void)
{
    _shapes = new TObjectList();
}

__fastcall TYRTGroup::~TYRTGroup(void)
{
    delete _shapes;
}

void TYRTGroup::Add(TYRTShape *shape)
{
    _shapes->Add(shape);
}

void TYRTGroup::Clear()
{
    _shapes->Clear();
}

int TYRTGroup::GetCount(void)
{
    return _shapes->Count;
}

bool TYRTGroup::GetIntersection(TYRTRay *ray, TYRTVector &point, TColor &color)
{
    bool result = false;
    float distanceSqrMin = MAX_FLOAT;

    for (int i = 0; i < GetCount(); i++)
    {
        TYRTShape *shape = GetShape(i);
        TYRTVector shapePoint;
        TColor shapeColor;

        if (shape->GetIntersection(ray, shapePoint, shapeColor))
        {
            float shapeDistanceSqr = ray->Start.GetDistanceSqr(shapePoint);

            if (shapeDistanceSqr < distanceSqrMin)
            {
                distanceSqrMin = shapeDistanceSqr;
                point = shapePoint;
                color = shapeColor;
                result = true;
            }
        }
    }

    return result;
}

TYRTShape* TYRTGroup::GetShape(int index)
{
    return (TYRTShape*)_shapes->Items[index];
}

void TYRTGroup::Move(float dx, float dy, float dz)
{
    for (int i = 0; i < GetCount(); i++)
    {
        GetShape(i)->Move(dx, dy, dz);
    }
}

void TYRTGroup::RunPrecalculations(void)
{
    for (int i = 0; i < GetCount(); i++)
    {
        GetShape(i)->RunPrecalculations();
    }
}

void TYRTGroup::Zoom(float factor)
{
    for (int i = 0; i < GetCount(); i++)
    {
        GetShape(i)->Zoom(factor);
    }
}

