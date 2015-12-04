#ifndef YRTTracerH
#define YRTTracerH

#include <Graphics.hpp>

#include "YRTScene.h"

typedef void (__closure *TYRTTracerUpdateFunc) (int);

class TYRTTracer : public TThread
{
private:
    TYRTScene *_scene;
    Graphics::TBitmap *_bitmap;
    TYRTRay _eye;
    int _antiAliasingX;
    int _antiAliasingY;
    TYRTTracerUpdateFunc _updateFunc;
    int _progress;
    void __fastcall UpdateProgress();
protected:
    virtual void __fastcall Execute();
public:
    __fastcall TYRTTracer(TYRTScene *scene, Graphics::TBitmap *bitmap,
        TYRTRay eye, int antiAliasingX, int antiAliasingY,
        TYRTTracerUpdateFunc updateFunc);
};

#endif
