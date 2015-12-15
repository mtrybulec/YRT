#ifndef YRTMainH
#define YRTMainH

#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>

#include "YRTEngine.h"
#include "YRTScene.h"
#include <ComCtrls.hpp>

class TYRTMainForm : public TForm
{
__published:
    TPanel *ScenePanel;
    TImage *SceneImage;
    TButton *RenderButton;
    TGroupBox *AntiAliasingGroupBox;
    TLabel *AntiAliasingXLabel;
    TEdit *AntiAliasingXEdit;
    TUpDown *AntiAliasingXUpDown;
    TLabel *AntiAliasingYLabel;
    TEdit *AntiAliasingYEdit;
    TUpDown *AntiAliasingYUpDown;
    TLabel *ExamplesLabel;
    TComboBox *ExamplesComboBox;
    TLabel *TimeLabel;
    TProgressBar *ProgressBar;
    void __fastcall FormCreate(TObject *sender);
    void __fastcall RenderButtonClick(TObject *sender);
private:
    TYRTEngine _engine;
    TYRTScene _scene;
    TStrings* _scenes;
    int _selectedSceneIndex;
    Graphics::TBitmap *_bitmap;
    TDateTime _startTime, _endTime;
    TDateTime GetRenderTime(void);
    bool _isRendering;
    void __fastcall RenderingDone(TObject* sender);
    void UpdateProgress(int y);
    void UpdateWindow(void);
public:
    __fastcall TYRTMainForm(TComponent* owner);
};

extern PACKAGE TYRTMainForm *YRTMainForm;

#endif
