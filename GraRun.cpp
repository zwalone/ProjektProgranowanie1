#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>


using namespace std;
const int width = 120, heigth = 28;
const int gamewidth = 30, gameheigth = 26;
char tab[gamewidth + 2][gameheigth + 2];
bool endgame = false , gameexit = false;
int xMe, yMe;
int level , czas, score, n;		//n do zmienna do lv
char postac, przeciwnik;

void LosujPrzeciwnika(); //losowanie przeciwników  
void Update();	//update pozycji na mapie	LosujPrzeciwnika i Endgame
void Menu();	//tab menu
void Setup();	//pocz¹tkowe parametry
void Mapa();	//Wypisanie obramówek
void Logic();	//movement i                 Update !
void gotoxy(int x , int y);	//kursor
void Options();				// opcja do rozbudowy
void Endgame();			//END GAME 
void HideCursor();
void ShowCursor();

int main() {
	HideCursor();
	
	Setup();
	while (gameexit != true) {
		Menu();
		Mapa();
		while (endgame != true) {
			Logic();
			score++;
			Sleep(czas);
			if (score == 45); {
				n++;
				if (n == 30) {
					level++;
					n = 0;
				}
			}
		}
		system("cls");
	}
	//system("pause");
	return 0;
}
void Menu() {
	cout << char(201);
	cout.fill(char(205));
	cout.width(width - 2);
	cout << char(187);
	cout << endl;

	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << char(186);
		cout.width(width - 2);
		cout << char(186);
		cout << endl;
	}
	//Napisz RUN
	cout << char(186);
	cout.width(43);
	cout << char(177) << char(177) << char(177) << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << char(177);
	cout.width(49);
	cout << char(186) << endl;

	cout << char(186);
	cout.width(43);
	cout << char(177) << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << char(177) << ' ' << ' ' << char(177);
	cout.width(49);
	cout << char(186) << endl;

	cout << char(186);
	cout.width(43);
	cout << char(177) << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << char(177) << ' ' << char(177);
	cout.width(49);
	cout << char(186) << endl;

	cout << char(186);
	cout.width(43);
	cout << char(177) << char(177) << char(177) << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << char(177) << char(177);
	cout.width(49);
	cout << char(186) << endl;

	cout << char(186);
	cout.width(43);
	cout << char(177) << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << char(177);
	cout.width(49);
	cout << char(186) << endl;

	cout << char(186);
	cout.width(43);
	cout << char(177) << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << char(177) << char(177) << char(177) << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << char(177);
	cout.width(49);
	cout << char(186) << endl;


	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << char(186);
		cout.width(width - 2);
		cout << char(186);
		cout << endl;
	}

	cout << char(204);  ///========
	cout.fill(char(205));
	cout.width(width - 2);
	cout << char(185);
	cout << endl;

	cout.fill(' ');
	for (int i = 0; i < 7; i++) {
		cout << char(186);
		cout.width(width - 2);
		cout << char(186);
		cout << endl;
	}
	
	cout << char(186);
	cout.width(58);
	cout << "1.START";
	cout.width(60);
	cout << char(186);
	cout << endl;

	cout << char(186);
	cout.width(60);
	cout << "2.OPTIONS";
	cout.width(58);
	cout << char(186);
	cout << endl;

	cout << char(186);
	cout.width(57);
	cout << "3.EXIT";
	cout.width(61);
	cout << char(186);
	cout << endl;

	cout.fill(' ');
	for (int i = 0; i < 4; i++) {
		cout << char(186);
		cout.width(width - 2);
		cout << char(186);
		cout << endl;
	}


	cout << char(200);
	cout.fill(char(205));
	cout.width(width - 2);
	cout << char(188);		

		//obs³uga Menu
		switch (_getch())
		{
		case '1':{
			system("cls");
			endgame = false;
			break;
		}
		case '2': {
			system("cls");
			Options();
			break;
		}
		case '3': {
			system("cls");
			gameexit = true;
			endgame = true;
			break;
		}
		default:
			system("cls");
			Menu();
			break;
		}
}  
void Setup() {
	endgame = false;
	xMe = gamewidth/2;
	yMe = gameheigth;
	//pierwsze zaznaczenie postaci
	tab[xMe][yMe] = postac;
	level = 1;
	czas = 200;
	postac = 178; 
	przeciwnik = 33; 
	score = 0;
	n = 0;
}
void Mapa() {

	//Obramowki
	cout << char(201);
	cout.fill(char(205)); 
	cout.width(gamewidth+1);
	cout << char(187);
	cout << endl;
	
	cout.fill(' ');
	for (int i = 0; i < gameheigth; i++) {
		cout << char(186);
		cout.width(gamewidth+1);
		cout << char(186);
		cout << endl;
	}
	cout << char(200);
	cout.fill(char(205)); 
	cout.width(gamewidth+1);
	cout << char(188);
	cout << endl;

	gotoxy(60, 8);
	cout << "LEVEL :";
	gotoxy(60, 13);
	cout << "STEROWANIE";
	gotoxy(60, 15);
	cout << "A - Lewo";
	gotoxy(60, 16);
	cout << "D - Prawo";
}
void Logic() {
	//Poruszanie 
	if (_kbhit() == true) 
	{
		//czyszczenie pozycji na mapie
		tab[xMe][yMe] = 32;
		gotoxy(xMe, yMe);
		cout << tab[xMe][yMe];

		switch (_getch()) {
		case 'a': {
			if (xMe == 1) xMe =1;
			else xMe -= 1;
			//pozycja na mapie 
			tab[xMe][yMe] = postac;
			gotoxy(xMe, yMe);
			cout << tab[xMe][yMe];
			break;
		}


		case 'd': {
			if (xMe == gamewidth) xMe = gamewidth;
			else xMe += 1;
			//pozycja na mapie 
			tab[xMe][yMe] = postac;
			gotoxy(xMe, yMe);
			cout << tab[xMe][yMe];
			break;
		}
		default:
			//pozycja na mapie 
			tab[xMe][yMe] = postac;
			gotoxy(xMe, yMe);
			cout << tab[xMe][yMe];
			break;
		}
		//kursor poza mape
		gotoxy(120, 28);
	
	}
	else
	{
		//pozycja na mapie 
		tab[xMe][yMe] = postac;
		gotoxy(xMe, yMe);
		cout << tab[xMe][yMe];
		gotoxy(120, 28);
	}
	Update();
	}
void Update() {
	//Update LEVEL
	gotoxy(68, 8);
	cout << level;
	//Update przeciwnikow
	for (int i = 1; i < gamewidth + 1; i++) {                   
		for (int j = gameheigth + 1; j > 1; j--) {
			tab[i][j] = tab[i][j - 1];
			tab[i][j - 1] = 32;
		}
	}
	LosujPrzeciwnika();
	Endgame();
	//zanaczanie pozycji na mapie
	tab[xMe][yMe] = postac;
	//Wipisywanie przeciwników
	for(int i = 1 ; i< gameheigth+1 ; i ++){
		gotoxy(1, i);
		for (int j = 1; j < gamewidth+1; j++) {
			cout << tab[j][i];
		}
}
	gotoxy(120, 28);
}
void LosujPrzeciwnika(){
	//Randomowe uk³adanie enemy level*2
	for (int i = 0; i < level ; i++) {
		tab[(rand() % gamewidth) + 1][1]=przeciwnik;
	}

}
void Endgame() {
	if (tab[xMe][yMe] == przeciwnik) {
		Sleep(1000);
		endgame = true;
		level = 1;
		gotoxy(0, 0);
		//czyszczeni tablicy
		for (int i = 0; i < gamewidth + 2; i++) {
			for (int j = 0; j < gameheigth + 2; j++) {
				tab[i][j] = 32;
			}
		}
	}
}
void Options() {
	//Obramowki
	cout << char(201);
	cout.fill(char(205));
	cout.width(width-2);
	cout << char(187);
	cout << endl;

	cout.fill(' ');
	for (int i = 0; i < heigth-1; i++) {
		cout << char(186);
		cout.width(width-2);
		cout << char(186);
		cout << endl;
	}
	cout << char(200);
	cout.fill(char(205));
	cout.width(width-2);
	cout << char(188);
	cout << endl;

	// ======
	gotoxy(0, 13);
	cout << char(204);
	cout.fill(char(205));
	cout.width(width - 2);
	cout << char(185);

	//   <<char(177)    <<' '     Napis Options
	gotoxy(31, 4); cout << char(177) << char(177) << char(177) << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << char(177) << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << char(177) << char(177) << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << char(177) << char(177) << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' '<< ' ' << ' ' << char(177) << char(177) << char(177);
	gotoxy(31, 5); cout << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << char(177) << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177);
	gotoxy(31, 6); cout << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << char(177) << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177);
	gotoxy(31, 7); cout << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << char(177) << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177);
	gotoxy(31, 8); cout << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177);
	gotoxy(31, 9); cout << char(177) << char(177) << char(177) << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << char(177) << char(177) << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << ' ' << ' ' << char(177) << ' ' << ' ' << ' ' << ' ' << ' ' << char(177) << char(177) << char(177);

	// Napisy wyboru 
	gotoxy(20, 17); cout << "POSTAC";				gotoxy(40, 17); cout << "PRZECIWNICY";			
	gotoxy(20, 19); cout << "1. " << char(207);		gotoxy(40, 19); cout << "a. " << char(126);
	gotoxy(20, 21); cout << "2. " << char(35);		gotoxy(40, 21); cout << "b. " << char(245);
	gotoxy(20, 23); cout << "3. " << char(254);		gotoxy(40, 23); cout << "c. " << char(206);
	gotoxy(20, 25); cout << "0. EXIT";

	//wybor znaków 
	switch (_getch())
	{
	case '1':{
		postac = 207;
		system("cls");
		Options();
		break;
		}
	case '2': {
		postac = 35;
		system("cls");
		Options();
		break;
	}
	case '3': {
		postac = 254;
		system("cls");
		Options();
		break;
	}
	case 'a': {
		przeciwnik = 126;
		system("cls");
		Options();
		break;
	}
	case 'b': {
		przeciwnik = 245;
		system("cls");
		Options();
		break;
	}
	case 'c': {
		przeciwnik = 206;
		system("cls");
		Options();
		break;
	}
	case '0': {
		system("cls");
		Menu();
		break;
	}
		default:
		{	system("cls");
			Options();
			break;
		}
	}
}
void gotoxy(int x, int y)
{
	COORD cord;
	cord.X = x;
	cord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}
void HideCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}
void ShowCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	if (hCCI.bVisible != TRUE)
	{
		hCCI.bVisible = TRUE;
		::SetConsoleCursorInfo(hConsoleOut, &hCCI);
	}
}
