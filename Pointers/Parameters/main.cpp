#include<iostream>
using namespace std;

#define tab "\t"
//define - определить
//Директива #define показывает компилятору, 
//что заменить, чем заменить
//#define создает макроопределение (макрос)
//identifier - это имя!!!

void Exchange(int a, int b);//Прототип функции (Объявление функции - Function declaration)

void main()
{
	setlocale(LC_ALL, "Russian");
	int a = 2, b = 3;
	cout << a << tab << b << endl;
	Exchange(a, b);
	cout << a << tab << b << endl;
}

void Exchange(int a, int b)	//Реализация (Определение) функции - Function definition
{
	int buffer = a;
	a = b;
	b = buffer;
	cout << a << tab << b << endl;
}

/*
-----------------------------
-По Значению;
-По Указателю;
-По Ссылке;
-----------------------------
*/