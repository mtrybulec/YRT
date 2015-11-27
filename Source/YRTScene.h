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
    int GetCount(void);
    TYRTShape* GetShape(int index);
};

#endif
