#include<iostream>
#include<conio.h>
using namespace std;

#define tab "\t"
#define VERTICAL_SHIFT		"\n\n\n\n\n\n\n\n"
#define HORIZONTAL_SHIFT	"\t\t\t\t\t\t"

void ASCII();
void InitField(char field[]);
void PrintField(char field[], char player);
void Move(char field[], char player);
void Check(char field[], char player);

void main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 9;
	char field[n] = {};
	InitField(field);
	//PrintField(field);
	cout << "Еще разочек? (y/n):" << endl;
	if (_getch() == 'y')main();
}

void ASCII()
{
	setlocale(LC_ALL, "C");
	for (int i = 0; i < 256; i++)
	{
		/*if (i % 16 == 0)cout << endl;
		cout << (char)i << " ";*/
		cout << i << tab << (char)i << endl;
	}
}

void InitField(char field[])
{
	for (int i = 0; i < 9; i++)
		field[i] = ' ';
	PrintField(field, '0');
	//Check(field, 'X');
}

void PrintField(char field[], char player)
{
	system("CLS");
	//ASCII();
	cout << VERTICAL_SHIFT;
	for (int i = 6; i >= 0; i -= 3)
	{
		cout << HORIZONTAL_SHIFT;
		cout << " ";
		for (int j = 0; j < 3; j++)
		{
			cout << field[i + j];
			if (j != 2)cout << " | ";
		}
		cout << endl;
		if (i != 0)cout << HORIZONTAL_SHIFT << "--- --- ---";
		cout << endl;
	}
	//Move(field, player);
	Check(field, player);
}

void Move(char field[], char player)
{
	char key;//Ожидает нажатие клавиши, и возвращает ASCII-код нажатой клавиши.
	do
	{
		key = _getch();
		if (key == 27)return;
		if (key<'1' || key>'9')cout << "\aВы вышли за пределы игрового поля, допустимые клавиши 1...9" << endl;
		else if (field[key - 49] != ' ')cout << "\aКлетка уже занята" << endl;
	} while (key<'1' || key>'9' || field[key - 49] != ' ');
	field[key - 49] = player;
	//PrintField(field);
	/*if (player == 'X')PrintField(field, '0');
	else PrintField(field, 'X');*/
	//PrintField(field, player == 'X' ? '0' : 'X');
	//Check(field, player);
	PrintField(field, player);
}

void Check(char field[], char player)
{
	bool game_over = false;

	if (field[0] == field[4] && field[4] == field[8] && field[4] == player) game_over = true;
	if (field[2] == field[4] && field[4] == field[6] && field[4] == player) game_over = true;

	if (field[0] == field[1] && field[1] == field[2] && field[2] == player) game_over = true;
	if (field[3] == field[4] && field[4] == field[5] && field[4] == player) game_over = true;
	if (field[6] == field[7] && field[7] == field[8] && field[8] == player) game_over = true;

	if (field[0] == field[3] && field[3] == field[6] && field[6] == player) game_over = true;
	if (field[1] == field[4] && field[4] == field[7] && field[7] == player) game_over = true;
	if (field[2] == field[5] && field[5] == field[8] && field[8] == player) game_over = true;

	if (game_over)
	{
		cout << player << " победил" << endl;
		return;
	}

	bool draw = true;	//Допускаем ничью, но это нужно проверить
	for (int i = 0; i < 9; i++)
	{
		if (field[i] == ' ')
		{
			draw = false;
			break;
		}
	}
	if (draw)
	{
		cout << "Ничья" << endl;
		return;
	}

	Move(field, player == 'X' ? '0' : 'X');
	//PrintField(field, player == 'X' ? '0' : 'X');
}