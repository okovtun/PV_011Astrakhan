#include<iostream>
#include<Windows.h>
using namespace std;

void ASCII();
int StringLength(char str[]);
void to_upper(char str[]);	//Переводит строку в верхний регистр
void to_lower(char str[]);	//Переводит строку в нижний регистр
void capitalize(char str[]);	//Первую букву каждого слова в предложении делает заглавной
void shrink(char str[]);
void remove_symbol(char str[], char symbol);

bool is_palindrome(char str[]);

bool is_int_number(char str[]);
int  to_int_number(char str[]);

bool is_bin_number(char str[]);
char* dec_to_bin(int decimal);
int  bin_to_dec(char str[]);
bool is_hex_number(char str[]);
int  hex_to_dec(char hex[]);

//#define STRING_DECLARATION //Объявление строк
//#define CHECK_1
#define BINARY

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRING_DECLARATION
	//ASCII-символ с кодом 0  '\0'
	'H';	//Символьная константа (типа char).
	"Hello";//Строковая константа 
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//for (int i = 0; i < sizeof(str); i++)cout << str[i];cout << endl;
	char str[] = "Hello";
	//str[1] = 'E';
	cout << str << endl;
	cout << sizeof("Hello") << endl;
	cout << sizeof(double) << endl;
#endif // STRING_DECLARATION

	//ASCII();
	cout << (int)'a' - (int)'A' << endl;
	cout << 'a' - 'A' << endl;
	const int n = 256;
	//char str[n] = "Hello   World     (  это    Привет   -     Мир   !!!          )";
	char str[n] = "Аргентина манит негра";
	//cout << "Введите строку: ";
	////cin >> str1;
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	//cin.getline(str, n);//CP1251
	//cout << str << endl;//CP866
#ifdef CHECK_1
	cout << StringLength(str) << endl;
	//cout << (int)'0' << endl;
	//to_upper(str);
	//capitalize(str);
	//shrink(str);
	cout << str << endl;

	cout << "Строка " << (is_palindrome(str) ? "" : "НЕ ") << "является палиндромом" << endl;
#endif // CHECK_1

	//cout << "Строка " << str << (is_int_number(str) ? "" : " НЕ") << " является целым числом" << endl;
	//cout << str << endl;
	//cout << to_int_number(str) * 2 << endl;

	//cout << is_bin_number(str) << endl;

	//int decimal;cout << "Введите десятичное число: "; cin >> decimal;
	//cout << dec_to_bin(decimal) << endl;

	cout << "Введите шестнадцатеричное число: "; cin >> str;
	cout << "Строка " << (is_hex_number(str) ? "" : "НЕ ") << "является шестнадцатеричным числом" << endl;
	cout << str << "(hex) = " << hex_to_dec(str) << "(dec)\n";

	//	cout << str << "(bin) = " << bin_to_dec(str) << "(dec)\n";
}

void ASCII()
{
	for (int i = 0; i < 128; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}
}

int StringLength(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
	/*
	--------------------------------------
	false - это 0
	true  - все что НЕ 0
	for(Counter; Condition; Expression)
	{

	}
	--------------------------------------
	*/
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (//ЕСЛИ символ
			str[i] >= 'a' && str[i] <= 'z' ||	//маленькая английская буква ИЛИ
			str[i] >= 'а' && str[i] <= 'я'		//маленькая русская буква
			)//тогда переводим в верхний регистр
			str[i] -= ' ';
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= 'А' && str[i] <= 'Я'
			)
			str[i] += 32;
	}
}

void capitalize(char str[])
{
	to_lower(str);
	//Первую букву каждого слова в предложении делает заглавной
	if (
		str[0] >= 'a' && str[0] <= 'z' ||
		str[0] >= 'а' && str[0] <= 'я'
		)
		str[0] -= 32;
	for (int i = 1; str[i]; i++)
	{
		if (str[i - 1] == ' ')
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
				str[i] -= 32;
		}
	}
}

void shrink(char str[])
{
	//Общий случай:
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] == ' ' &&
			(
				str[i + 1] == ' ' ||
				str[i + 1] == '.' ||
				str[i + 1] == ',' ||
				str[i + 1] == '?' ||
				str[i + 1] == '!' ||
				str[i + 1] == ':' ||
				str[i + 1] == ';' ||
				str[i + 1] == '-' ||
				str[i + 1] == ')'
				)
			|| str[0] == ' '
			|| str[i - 1] == '(' && str[i] == ' '
			|| str[i - 1] == '-'&& str[i] == ' '
			)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

bool is_palindrome(char str[])
{
	int length = StringLength(str);
	char* buffer = new char[length + 1]{};
	for (int i = 0; i < length; i++)
	{
		buffer[i] = str[i];
	}
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	length = StringLength(buffer);
	bool is_palindrome = true;
	for (int i = 0; i < length / 2; i++)
	{
		if (buffer[i] != buffer[length - 1 - i])
		{
			is_palindrome = false;
			break;
		}
	}
	delete[] buffer;
	return is_palindrome;
}

bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		//if (!(str[i] >= '0' && str[i] <= '9'))
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')return false;
		if (str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}

int  to_int_number(char str[])
{
	if (!is_int_number(str))return 0;
	int decimal = 0;	//Десятичное число
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			decimal *= 10;	//Сдвигаем число на 1 разряд влево
			decimal += str[i] - '0';
		}
	}
	return decimal;
}

bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
			return false;
		if (str[i] == ' ' && str[i - 1] == ' ' && str[i + 1] == ' ')
			return false;
	}
	return true;
}

void insert_spaces(char str[])
{
	for (int i = 1, digit = 0; str[i]; i++)
	{
		if (digit % 4 == 0)
		{
			for (int j = strlen(str); j > i; j--)
			{
				str[j] = str[j - 1];
			}
			str[i] = ' ';
			continue;
		}
		digit++;
	}
}

char* dec_to_bin(int decimal)
{
	//1) Определим количество двоичных разрядов:
	int capacity = 0;
	int buffer = decimal;
	for (; buffer; capacity++)
	{
		buffer /= 2;
		if (capacity % 4 == 0)capacity++;
	}
	//2) Выделяем память под двоичное число:
	char* bin = new char[capacity + 1]{};
	//3) Получаем разряды двоичного числа, и сохраняем их в строку:
	for (int i = 0, digit = 0; decimal; i++, digit++)
	{
		//if (i % 4 == 0)
		//{
		//	//bin[i] = ' ';
		//}
		//else
		{
			bin[i] = decimal % 2 + '0';	//Получаем младший разряд числа:
			decimal /= 2;				//Убираем младший разряд из числа
		}
	}
	insert_spaces(bin);
	return bin;
}

int bin_to_dec(char str[])
{
	if (!is_bin_number(str))return 0;
#ifdef DEBUG
	int decimal = 0;	//Конечное десятичное число
	int weight = 1;		//Весовой коэффициент разряда 2^n;
	int capacity = strlen(str);	//Разрядность двоичного числа
	for (int i = capacity - 1; i >= 0; i--)
	{
		decimal +=
	}
#endif // DEBUG

	int decimal = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			decimal *= 2;
			decimal += str[i] - '0';
		}
	}
	return decimal;
}

bool is_hex_number(char str[])
{
	for (int i = str[0] == '0' && (str[1] == 'x' || str[1] == 'X') ? 2 : 0; str[i]; i++)
	{
		if (
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			!(str[i] >= 'a' && str[i] <= 'f')
			)
			return false;
	}
	return true;
}

int  hex_to_dec(char hex[])
{
	if (!is_hex_number(hex))return 0;
	int decimal = 0;
	for (int i = 0; hex[i]; i++)
	{
		decimal *= 16;
		if (hex[i] >= '0' && hex[i] <= '9')decimal += hex[i] - '0';
		if (hex[i] >= 'A' && hex[i] <= 'F')decimal += hex[i] - 'A' + 10;
		if (hex[i] >= 'a' && hex[i] <= 'f')decimal += hex[i] - 'a' + 10;
	}
	return decimal;
}