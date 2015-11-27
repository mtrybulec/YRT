#include <math.h>

#include "YRTScene.h"
#include "YRTTriangle.h"
#include "YRTUtils.h"

#pragma hdrstop

TYRTScene::TYRTScene(void)
{
    _shapes = new TObjectList();
}

TYRTScene::~TYRTScene(void)
{
    delete _shapes;
}

void TYRTScene::GenerateExample_01Triangles(int width, int height)
{
    TYRTTriangle *triangle;

    _shapes->Clear();

    float y = width / 12;
    float z = width / 6;

    // Plane:
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(0, y, z);
    triangle->Points[1] = TYRTVector(width, y, z);
    triangle->Points[2] = TYRTVector(0, y, z + width);
    triangle->Color = (TColor)RGB(0, 0, 255);
    _shapes->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(width, y, z + width);
    triangle->Points[1] = TYRTVector(width, y, z);
    triangle->Points[2] = TYRTVector(0, y, z + width);
    triangle->Color = (TColor)RGB(255, 0, 0);
    _shapes->Add(triangle);

    // Crown:
    const int count = 12;
    for (int i = 0; i < count; i++)
    {
        float h = 100 + (rand() * 1.0 / RAND_MAX) * height * 2 / 3;
        float r = width / 3;

        triangle = new TYRTTriangle;

        triangle->Points[0].X = width / 2 + r * sin(i * 2 * PI / count + PI / count / 4);
        triangle->Points[0].Y = y + 0;
        triangle->Points[0].Z = z + width / 2 + r * cos(i * 2 * PI / count + PI / count / 4);

        triangle->Points[1].X = width / 2 + r * sin((i + 1) * 2 * PI / count - PI / count / 4);
        triangle->Points[1].Y = y + 0;
        triangle->Points[1].Z = z + width / 2 + r * cos((i + 1) * 2 * PI / count - PI / count / 4);

        triangle->Points[2].X = width / 2 + (r + h / 8) * sin(i * 2 * PI / count + PI / count);
        triangle->Points[2].Y = y + h;
        triangle->Points[2].Z = z + width / 2 + (r + h / 8) * cos(i * 2 * PI / count + PI / count);

        triangle->Color = (TColor)RGB(0, i * 255 / count, 0);

        _shapes->Add(triangle);
    }
}

int TYRTScene::GetCount(void)
{
    if (_shapes)
        return _shapes->Count;
    else
        return 0;
}

TYRTShape* TYRTScene::GetShape(int index)
{
    if (_shapes)
        if ((index >= 0) && (index < _shapes->Count))
            return (TYRTShape*)_shapes->Items[index];
        else
            return NULL;
    else
        return NULL;
}

