#ifndef YRTTracerH
#define YRTTracerH

#include <Graphics.hpp>

#include "YRTEngine.h"
#include "YRTScene.h"

class TYRTTracer : public TThread
{
private:
    TYRTScene *_scene;
    Graphics::TBitmap *_bitmap;
    TYRTRay _eye;
    int _antiAliasingX;
    int _antiAliasingY;
    TYRTEngineUpdateFunc _updateFunc;
    int _progress;
    void __fastcall UpdateProgress();
protected:
    virtual void __fastcall Execute();
public:
    __fastcall TYRTTracer(TYRTScene *scene, Graphics::TBitmap *bitmap,
        TYRTRay eye, int antiAliasingX, int antiAliasingY,
        TYRTEngineUpdateFunc updateFunc);
};

#endif
