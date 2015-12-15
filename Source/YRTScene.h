#ifndef YRTSceneH
#define YRTSceneH

#include <Contnrs.hpp>

#include "YRTShape.h"

class TYRTScene
{
private:
    TYRTShape *_shape;
    TYRTShape* GenerateExample_01Triangles(int width, int height);
    TYRTShape* GenerateExample_02Atom(int width, int height);
    TYRTShape* GenerateExample_03StarShip(float x, float y, float z);
    TYRTShape* GenerateExample_03StarShips(int width, int height);
public:
    ~TYRTScene(void);
    TStrings* GenerateExamples(int width, int height);
    void GetIntersection(TYRTRay *ray, TColor &color);
    void RunPrecalculations(void);
    void SetShape(TYRTShape *shape);
};

#endif
