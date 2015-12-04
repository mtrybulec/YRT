#ifndef YRTEngineH
#define YRTEngineH

#include <Graphics.hpp>

#include "YRTScene.h"
#include "YRTTracer.h"

class TYRTEngine
{
private:
    TYRTTracer* _tracer;
public:
    void RenderScene(TYRTScene *scene, Graphics::TBitmap *bitmap,
        int antiAliasingX, int antiAliasingY,
        TYRTTracerUpdateFunc updateFunc, TNotifyEvent terminatedFunc);
    void Stop();    
};

#endif
