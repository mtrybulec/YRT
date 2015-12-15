#include <math.h>

#include "YRTGroup.h"
#include "YRTScene.h"
#include "YRTSphere.h"
#include "YRTTriangle.h"
#include "YRTUtils.h"

#pragma hdrstop

TYRTScene::~TYRTScene(void)
{
    delete _shape;
}

TYRTShape* TYRTScene::GenerateExample_01Triangles(int width, int height)
{
    TYRTGroup *result = new TYRTGroup;
    TYRTTriangle *triangle;

    float y = width / 12;
    float z = width / 6;

    // Plane:
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(0, y, z);
    triangle->Points[1] = TYRTVector(width, y, z);
    triangle->Points[2] = TYRTVector(0, y, z + width);
    triangle->Color = (TColor)RGB(0, 0, 255);
    result->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(width, y, z + width);
    triangle->Points[1] = TYRTVector(width, y, z);
    triangle->Points[2] = TYRTVector(0, y, z + width);
    triangle->Color = (TColor)RGB(255, 0, 0);
    result->Add(triangle);

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

        result->Add(triangle);
    }

    return result;
}

TYRTShape* TYRTScene::GenerateExample_02Atom(int width, int height)
{
    TYRTGroup *result = new TYRTGroup;
    TYRTSphere *sphere;

    sphere = new TYRTSphere;
    sphere->Center = TYRTVector(0, 0, 0);
    sphere->Radius = 10;
    sphere->Color = clBlue;
    result->Add(sphere);

    sphere = new TYRTSphere;
    sphere->Center = TYRTVector(-5, -5, -3);
    sphere->Radius = 6;
    sphere->Color = clRed;
    result->Add(sphere);

    sphere = new TYRTSphere;
    sphere->Center = TYRTVector(+5, -5, +3);
    sphere->Radius = 6;
    sphere->Color = clRed;
    result->Add(sphere);

    // Zoom/move elements into view:
    result->Zoom(10);
    result->Move(width / 2, height / 2, 0);

    return result;
}

TYRTShape* TYRTScene::GenerateExample_03Starship(float x, float y, float z)
{
    float deckHeight = 0.1;
    float epsilon = 0.01;
    TYRTGroup *result = new TYRTGroup;
    TYRTTriangle *triangle;
    TYRTSphere *sphere;

    // Bottom:
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector( 0, -1,   0);
    triangle->Points[1] = TYRTVector(-3,  0,  -1);
    triangle->Points[2] = TYRTVector( 0,  0, -10);
    triangle->Color = (TColor)RGB(190, 190, 190);
    triangle->Move(0, -deckHeight, 0);
    result->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(0, -1,   0);
    triangle->Points[1] = TYRTVector(3,  0,  -1);
    triangle->Points[2] = TYRTVector(0,  0, -10);
    triangle->Color = (TColor)RGB(190, 190, 190);
    triangle->Move(0, -deckHeight, 0);
    result->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector( 0,  0,   0);
    triangle->Points[1] = TYRTVector(-3,  0,  -1);
    triangle->Points[2] = TYRTVector( 0,  0, -10);
    triangle->Color = (TColor)RGB(190, 190, 190);
    triangle->Move(0, -deckHeight, 0);
    result->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(0,  0,   0);
    triangle->Points[1] = TYRTVector(3,  0,  -1);
    triangle->Points[2] = TYRTVector(0,  0, -10);
    triangle->Color = (TColor)RGB(190, 190, 190);
    triangle->Move(0, -deckHeight, 0);
    result->Add(triangle);
    // Top:
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector( 0, 1,   0);
    triangle->Points[1] = TYRTVector(-3, 0,  -1);
    triangle->Points[2] = TYRTVector( 0, 0, -10);
    triangle->Color = (TColor)RGB(190, 190, 190);
    triangle->Move(0, deckHeight, 0);
    result->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(0, 1,   0);
    triangle->Points[1] = TYRTVector(3, 0,  -1);
    triangle->Points[2] = TYRTVector(0, 0, -10);
    triangle->Color = (TColor)RGB(190, 190, 190);
    triangle->Move(0, deckHeight, 0);
    result->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector( 0, 0,   0);
    triangle->Points[1] = TYRTVector(-3, 0,  -1);
    triangle->Points[2] = TYRTVector( 0, 0, -10);
    triangle->Color = (TColor)RGB(190, 190, 190);
    triangle->Move(0, deckHeight, 0);
    result->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(0, 0,   0);
    triangle->Points[1] = TYRTVector(3, 0,  -1);
    triangle->Points[2] = TYRTVector(0, 0, -10);
    triangle->Color = (TColor)RGB(190, 190, 190);
    triangle->Move(0, deckHeight, 0);
    result->Add(triangle);
    // Sides:
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(-3.0 + 1.0/6, -deckHeight,   -1.0);
    triangle->Points[1] = TYRTVector(-3.0 + 1.0/6,  deckHeight,   -1.0);
    triangle->Points[2] = TYRTVector(           0,  deckHeight, -9.444);
    triangle->Color = (TColor)RGB(127, 127, 127);
    result->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(-3.0 + 1.0/6, -deckHeight,   -1.0);
    triangle->Points[1] = TYRTVector(           0,  deckHeight, -9.444);
    triangle->Points[2] = TYRTVector(           0, -deckHeight, -9.444);
    triangle->Color = (TColor)RGB(127, 127, 127);
    result->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector( 3.0 - 1.0/6, -deckHeight,   -1.0);
    triangle->Points[1] = TYRTVector( 3.0 - 1.0/6,  deckHeight,   -1.0);
    triangle->Points[2] = TYRTVector(           0,  deckHeight, -9.444);
    triangle->Color = (TColor)RGB(127, 127, 127);
    result->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector( 3.0 - 1.0/6, -deckHeight,   -1.0);
    triangle->Points[1] = TYRTVector(           0,  deckHeight, -9.444);
    triangle->Points[2] = TYRTVector(           0, -deckHeight, -9.444);
    triangle->Color = (TColor)RGB(127, 127, 127);
    result->Add(triangle);
    // Bridge:
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector(-1.0, 0.0, -1.0);
    triangle->Points[1] = TYRTVector(-0.5, 1.5, -1.0);
    triangle->Points[2] = TYRTVector( 0.5, 1.5, -1.0);
    triangle->Color = (TColor)RGB(127, 127, 127);
    result->Add(triangle);
    triangle = new TYRTTriangle;
    triangle->Points[0] = TYRTVector( 1.0, 0.0, -1.0);
    triangle->Points[1] = TYRTVector(-1.0, 0.0, -1.0);
    triangle->Points[2] = TYRTVector( 0.5, 1.5, -1.0);
    triangle->Color = (TColor)RGB(127, 127, 127);
    result->Add(triangle);
    // Bottom generator:
    sphere = new TYRTSphere;
    sphere->Center = TYRTVector(0, -0.45, -2.5);
    sphere->Radius = 0.5;
    sphere->Color = (TColor)RGB(212, 212, 212);
    result->Add(sphere);
    // Top generators:
    sphere = new TYRTSphere;
    sphere->Center = TYRTVector(-0.5 + 0.1, 1.6, -1.0);
    sphere->Radius = 0.1;
    sphere->Color = (TColor)RGB(190, 190, 190);
    result->Add(sphere);
    sphere = new TYRTSphere;
    sphere->Center = TYRTVector( 0.5 - 0.1, 1.6, -1.0);
    sphere->Radius = 0.1;
    sphere->Color = (TColor)RGB(190, 190, 190);
    result->Add(sphere);

    result->Move(x, y, z);

    return result;
}

TYRTShape* TYRTScene::GenerateExample_03Starships(int width, int height)
{
    TYRTGroup *result = new TYRTGroup;

    result->Add(GenerateExample_03Starship(0, 0, 0));
    result->Add(GenerateExample_03Starship(10, 4, 1));
    result->Add(GenerateExample_03Starship(-1, 6, 14));

    result->Zoom(30);
    result->Move(170, 150, 100);

    return result;
}

TStrings* TYRTScene::GenerateExamples(int width, int height)
{
    TStringList* result = new TStringList;

    result->AddObject("Triangles", GenerateExample_01Triangles(width, height));
    result->AddObject("Atom", GenerateExample_02Atom(width, height));
    result->AddObject("Starships", GenerateExample_03Starships(width, height));

    return result;
}

void TYRTScene::GetIntersection(TYRTRay *ray, TColor &color)
{
    TYRTVector point;
    _shape->GetIntersection(ray, point, color);
}

void TYRTScene::RunPrecalculations(void)
{
    _shape->RunPrecalculations();
}

void TYRTScene::SetShape(TYRTShape *shape)
{
    _shape = shape;
}
