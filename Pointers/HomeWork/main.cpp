
#include <iostream>
#include <time.h>
#include <random>
using namespace std;
/*eсть массив 'arr' из 10-ти элементов, заполненный случайными числами. Нужно создать еще два массива 'even' и 'odd' минимально возможного размера, в массив 'even' нужно скопировать все четные значения из исходного массива, а в массив
'odd' - нечетные. Массивы 'even' и 'odd' вывести на экран.*/

void FillRand(int arr[], int n);
void print(int arr[], int n);
void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);

void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);

void erase(int*& arr, int& n);

void insert(int*& arr, int& n);

int main()
{
	setlocale(LC_ALL, "ru");
	int n = 0;
	cout << "введите количество элементов массива" << endl;
	cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	print(arr, n);
	int value;
	cout << "введите добавляемое значение" << endl;
	cin >> value;
	push_back(arr, n, value);
	print(arr, n);

	cout << endl;

	cout << "введите добавляемое значение" << endl;
	cin >> value;
	push_front(arr, n, value);
	print(arr, n);


	cout << "удаление последнего элемента" << endl;
	pop_back(arr, n);
	print(arr, n);

	cout << "удаление нулевого элемента" << endl;
	pop_front(arr, n);
	print(arr, n);

	cout << "функция erase удаление элемента по выбранному индексу " << endl;
	erase(arr, n);
	print(arr, n);

	cout << "функция insert удаление элемента по выбранному индексу " << endl;
	insert(arr, n);
	print(arr, n);

	delete[] arr;

}

void FillRand(int* arr, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 20;
	}

}
void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void push_back(int*& arr, int& n, int value)
{
	// 1) создаем буферны массив нужного размера
	int* buffer = new int[n + 1]{};
	// 2) копируем все значения из одного массва в другой 
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];

	}
	// 3) После того как данные скопированы, удаляем исходный массв
	delete[] arr;
	//4) подменяем адрес указателя на исходный массив
	arr = buffer;
	//5) И только после всего этого можно записать новое значение а конец массива
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		// копируем элементы со смещением на один элемент вправо
		buffer[i + 1] = arr[i];

	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	//для того, чтобы удалить элемент из массива в буферный массив нужно скопировать все элементы кроме удаляемого
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;


}

void pop_front(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}

/*Удаляет элемент из массива по заданному индексу*/

void erase(int*& arr, int& n)
{
	int* buffer = new int[n - 1]{};
	int a;
	cout << "введите номер элемента для удаления" << endl;
	cin >> a;
	for (int i = 0, j = 0; i < n; j++, i++)
	{
		if (i != (a - 1))
		{
			buffer[j] = arr[i];
		}
		else
		{
			j--;
		}

	}
	n--;
	delete[] arr;
	arr = buffer;
}

//добавить 
void insert(int*& arr, int& n)
{
	int* buffer = new int[n + 1]{};
	int q;
	cout << "введите индекс для добавления числа" << endl;
	cin >> q;
	int a;
	cout << "введите число которое вы хотите вставить" << endl;
	cin >> a;
	for (int i = 0; i < q; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[q] = a;

	for (int j = q; j < n; j++)
	{
		buffer[j + 1] = arr[j];
	}

	delete[] arr;
	arr = buffer;
	n++;
}

