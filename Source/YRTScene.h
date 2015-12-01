#ifndef YRTSceneH
#define YRTSceneH

#include <Contnrs.hpp>

#include "YRTShape.h"

class TYRTScene
{
private:
    TObjectList *_shapes;
public:
    TYRTScene(void);
    ~TYRTScene(void);
    void GenerateExample_01Triangles(int width, int height);
    void GenerateExample_02Atom(int width, int height);
    void GenerateExample_03StarShip(float x, float y, float z);
    void GenerateExample_03StarShips(int width, int height);
    int GetCount(void);
    void Move(float dx, float dy, float dz);
    void Zoom(float factor);
    TYRTShape* GetShape(int index);
};

#endif
