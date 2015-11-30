#include <vcl.h>

#include "YRTUtils.h"

#pragma hdrstop

USEFORM("YRTMain.cpp", YRTMainForm);

WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->Title = title;
        Application->CreateForm(__classid(TYRTMainForm), &YRTMainForm);
         Application->Run();
    }
    catch(Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}

