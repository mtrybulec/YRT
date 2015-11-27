#ifndef YRTEngineH
#define YRTEngineH

#include <Graphics.hpp>

#include "YRTScene.h"

typedef void (__closure *TYRTEngineUpdateFunc) (int);

class TYRTEngine
{
public:
    void RenderScene(TYRTScene *scene, Graphics::TBitmap *bitmap,
        int antiAliasingX, int antiAliasingY,
        TYRTEngineUpdateFunc updateFunc, TNotifyEvent terminatedFunc);
};

#endif
