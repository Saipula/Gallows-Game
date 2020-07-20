//---------------------------------------------------------------------------

#pragma hdrstop

#include "class.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Game::next_lvl(){
	iter = rand()%slova.size();
}

void Game::save(TListBox *ListBox1){
	ListBox1->Clear();
	DeleteFile("saves.txt");

	for (int i = 0; i < slova.size(); i++) {
		ListBox1->Items->Add(slova[i]->str1);
		ListBox1->Items->Add(IntToStr(slova[i]->counter));
		ListBox1->Items->Add(slova[i]->hint);
	}
	ListBox1->Items->SaveToFile("saves.txt");
}

AnsiString Game::Bukva(AnsiString slovo, AnsiString bukva){
	for (int i = 0; i < slovo.Length(); i++) {
		if (slova[iter]->str1[i+1] == bukva[1])
			slovo[i+1] = bukva[1];
	}
	return slovo;
}

