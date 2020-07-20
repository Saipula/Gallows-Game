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
	//Выключается кнопка Старт и включаются все игровые компоненты
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

	if (game->slova.empty()) // Если файл из сохранениями пуст то и лист пуст, значит программа выдаст сообщение об этом
		ShowMessage("Vector Empty!");
	else{
		//Проверка на то, не пройден ли уровень раньше
		if (game->slova[game->iter]->counter != 0)  {
			ShowMessage("You win this level!\nYou Can Replay It!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
	//Выбор режима заполнения (1 символ/ Длинна необходимого слова)
	if(RadioGroup1->ItemIndex == 0){
		Edit1->MaxLength = 1;

		//Если до это был другой режим то из его приходит только первый символ
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
	if(Key == 13){ // Нажатие кнопки Ентер
		if(RadioGroup1->ItemIndex == 0){ //Заполнение Label1 по 1 символу
			Label1->Caption = game->Bukva(Label1->Caption, Edit1->Text[1]);;
		}
		else if(RadioGroup1->ItemIndex == 1){ //Заполнение Label1 полностью
			if (game->provFull(Edit1->Text)) {
				Label1->Caption = Edit1->Text;
			}
		}

		//Очищаем Едит и счётчик увеличивается
		Edit1->Text = "";
		game->slova[game->iter]->counter++;
		Label3->Caption = game->slova[game->iter]->counter;

		//Проверка на совпадения слова в Label1 и необходимого слова
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
	//Обнуление Label1 и счётчика
	Label1->Caption = AnsiString::StringOfChar('*', game->slova[game->iter]->str1.Length());
	Edit1->Text = "";
	game->slova[game->iter]->counter = 0;
	Label3->Caption = game->slova[game->iter]->counter;

    //Замена максимальной длинны Едита
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
	//При выходе из игра сохраняется неоходимое слово и сколько ходов на разгадывание его было потрачено
	if (!game->slova.empty()){
		game->save(ListBox1);
	}
}
//---------------------------------------------------------------------------


