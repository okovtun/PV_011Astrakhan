/*
1. Код добавления значения в конец массива вынести в функцию ??? push_back(???);  +
2. В проект DynamicMemory добавить функции:
	??? push_front(???);	//Добавляет значение в начало массива  +
	??? insert(???);		//Вставляет значение в массив по указанному индексу
	??? pop_back(???);		//Удаляет последний элемент из массива  +
	??? pop_front(???);		//Удаляет нулевой элемент из массива
	??? erase(???);			//Удаляет элемент из массива по заданному индексу
	Для того чтобы удалить элемент из массива, в буферный массив нужно скопировать все кроме удаляемого элемента.*/

#include<iostream>
using namespace std;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);
void pop_back(int*& arr, int& n);


void main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;

	int value; //добавляемое значение
	cout << "Введите добавляемое значение: "; cin >> value;

	push_back(arr, n, value);
	Print(arr, n);
	cout << endl;

	push_front(arr, n, value);
	Print(arr, n);
	cout << endl;

	pop_back(arr, n);
	cout << "Последний элемент массива удален: " << endl;
	Print(arr, n);

	delete[] arr;
}

void FillRand(int arr[], const int n) //заполнение рандомными значениями
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n) //вывод
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}

void push_back(int *&arr, int &n, int value) //Добавляет значение в конец массива
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[n] = value;
	n++;

}

void push_front(int*& arr, int& n, int value) //Добавляет значение в начало массива
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	buffer[0] = value;
	delete[] arr;
	arr = buffer;
}

void pop_back(int*& arr, int& n) //Удаляет последний элемент из массива
{
	//n--;
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
