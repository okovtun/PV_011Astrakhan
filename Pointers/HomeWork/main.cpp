/*Используя два указателя на массив целых чисел, скопировать один массив в другой.
Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.*/

#include <iostream>
using namespace std;

void Les1()
{
	const int size = 10;
	int arr1[size] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	int arr2[size];
	int* parr1 = arr1;
	int* parr2 = arr2;

	cout << "{ ";
	for (int i = 0; i < size; i++)
	{
		parr2 = parr1;
		cout << *parr2 << " ";
		parr1++;
		parr2++;
	}
	cout << "}\n\n";

	system("PAUSE");
}

void Les2()
{
	const int size = 9;
	int arr[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, temp;
	int* start = arr, *end = &arr[size - 1];
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	while (start != end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void main()
{
	int a;
	cout << "Введите номер задания(1 или 2):  ";
	cin >> a;
	switch (a)
	{
	case 1:
		Les1();
		break;

	case 2:
		Les2();
		break;

	default:
		cout << "Некорректный ввод!";
	}

}