#ifndef YRTSceneH
#define YRTSceneH

#include <Contnrs.hpp>

#include "YRTShape.h"

class TYRTScene
{
private:
    TYRTShape *_shape;
public:
    ~TYRTScene(void);
    TYRTShape* GenerateExample_01Triangles(int width, int height);
    TYRTShape* GenerateExample_02Atom(int width, int height);
    TYRTShape* GenerateExample_03StarShip(float x, float y, float z);
    TYRTShape* GenerateExample_03StarShips(int width, int height);
    TStrings* GenerateExamples();
    void GetIntersection(TYRTRay *ray, TColor &color);
    void RunPrecalculations(void);
    void SetShape(TYRTShape *shape);
};

#endif
