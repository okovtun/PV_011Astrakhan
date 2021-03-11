#include<iostream>
using namespace std;
#define tab "\t"

void FillRand(int arr[], const int n);	//Заполняет массив случайными числами
void Print(int* arr, const int n);		//Выводит массива на экран

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	//1) Объявление динамического массива:
	int* arr = new int[n] { 3, 5, 8, 13, 21 };
	//2) Использование динамического массива:
	Print(arr, n);
	FillRand(arr, n);
	Print(arr, n);
	//3) Удаление динамического массива:
	delete[] arr;
	cout << "That's okey ;-)" << endl;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Доступ к элементам массива через арифметику указателей
		//и оператор разыменования:
		*(arr + i) = rand();
	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Доступ к элементам массива через оператор индексирования (Subscript operator):
		cout << arr[i] << tab;
	}
	cout << endl;
}