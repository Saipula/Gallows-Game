//---------------------------------------------------------------------------

#ifndef classH
#define classH

#include <vector>

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
class str_obj{
public:
	AnsiString str1;
	AnsiString hint;
	int counter;

	str_obj(AnsiString Str1, short Counter, AnsiString Hint){
        str1 = Str1; counter = Counter; hint = Hint;
	}
};

class Game{
public:
	std::vector<str_obj*> slova;
    int iter;

	//Конструктор
	Game(TListBox *ListBox1){
        AnsiString temp[3]; //Временная переменная для заполнения Листа

		for (int i = 0; i < ListBox1->Items->Count; i++) { // Заполнение листа
			temp[i%3] = ListBox1->Items->Strings[i];

			if ((i+1)%3 == 0)
				slova.push_back(new str_obj(temp[0], temp[1].ToInt(), temp[2]));
		}
	}

	//Next iter
	void next_lvl();
	//Save game
	void save(TListBox *ListBox1);
	//Проверка полностью слова
	bool provFull(AnsiString slovo){
		if(slova[iter]->str1 == slovo)
			return true;
		return false;
	}
    //Проверяет букву
	AnsiString Bukva(AnsiString slovo, AnsiString bukva);
};


#endif
