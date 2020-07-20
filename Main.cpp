//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "class.h"
#include <ctime>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Game *game;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	srand(time(NULL));

	ListBox1->Items->LoadFromFile("saves.txt", TEncoding::UTF8);
	game = new Game(ListBox1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	//����������� ������ ����� � ���������� ��� ������� ����������
	Button1->Visible = false;
	Label1->Visible = true;
	Label2->Visible = true;
	Label3->Visible = true;
	Label4->Visible = true;
	RadioGroup1->Visible = true;
	Edit1->Visible = true;
	N2->Visible = true;
	N1->Visible = true;

	N2Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
	game->next_lvl();
	N1Click(Sender);

	Label4->Caption = game->slova[game->iter]->hint;

	if (game->slova.empty()) // ���� ���� �� ������������ ���� �� � ���� ����, ������ ��������� ������ ��������� �� ����
		ShowMessage("Vector Empty!");
	else{
		//�������� �� ��, �� ������� �� ������� ������
		if (game->slova[game->iter]->counter != 0)  {
			ShowMessage("You win this level!\nYou Can Replay It!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
	//����� ������ ���������� (1 ������/ ������ ������������ �����)
	if(RadioGroup1->ItemIndex == 0){
		Edit1->MaxLength = 1;

		//���� �� ��� ��� ������ ����� �� �� ��� �������� ������ ������ ������
		char kek = Edit1->Text[1];
		Edit1->Text = kek;
	}

	if(RadioGroup1->ItemIndex == 1){
		Edit1->MaxLength = game->slova[game->iter]->str1.Length();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == 13){ // ������� ������ �����
		if(RadioGroup1->ItemIndex == 0){ //���������� Label1 �� 1 �������
			Label1->Caption = game->Bukva(Label1->Caption, Edit1->Text[1]);;
		}
		else if(RadioGroup1->ItemIndex == 1){ //���������� Label1 ���������
			if (game->provFull(Edit1->Text)) {
				Label1->Caption = Edit1->Text;
			}
		}

		//������� ���� � ������� �������������
		Edit1->Text = "";
		game->slova[game->iter]->counter++;
		Label3->Caption = game->slova[game->iter]->counter;

		//�������� �� ���������� ����� � Label1 � ������������ �����
		if (game->provFull(Label1->Caption)){
			ShowMessage("You completed this level in " +
				IntToStr(game->slova[game->iter]->counter) + " turns!");

			N2Click(Sender);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
	//��������� Label1 � ��������
	Label1->Caption = AnsiString::StringOfChar('*', game->slova[game->iter]->str1.Length());
	Edit1->Text = "";
	game->slova[game->iter]->counter = 0;
	Label3->Caption = game->slova[game->iter]->counter;

    //������ ������������ ������ �����
	if(Form1->RadioGroup1->ItemIndex == 0){
		Form1->Edit1->MaxLength = 1;
	}
	else if(Form1->RadioGroup1->ItemIndex == 1){
		Form1->Edit1->MaxLength = game->slova[game->iter]->str1.Length();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	//��� ������ �� ���� ����������� ���������� ����� � ������� ����� �� ������������ ��� ���� ���������
	if (!game->slova.empty()){
		game->save(ListBox1);
	}
}
//---------------------------------------------------------------------------


