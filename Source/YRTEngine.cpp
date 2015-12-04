#include "YRTEngine.h"
#include "YRTTracer.h"

#pragma hdrstop

void TYRTEngine::RenderScene(TYRTScene *scene, Graphics::TBitmap *bitmap,
    int antiAliasingX, int antiAliasingY,
    TYRTTracerUpdateFunc updateFunc, TNotifyEvent terminatedFunc)
{
    assert(bitmap->PixelFormat == pf24bit);

    for (int t = 0; t < scene->GetCount(); t++)
    {
        TYRTShape *shape = scene->GetShape(t);
        shape->RunPrecalculations();
    }

    TYRTRay eye;

    // Set the "eye" to be in the mid-point of the screen,
    // but at a distance equal to the width of the screen:
    eye.Start.X = (bitmap->Width) / 2;
    eye.Start.Y = (bitmap->Height) / 2;
    eye.Start.Z = -(bitmap->Width);

    // ray.Dir will point to consecutive pixels of the screen;
    // the .Z component is always equal to the distance of the "eye" from the screen.
    eye.Dir.Z = -eye.Start.Z;

    _tracer = new TYRTTracer(scene, bitmap, eye, antiAliasingX, antiAliasingY, updateFunc);
    _tracer->FreeOnTerminate = true;
    _tracer->OnTerminate = terminatedFunc;
    _tracer->Resume();
}

void TYRTEngine::Stop()
{
    _tracer->Terminate();
}
