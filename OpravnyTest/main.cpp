#include "ZoznamStudentov.h"
#include "DoublePole.h"

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//ZoznamStudentov zoznamStudentov((char*)"Data5.txt");
	ZoznamStudentov zoznamStudentov((char*)argv[1]);

	//cout << "Zoznam studentov:" << endl;
	//nacitaj.Nacitaj();

	//zoznamStudentov.pridajStudentaManualne((char*)"Hudec Marian 1.03");		// v pripade, ze by som chcel pridavat dalsie zaznamy tymto sposobom, musel by som riesit kopirovanie zoznamu do noveho zoznamu o 1 vacsieho (vid "Kataster:Nehnutelnost")
	//																		// teda asi rovno prerobit aj celu triedu "ZoznamStudentov", minimalne pridavanie a parser.
	//
	//// https://stackoverflow.com/questions/3555108/multiple-word-string-input-through-scanf		https://stackoverflow.com/a/36632274
	//char* word = new char[255];
	//scanf("%63[^\n]s", word);		// scanf vracia pocet prvkov (pri dvoch = 2)... delimiter je v "[^?]... 63 znamena ze nacita 63 znakov (+ bin. 0)... "s" by tu nemalo byt treba
	////string word; 
	////getline(cin, word);		// cin >> slovo... cin nacitava po slovach (cin >> slovo1 >> slovo2 => nacita 2 slova, kazde do osobitnej premennej)
	//zoznamStudentov.pridajStudentaManualne(word);
	//delete[] word;
	////zoznamStudentov.pridajStudentaManualne(getline);
	

	cout << endl << "Studenti usporiadani vzostupne (podla priemeru):" << endl;
	zoznamStudentov.vypisUsporiadanyZoznamStudentovPodlaPriemeru();

	return 0;
}