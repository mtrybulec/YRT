#include <stdlib.h>
#include <vcl.h>

#include "YRTMain.h"
#include "YRTUtils.h"

#pragma hdrstop
#pragma resource "*.dfm"

#define RenderButtonCaption "&Render"

TYRTMainForm *YRTMainForm;


__fastcall TYRTMainForm::TYRTMainForm(TComponent* owner) : TForm(owner)
{
    Caption = title;
}

void __fastcall TYRTMainForm::FormCreate(TObject *sender)
{
    RenderButton->Caption = RenderButtonCaption;
    TimeLabel->Caption = "";

    // Make sure that SceneImage is a bitmap:
    _bitmap = new Graphics::TBitmap();
    _bitmap->Width = SceneImage->Width;
    _bitmap->Height = SceneImage->Height;
    _bitmap->PixelFormat = pf24bit;

    SceneImage->Picture->Assign(_bitmap);
    _isRendering = false;

    // Some examples use randomization to generate shapes:
    randomize();

    _scenes = _scene.GenerateExamples(_bitmap->Width, _bitmap->Height);

    ExamplesComboBox->Items->Assign(_scenes);
    ExamplesComboBox->ItemIndex = 0;
}

TDateTime TYRTMainForm::GetRenderTime(void)
{
    return _endTime - _startTime;
}

void __fastcall TYRTMainForm::RenderButtonClick(TObject *sender)
{
    if (_isRendering)
    {
        if (Application->MessageBox("Rendering in progress.\nStop?", "Confirm", MB_ICONWARNING | MB_YESNO) == ID_YES)
        {
            _engine.Stop();
        }
    }
    else
    {
        _scene.SetShape((TYRTShape*)_scenes->Objects[_selectedSceneIndex]);

        _startTime = TDateTime::CurrentTime();
        RenderButton->Caption = "Cancel";
        RenderButton->Cancel = true;

        _isRendering = true;
        _engine.RenderScene(&_scene, _bitmap,
            StrToInt(AntiAliasingXEdit->Text), StrToInt(AntiAliasingYEdit->Text), UpdateProgress, RenderingDone);
    }
}

void __fastcall TYRTMainForm::RenderingDone(TObject *sender)
{
    UpdateWindow();
    RenderButton->Caption = RenderButtonCaption;
    RenderButton->Cancel = false;
    ProgressBar->Position = ProgressBar->Max;
    MessageBeep(MB_OK);
    _isRendering = false;
}

void TYRTMainForm::UpdateProgress(int y)
{
    int progress = (y * 100.0) / SceneImage->Height;
    UpdateWindow();
    ProgressBar->Position = progress;
}

void TYRTMainForm::UpdateWindow(void)
{
    _endTime = TDateTime::CurrentTime();
    SceneImage->Picture->Assign(_bitmap);
    TimeLabel->Caption =
        "Time: " +
        FormatDateTime("hh:nn:ss.zzz", GetRenderTime());
}

