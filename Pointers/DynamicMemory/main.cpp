#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

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