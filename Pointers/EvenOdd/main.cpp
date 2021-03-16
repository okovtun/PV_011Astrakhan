#include<iostream>
#include<ctime>
using namespace std;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int n = 10;
	//cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	//Вычислим количество четных и нечетных элементов:
	int even_count = 0;	//Количество четных значений
	int odd_count = 0;	//Количество нечетных значений
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
			even_count++;
		else
			odd_count++;
	}
	cout << "Количество четных элементов: " << even_count << endl;
	cout << "Количество нечетных элементов: " << odd_count << endl;
	//Выделяем память для массивов с четными и нечетными элементами:
	int* even = new int[even_count] {};
	int* odd = new int[odd_count] {};

	//Скопируем четные и нечетные значения в соответсвующие массивы:
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
			even[j++] = arr[i];
		else
			odd[k++] = arr[i];
		//(arr[i] % 2 ? odd[k++] : even[j++]) = arr[i];
	}
	cout << "Четные элементы:  "; Print(even, even_count);
	cout << "Нечетные элементы:"; Print(odd, odd_count);

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
		cout << arr[i] << tab;
	}
	cout << endl;
	int a = 2 > 3 ? 1 : 2;
}