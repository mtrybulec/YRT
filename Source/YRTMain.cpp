#include <stdlib.h>
#include <vcl.h>

#include "YRTMain.h"
#include "YRTUtils.h"

#pragma hdrstop
#pragma resource "*.dfm"

TYRTMainForm *YRTMainForm;

__fastcall TYRTMainForm::TYRTMainForm(TComponent* owner) : TForm(owner)
{
    Caption = title;
}

void __fastcall TYRTMainForm::FormCreate(TObject *sender)
{
    ProgressLabel->Caption = "";
    TimeLabel->Caption = "";

    // Make sure that SceneImage is a bitmap:
    _bitmap = new Graphics::TBitmap();
    _bitmap->Width = SceneImage->Width;
    _bitmap->Height = SceneImage->Height;
    _bitmap->PixelFormat = pf24bit;

    SceneImage->Picture->Assign(_bitmap);

    // Some examples use randomization to generate shapes:
    randomize();
}

TDateTime TYRTMainForm::GetRenderTime(void)
{
    return _endTime - _startTime;
}

void __fastcall TYRTMainForm::RenderButtonClick(TObject *sender)
{
    _scene.GenerateExample_01Triangles(_bitmap->Width, _bitmap->Height);
    _startTime = TDateTime::CurrentTime();

    _engine.RenderScene(&_scene, _bitmap,
        StrToInt(AntiAliasingXEdit->Text), StrToInt(AntiAliasingYEdit->Text), UpdateProgress, RenderingDone);
}

void __fastcall TYRTMainForm::RenderingDone(TObject *sender)
{
    UpdateWindow();
    ProgressLabel->Caption = "DONE";
    MessageBeep(MB_OK);
}

void TYRTMainForm::UpdateProgress(int y)
{
    UpdateWindow();
    ProgressLabel->Caption =
        "Progress: " +
        FloatToStrF((y * 1.0) / SceneImage->Height * 100, ffFixed, 1, 0) + "\%";
}

void TYRTMainForm::UpdateWindow(void)
{
    _endTime = TDateTime::CurrentTime();
    SceneImage->Picture->Assign(_bitmap);
    TimeLabel->Caption =
        "Time: " +
        FormatDateTime("hh:nn:ss.zzz", GetRenderTime());
}

