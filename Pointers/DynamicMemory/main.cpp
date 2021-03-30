#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int m, const int n);
void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);

void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);

void pop_back(int*& arr, int& n);	//Удаляет элемент с конца массива
void pop_front(int*& arr, int& n);
void erase(int*& arr, int& n, int index);

//Добавление строк:
void push_row_back(int**& arr, int& m, const int n);
void push_row_front(int**& arr, int& m, const int n);

//Удаление строк:
void pop_row_back(int**& arr, int& m, const int n);

//Добавление столбцов:
void push_col_back(int** arr, const int m, int& n);

//#define PUSH_BACK
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define DEBUG_ARRAYS

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello" << endl;
#ifdef DYNAMIC_MEMORY_1
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

	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);

	cout << "Удаление последнего элемента:\n";
	pop_back(arr, n);
	Print(arr, n);
	cout << "Введите индекс удавляемого элемента: "; cin >> index;
	erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	/////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////		ОБЪЯВЛЕНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА		/////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	int m;	//Количество строк
	int n;	//Количество элементов cтроки
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки: "; cin >> n;
	//1)Создаем массив указателей, и сохраняем его адрес в указатель на указатель:
	int** arr = new int*[m];
	//2)Выделяем память под строки двумерного массива:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////		ИСПОЛЬЗОВАНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА		/////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	cout << "Память выделена" << endl;
	system("PAUSE");
	FillRand(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление строки в конец массива:\n";
	push_row_back(arr, m, n);
	Print(arr, m, n);
	
	cout << "Добавление строки в начало массива:\n";
	push_row_front(arr, m, n);
	Print(arr, m, n);
	


	cout << "Добавление столбца в конец:" << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);
	//cout << "Строка добавлена" << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////		УДАЛЕНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА		/////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	//1) Удаление строк:
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	//2) Удаление массива указателей:
	delete[] arr;
#endif // DYNAMIC_MEMORY_2

#ifdef DEBUG_ARRAYS
	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	Print(arr, n);
#endif // DEBUG_ARRAYS

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
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
void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};
	/*for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < n; i++)
		buffer[i + 1] = arr[i];*/
	for (int i = 0; i < n; i++)
	{
		true;
		if (i < index)buffer[i] = arr[i]; else buffer[i + 1] = arr[i];
		//(i < index) ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		//(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
		buffer[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
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
void erase(int*& arr, int& n, int index)
{
	int* buffer = new int[--n]{};
	/*for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}*/
	for (int i = 0; i < n; i++)
	{
		//buffer[i] = i < index ? arr[i] : arr[i + 1];
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	arr = buffer;
}

void push_row_back(int**& arr, int& m, const int n)
{
	//1) Создаем буферный массив:
	int** buffer = new int*[m + 1]{};
	/*for (int i = 0; i < m + 1; i++)
	{
		buffer[i] = new int[n] {};
	}*/

	//2) Копируем все значения исходного массива в буферный
	for (int i = 0; i < m; i++)
	{
		/*for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}*/
		buffer[i] = arr[i];	//В буферный массив просто переносим адрес соответсвующей строки.
	}

	//3) Удаляем исходный массив:
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	//НЕ нужно удалять строки, достаточно удалить старый массив указателей:
	delete[] arr;
	//4) Переопределяем новый массив:
	arr = buffer;
	//5) Создаем добавляемую строку:
	arr[m] = new int[n] {};
	m++;
}
void push_row_front(int**& arr, int& m, const int n)
{
	//1) Создаем буферный массив указателей нужного размера:
	int** buffer = new int*[m + 1]{};
	//2) Копируем адреса строк в новый массив:
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3) Удаляем старый массив указателей:
	delete[] arr;
	//4) Подменяем адрес на новый массив:
	arr = buffer;
	//5) Создаем добавляемую строку:
	arr[0] = new int[n] {};
	//5) Увеличиваем количество строк:
	m++;
}

void pop_row_back(int**& arr, int& m, const int n)
{
	//1) Создаем буферный массив указателей нужного размера:
	int** buffer = new int*[--m]{};
	//2) Копируе мстроки в новый массив:
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем последнюю строку:
	delete[] arr[m];
	//4) Удаляем старый массив указателей:
	delete[] arr;
	//5) Сохраняем адрем нового массива:
	arr = buffer;
}
void push_col_back(int** arr, const int m, int& n)
{
	//Проходим по строкам, и переопределяем каждую строку:
	for (int i = 0; i < m; i++)
	{
		//1) Создаем строку нужного размера:
		int* buffer = new int[n + 1]{};
		//2) Копируем исходную строку в новую:
		for (int j = 0; j < n; j++)buffer[j] = arr[i][j];
		//3) Удаляем исходную строку:
		delete[] arr[i];
		//4) Подменяем адрес старой строки, адресом новой строки:
		arr[i] = buffer;
	}
	//6) После того, как мы переопределили каждую строку, увеличиваем количество строк на 1:
	n++;
}