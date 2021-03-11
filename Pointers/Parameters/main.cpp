#include<iostream>
using namespace std;

#define tab "\t"
//define - определить
//Директива #define показывает компилятору, 
//что заменить, чем заменить
//#define создает макроопределение (макрос)
//identifier - это имя!!!

/*
-----------------------------
-По Значению - By value;
-По Указателю - By pointer;
-По Ссылке - By reference;
-----------------------------
*/

void Exchange(int& a, int& b);//Прототип функции (Объявление функции - Function declaration)
//В прототипе и реализации функции мы показываем, какие параметры функция ПРИНИМАЕТ

void main()
{
	setlocale(LC_ALL, "Russian");
	int a = 2, b = 3;
	cout << a << tab << b << endl;
	Exchange(a, b);	//Вызов функции - Function call.
	//Когда мы вызываем функцию, мы ПЕРЕДАЕМ в нее параметры.
	cout << a << tab << b << endl;
}

void Exchange(int& a, int& b)	//Реализация (Определение) функции - Function definition
//В прототипе и реализации функции мы показываем, какие параметры функция ПРИНИМАЕТ
{
	int buffer = a;
	a = b;
	b = buffer;
	//cout << a << tab << b << endl;
}