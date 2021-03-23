#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);

void pop_back(int*& arr, int& n);	//Удаляет элемент с конца массива
void pop_front(int*& arr, int& n);

//#define PUSH_BACK

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	int value;	//Добвляемое значение
	cout << "Введите добавляемое значение: "; cin >> value;
#ifdef PUSH_BACK
	//1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1]{};
	//2) Копируем все значения из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) После того как данные скопированы, исходный массив можно удалить:
	delete[] arr;
	//4) Подменяем адрес в указателе на исходный массив:
	arr = buffer;
	//5) И только после всего этого можно записать новое значение в конец массива:
	arr[n] = value;
	n++;
#endif // PUSH_BACK
	push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);

	cout << "Удаление последнего элемента:\n";
	pop_back(arr, n);
	Print(arr, n);
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] <<tab;
	}
	cout << endl;
}

void push_back(int*& arr, int& n, int value)
{
	//1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1]{};
	//2) Копируем все значения из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];	//Копируем элементы СООТВЕТСТВЕННО
	}
	//3) После того как данные скопированы, исходный массив можно удалить:
	delete[] arr;
	//4) Подменяем адрес в указателе на исходный массив:
	arr = buffer;
	//5) И только после всего этого можно записать новое значение в конец массива:
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1/*Сложить, суммировать*/]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];	//Копируем элементы СО СМЕЩЕНИЕМ НА ОДИН ЭЛЕМЕНТ ВПРАВО
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n]{};	//Фигурные скобки заполняют выделяемую пать нулями
	//Для того чтобы удалить элемент из массива, 
	//в буферный массив нужно скопировать все элементы кроме удаляемого:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
void pop_front(int*& arr, int& n)
{
	
}