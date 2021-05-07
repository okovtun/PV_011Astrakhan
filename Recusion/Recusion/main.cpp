#include<iostream>
#include<conio.h>
using namespace std;

#define tab "\t"
//#define DataType long long int
typedef long long int DataType;

void elevator(int floor);
int factorial(int n);
double power(double a, int n);
void Fibonacci1(int n, int a = 0, int b = 1);
void Fibonacci2(int n, DataType a = 0, DataType b = 1);

//#define RECURSION_BASICS
//#define FACTORIAL
//#define POWER

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef RECURSION_BASICS
	system("CLS");
	cout << "Hello World\n";

	int floor;
	cout << "На каком Вы этаже?"; cin >> floor;
	elevator(floor);

	cout << "Еще разочек?(y/n):";
	if (_getch() == 'y')main();	//_getch() - ожидает нажатие клавиши, 
	//и возвращает ASCII-код нажатой клавиши  
#endif // RECURSION_BASICS

#ifdef FACTORIAL
	int n;
	cout << "Введите число для вычисления факториала: "; cin >> n;
	cout << factorial(n) << endl;
#endif // FACTORIAL

#ifdef POWER
	int a;	//Основание степени
	int n;	//Показатель степени
	cout << "Введите основание степени: "; cin >> a;
	cout << "Введите показатель степени: "; cin >> n;
	cout << power(a, n) << endl;
#endif // POWER

	int n;
	//cout << "Введите значение, до которого нужно вывести ряд Фибоначчи: "; cin >> n;
	cout << "Сколько чисел из ряда Фибоначчи нужно вывести: "; cin >> n;
	Fibonacci2(n);
}

void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "Привет подвал!" << endl;
		return;
	}
	static int counter = 0;
	cout << "Мы на " << floor << " этаже" << "\t";
	cout << counter++ << endl;;
	elevator(floor - 1);
	cout << "Мы на " << floor << " этаже" << "\t";
	cout << counter++ << endl;;
}

int factorial(int n)
{
	/*if (n == 0)return 1;
	return n * factorial(n - 1);*/

	return n == 0 ? 1 : n * factorial(n - 1);
}

double power(double a, int n)
{
	/*if (n == 0)return 1;
	if(n>0)	return a * power(a, n - 1);
	if (n < 0)return 1 / a * power(a, n + 1);*/

	return n == 0 ? 1 : n > 0 ? a * power(a, n - 1) : 1 / a * power(a, n + 1);
}

void Fibonacci1(int n, int a, int b)
{
	//Выводит числа Фибоначчи, до заданного предела
	if (a > n)return;
	cout << a << tab;
	Fibonacci1(n, b, a + b);
}
void Fibonacci2(int n, DataType a, DataType b)
{
	//Выводит заданное количество чисел из ряда Фибоначчи:
	static int i = 0;
	if (i > n)return;
	cout << i++ << " - " << a << endl;;
	Fibonacci2(n, b, a + b);
}
