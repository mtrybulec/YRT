#include <math.h>

#include "YRTScene.h"
#include "YRTSphere.h"
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

void TYRTScene::Clear()
{
    _shapes->Clear();
}

void TYRTScene::GenerateExample_01Triangles(int width, int height)
{
    TYRTTriangle *triangle;

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

void TYRTScene::GenerateExample_02Atom(int width, int height)
{
    TYRTSphere *sphere;

    sphere = new TYRTSphere;
    sphere->Center = TYRTVector(0, 0, 0);
    sphere->Radius = 10;
    sphere->Color = clBlue;
    _shapes->Add(sphere);

    sphere = new TYRTSphere;
    sphere->Center = TYRTVector(-5, -5, -3);
    sphere->Radius = 6;
    sphere->Color = clRed;
    _shapes->Add(sphere);

    sphere = new TYRTSphere;
    sphere->Center = TYRTVector(+5, -5, +3);
    sphere->Radius = 6;
    sphere->Color = clRed;
    _shapes->Add(sphere);

    // Zoom/move elements into view:
    Zoom(10);
    Move(width / 2, height / 2, 0);
}

void TYRTScene::GenerateExample_03StarShip(float x, float y, float z)
{
    TYRTTriangle *triangle;
    TYRTSphere *sphere;
    int index = _shapes->Count;

    // Bottom:
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector( 0, -1,   0);
    triangle->Points[1] = TYRTVector(-3,  0,  -1);
    triangle->Points[2] = TYRTVector( 0,  0, -10);
    triangle->Color = (TColor)RGB(190, 190, 190);
    _shapes->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(0, -1,   0);
    triangle->Points[1] = TYRTVector(3,  0,  -1);
    triangle->Points[2] = TYRTVector(0,  0, -10);
    triangle->Color = (TColor)RGB(190, 190, 190);
    _shapes->Add(triangle);
    // Top:
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector( 0, 1,   0);
    triangle->Points[1] = TYRTVector(-3, 0,  -1);
    triangle->Points[2] = TYRTVector( 0, 0, -10);
    triangle->Color = (TColor)RGB(190, 190, 190);
    triangle->Move(0, 0.1, 0);
    _shapes->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(0, 1,   0);
    triangle->Points[1] = TYRTVector(3, 0,  -1);
    triangle->Points[2] = TYRTVector(0, 0, -10);
    triangle->Color = (TColor)RGB(190, 190, 190);
    triangle->Move(0, 0.1, 0);
    _shapes->Add(triangle);
    // Sides:
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(-3.0 + 1.0/6, 0.0 - 1.0/18, -1.0);
    triangle->Points[1] = TYRTVector(-3.0 + 1.0/6, 0.1 + 1.0/18, -1.0);
    triangle->Points[2] = TYRTVector(           0,            0, -9.5);
    triangle->Color = (TColor)RGB(127, 127, 127);
    _shapes->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(-3.0 + 1.0/6, 0.1 + 1.0/18, -1.0);
    triangle->Points[1] = TYRTVector(           0,          0.1, -9.5);
    triangle->Points[2] = TYRTVector(           0,          0.0, -9.5);
    triangle->Color = (TColor)RGB(127, 127, 127);
    _shapes->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector( 3.0 - 1.0/6, 0.0 - 1.0/18, -1.0);
    triangle->Points[1] = TYRTVector( 3.0 - 1.0/6, 0.1 + 1.0/18, -1.0);
    triangle->Points[2] = TYRTVector(           0,            0, -9.5);
    triangle->Color = (TColor)RGB(127, 127, 127);
    _shapes->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector( 3.0 - 1.0/6, 0.1 + 1.0/18, -1.0);
    triangle->Points[1] = TYRTVector(           0,          0.1, -9.5);
    triangle->Points[2] = TYRTVector(           0,          0.0, -9.5);
    triangle->Color = (TColor)RGB(127, 127, 127);
    _shapes->Add(triangle);
    // Bridge:
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(-1.0, 0.0, -1.0);
    triangle->Points[1] = TYRTVector(-0.5, 1.5, -1.0);
    triangle->Points[2] = TYRTVector( 0.5, 1.5, -1.0);
    triangle->Color = (TColor)RGB(127, 127, 127);
    _shapes->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector( 1.0, 0.0, -1.0);
    triangle->Points[1] = TYRTVector(-1.0, 0.0, -1.0);
    triangle->Points[2] = TYRTVector( 0.5, 1.5, -1.0);
    triangle->Color = (TColor)RGB(127, 127, 127);
    _shapes->Add(triangle);
    // Bottom generator:
    sphere = new TYRTSphere;
    sphere->Center = TYRTVector(0, -0.45, -2.5);
    sphere->Radius = 0.5;
    sphere->Color = (TColor)RGB(212, 212, 212);
    _shapes->Add(sphere);
    // Top generators:
    sphere = new TYRTSphere;
    sphere->Center = TYRTVector(-0.5 + 0.1, 1.6, -1.0);
    sphere->Radius = 0.1;
    sphere->Color = (TColor)RGB(190, 190, 190);
    _shapes->Add(sphere);
    sphere = new TYRTSphere;
    sphere->Center = TYRTVector( 0.5 - 0.1, 1.6, -1.0);
    sphere->Radius = 0.1;
    sphere->Color = (TColor)RGB(190, 190, 190);
    _shapes->Add(sphere);

    for (int i = index; i < _shapes->Count; i++)
    {
        TYRTShape *shape = (TYRTShape*)_shapes->Items[i];
        shape->Move(x, y, z);
    }
}

void TYRTScene::GenerateExample_03StarShips(int width, int height)
{
    GenerateExample_03StarShip(0, 0, 0);
    GenerateExample_03StarShip(10, 4, 1);
    GenerateExample_03StarShip(-1, 6, 14);

    for (int i = 0; i < _shapes->Count; i++)
    {
        TYRTShape *shape = (TYRTShape*)_shapes->Items[i];
        shape->Zoom(30);
        shape->Move(170, 150, 100);
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

void TYRTScene::Move(float dx, float dy, float dz)
{
    for (int i = 0; i < _shapes->Count; i++)
    {
        TYRTShape *shape = (TYRTShape*)_shapes->Items[i];
        shape->Move(dx, dy, dz);
    }
}

void TYRTScene::Zoom(float factor)
{
    for (int i = 0; i < _shapes->Count; i++)
    {
        TYRTShape *shape = (TYRTShape*)_shapes->Items[i];
        shape->Zoom(factor);
    }
}

