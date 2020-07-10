object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Game'
  ClientHeight = 414
  ClientWidth = 909
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 328
    Top = 136
    Width = 141
    Height = 55
    Caption = 'Label1'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label2: TLabel
    Left = 328
    Top = 8
    Width = 171
    Height = 24
    Caption = #1050#1086#1083#1080#1095#1077#1089#1074#1086' '#1093#1086#1076#1086#1074': '
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label3: TLabel
    Left = 496
    Top = 8
    Width = 7
    Height = 24
    Caption = '-'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label4: TLabel
    Left = 216
    Top = 357
    Width = 15
    Height = 19
    Caption = '---'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsItalic]
    ParentFont = False
    Visible = False
  end
  object Button1: TButton
    Left = 344
    Top = 256
    Width = 161
    Height = 65
    Caption = 'Start'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object ListBox1: TListBox
    Left = -10
    Top = 0
    Width = 10
    Height = 10
    ItemHeight = 13
    TabOrder = 1
    Visible = False
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 240
    Width = 185
    Height = 81
    ItemIndex = 0
    Items.Strings = (
      #1042#1074#1077#1089#1090#1080' 1 '#1073#1091#1082#1074#1091
      #1042#1074#1077#1089#1090#1080' '#1087#1086#1083#1085#1086#1089#1090#1100#1102' '#1089#1083#1086#1074#1086)
    TabOrder = 2
    Visible = False
    OnClick = RadioGroup1Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 344
    Width = 185
    Height = 39
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    Visible = False
    OnKeyUp = Edit1KeyUp
  end
  object MainMenu1: TMainMenu
    Left = 32
    Top = 40
    object N2: TMenuItem
      Caption = #1057#1083#1077#1076#1091#1102#1097#1080#1081' '#1083#1074#1083
      Visible = False
      OnClick = N2Click
    end
    object N1: TMenuItem
      Caption = #1055#1077#1088#1077#1080#1075#1088#1072#1090#1100
      Visible = False
      OnClick = N1Click
    end
  end
end
