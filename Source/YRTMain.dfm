object YRTMainForm: TYRTMainForm
  Left = 192
  Top = 163
  ClientHeight = 479
  ClientWidth = 816
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object TimeLabel: TLabel
    Left = 646
    Top = 440
    Width = 49
    Height = 13
    Caption = 'TimeLabel'
    ShowAccelChar = False
  end
  object ProgressBar: TProgressBar
    Left = 646
    Top = 459
    Width = 162
    Height = 17
    Smooth = True
    TabOrder = 3
  end
  object ScenePanel: TPanel
    Left = 0
    Top = 0
    Width = 640
    Height = 479
    BevelOuter = bvNone
    Caption = 'ScenePanel'
    TabOrder = 0
    object SceneImage: TImage
      Left = 0
      Top = 0
      Width = 640
      Height = 479
      Align = alClient
      ExplicitLeft = 504
      ExplicitTop = 232
    end
  end
  object RenderButton: TButton
    Left = 646
    Top = 8
    Width = 162
    Height = 25
    Caption = 'RenderButton'
    TabOrder = 1
    OnClick = RenderButtonClick
  end
  object AntiAliasingGroupBox: TGroupBox
    Left = 646
    Top = 48
    Width = 162
    Height = 81
    Caption = 'Anti-aliasing'
    TabOrder = 2
    object AntiAliasingXLabel: TLabel
      Left = 11
      Top = 23
      Width = 10
      Height = 13
      Caption = '&X:'
      FocusControl = AntiAliasingXEdit
    end
    object AntiAliasingYLabel: TLabel
      Left = 11
      Top = 50
      Width = 10
      Height = 13
      Caption = '&Y:'
      FocusControl = AntiAliasingYEdit
    end
    object AntiAliasingXEdit: TEdit
      Left = 48
      Top = 20
      Width = 83
      Height = 21
      TabOrder = 0
      Text = '1'
    end
    object AntiAliasingXUpDown: TUpDown
      Left = 131
      Top = 20
      Width = 16
      Height = 21
      Associate = AntiAliasingXEdit
      Min = 1
      Max = 5
      Position = 1
      TabOrder = 1
    end
    object AntiAliasingYEdit: TEdit
      Left = 48
      Top = 47
      Width = 83
      Height = 21
      TabOrder = 2
      Text = '1'
    end
    object AntiAliasingYUpDown: TUpDown
      Left = 131
      Top = 47
      Width = 16
      Height = 21
      Associate = AntiAliasingYEdit
      Min = 1
      Max = 5
      Position = 1
      TabOrder = 3
    end
  end
end
