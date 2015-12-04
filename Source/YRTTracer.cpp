#include "YRTTracer.h"
#include "YRTUtils.h"

#pragma hdrstop

struct TRGB {
    byte R;
    byte G;
    byte B;
};

__fastcall TYRTTracer::TYRTTracer(TYRTScene *scene, Graphics::TBitmap *bitmap,
    TYRTRay eye, int antiAliasingX, int antiAliasingY,
    TYRTTracerUpdateFunc updateFunc) : TThread(true)
{
    _scene = scene;
    _bitmap = bitmap;
    _eye = eye;
    _antiAliasingX = antiAliasingX;
    _antiAliasingY = antiAliasingY;
    _updateFunc = updateFunc;
}

void __fastcall TYRTTracer::Execute()
{
    int antiAliasingSize = _antiAliasingX * _antiAliasingY;

    for (int y = 0; y < _bitmap->Height; y++)
    {
        TRGB *scanLine = (TRGB*)_bitmap->ScanLine[y];

        for (int x = 0; x < _bitmap->Width; x++)
        {
            int r = 0, g = 0, b = 0;

            for (int ax = 0; ax < _antiAliasingX; ax++)
                for (int ay = 0; ay < _antiAliasingY; ay++)
                {
                    if (Terminated)
                    {
                        return;
                    }

                    // Set the .x and .y components of the ray from the "eye" to the pixel (x, y):
                    _eye.Dir.X = -_eye.Start.X + x + (ax - 0.5) / _antiAliasingX;
                    _eye.Dir.Y = +_eye.Start.Y - y - (ay - 0.5) / _antiAliasingY;

                    // Get the color of the closest object in the direction of our ray:
                    int colorMin = clBlack;
                    float distMin = MAX_FLOAT;

                    for (int t = 0; t < _scene->GetCount(); t++)
                    {
                        TYRTShape *shape = _scene->GetShape(t);
                        TYRTVector point;
                        TColor color;

                        if (shape->GetIntersection(&_eye, &point, &color))
                        {
                            float dist = _eye.Start.GetDistanceSqr(point);
                            if (dist < distMin)
                            {
                                distMin = dist;
                                colorMin = color;
                            }
                        }
                    }

                    r += (colorMin / 256) / 256;
                    g += (colorMin / 256) % 256;
                    b += colorMin % 256;
                }

            // Draw the pixel in the color of the closest object:
            scanLine[x].R = r / antiAliasingSize;
            scanLine[x].G = g / antiAliasingSize;
            scanLine[x].B = b / antiAliasingSize;
        }

        // Update image:
        if ((_updateFunc != NULL) && (y % 16 == 0))
        {
            _progress = y;
            TThread::Synchronize(&UpdateProgress);
        }
    }
}

void __fastcall TYRTTracer::UpdateProgress()
{
    _updateFunc(_progress);
}

