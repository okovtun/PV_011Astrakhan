#include <iostream>
using namespace std;

#define tab "\t";

template <typename T>
void Round(T**& arr, int row, int col);

template <typename T>
void Allocate(T**& arr, int row, int col);
template <typename T>
void FillRand(T**& arr, int row, int col);
template <typename T>
void Print(T**& arr, const int row, const int col);

template <typename T>
void PushRowBack(T**& arr, int& row, int col, int value);
template <typename T>
void PushRowFront(T**& arr, int& row, int col, int value);
template <typename T>
void InsertRow(T**& arr, int& row, int col, int value);

template <typename T>
void PopRowBack(T**& arr, int& row, int value);
template <typename T>
void PopRowFront(T**& arr, int& row, int value);
template <typename T>
void EraseRow(T**& arr, int& row, int col, int value);

template <typename T>
void PushColBack(T**& arr, int row, int& col, int value);
template <typename T>
void PushColFront(T**& arr, int row, int& col, int value);
template <typename T>
void InsertCol(T**& arr, int row, int& col, int value);

template <typename T>
void PopColBack(T**& arr, int row, int& col, int value);
template <typename T>
void PopColFront(T**& arr, int row, int& col, int value);
template <typename T>
void EraseCol(T**& arr, int row, int& col, int value);

template <typename T>
void Clear(T**& arr, int row);

int main()
{
	setlocale(LC_ALL, "Russian");
	int row, col;
	cout << "Программа выводит массив заполненный случайными числами от 0 до 100,\n"
		"и позволяет добавлять или удалять нужное количество строк.\n"
		"Введите количество строк: ";
	cin >> row;
	cout << "Введите количество элементов в строке: ";
	cin >> col;
	char c;
	bool o = false;
	int** I_arr = new int*[row] {};
	double** D_arr = new double*[row] {};
	float** F_arr = new float*[row] {};
	char** C_arr = new char*[row] {};
	do {
		cout << "Выберите тип массива (I - int, F - float, D - double, C - char) - ";
		cin >> c;
		switch (c) {
		case 'i':
		case 'I':
			Round(I_arr, row, col);
			o = true;
			break;
		case 'f':
		case 'F':
			Round(F_arr, row, col);
			o = true;
			break;
		case 'd':
		case 'D':
			Round(D_arr, row, col);
			o = true;
			break;
		case 'c':
		case 'C':
			Round(C_arr, row, col);
			o = true;
			break;
		default:
			cout << "Тип не выбран." << endl;
			break;
		}
	} while (!o);

	return 0;
}
template <typename T>
void Round(T**& arr, int row, int col)
{
	int value;
	Allocate(arr, row, col);
	FillRand(arr, row, col);
	Print(arr, row, col);
	/*cout << "Введите количество добавляемых строк в конец массива: ";
	cin >> value;
	PushRowBack(arr, row, col, value);
	Print(arr, row, col);
	cout << "Введите количество добавляемых строк в начало массива: ";
	cin >> value;
	PushRowFront(arr, row, col, value);
	Print(arr, row, col);
	cout << "Введите количество строк добавляемых в массив: ";
	cin >> value;
	InsertRow(arr, row, col, value);
	Print(arr, row, col);
	cout << "Введите количество строк удаляемых с конца массива:";
	cin >> value;
	PopRowBack(arr, row, value);
	Print(arr, row, col);
	cout << "Введите количество строк удаляемых в начале массива: ";
	cin >> value;
	PopRowFront(arr, row, value);
	Print(arr, row, col);
	cout << "Введите количество удаляемых из массива строк: ";
	cin >> value;
	EraseRow(arr, row, col, value);
	Print(arr, row, col);
	cout << "Введите количество добавляемых столбцов в конец массива: ";
	cin >> value;
	PushColBack(arr, row, col, value);
	Print(arr, row, col);
	cout << "Введите количество добавляемых столбцов в начало массива: ";
	cin >> value;
	PushColFront(arr, row, col, value);
	Print(arr, row, col);
	cout << "Введите количество столбцов добавляемых в массив: ";
	cin >> value;
	InsertCol(arr, row, col, value);
	Print(arr, row, col);
	cout << "Введите количество столбцов удаляемых в конце массива: ";
	cin >> value;
	PopColBack(arr, row, col, value);
	Print(arr, row, col);
	cout << "Введите количество столбцов удаляемых в начале массива: ";
	cin >> value;
	PopColFront(arr, row, col, value);
	Print(arr, row, col);*/
	cout << "Введите количество удаляемых из массива столбцов: ";
	cin >> value;
	EraseCol(arr, row, col, value);
	Print(arr, row, col);
	Clear(arr, row);
}
template <typename T>
void Allocate(T**& arr, int row, int col)
{
	for (int i = 0; i < row; i++)
		arr[i] = new T[col]{};
}
template <typename T>
void FillRand(T**& arr, int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr[i][j] = rand() % 10000 / 1e2;
}
template <typename T>
void Print(T**& arr, const int row, const int col)
{
	cout << endl << "№\t ";
	for (int i = 0; i < col; i++)
		cout << i + 1 << tab;
	cout << endl << " \t";
	for (int i = 0; i < col; i++)
		cout << "________";
	cout << endl;
	for (int i = 0; i < row; i++) {
		cout << i + 1 << "\t|";
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << tab;
		cout << endl;
	}
	cout << endl;
}
template <typename T>
void PushRowBack(T**& arr, int& row, int col, int value)
{
	T** PushBackBuffer = new T*[row + value]{};
	for (int i = 0; i < row + value; i++)
		i < row ? PushBackBuffer[i] = arr[i] : PushBackBuffer[i] = new T[col]{};
	delete[] arr;
	arr = PushBackBuffer;
	row += value;
}
template <typename T>
void PushRowFront(T**& arr, int& row, int col, int value)
{
	T** PushFrontBuffer = new T*[row + value]{};
	for (int k = 0, i = 0; i < row + value; i++)
		i < value ? PushFrontBuffer[i] = new T[col]{} : PushFrontBuffer[i] = arr[k++];
	delete[] arr;
	arr = PushFrontBuffer;
	row += value;
}
template <typename T>
void InsertRow(T**& arr, int& row, int col, int value)
{
	bool o;
	int buffer;
	int* IndexBuffer = new int [value] {};
	for (int i = 0; i < value; i++)
		do {
			o = true;
			cout << "Введите номер для " << i + 1 << "-й строки: ";
			cin >> IndexBuffer[i];
			for (int j = 0; j < i; j++)
				IndexBuffer[j] == IndexBuffer[i] ? o = false : j;
		} while (1 > IndexBuffer[i] || IndexBuffer[i] > row + value || !o);
		for (int i = 0; i < value; i++)
			for (int j = i + 1; j < value; j++)
				if (IndexBuffer[j] < IndexBuffer[i]) {
					buffer = IndexBuffer[i];
					IndexBuffer[i] = IndexBuffer[j];
					IndexBuffer[j] = buffer;
				}
		T** InsertBuffer = new T*[row + value]{};
		for (int k = 0, v = 0, i = 0; i < row + value; i++)
			i == IndexBuffer[k] - 1 ? k++, InsertBuffer[i] = new T[col]{} : InsertBuffer[i] = arr[v++];
		delete[] arr;
		arr = InsertBuffer;
		row += value;
}
template <typename T>
void PopRowBack(T**& arr, int& row, int value)
{
	T** PopBackBuffer = new T*[row - value]{};
	for (int k = row - value, i = 0; i < row; i++)
		if (i < row - value)
			PopBackBuffer[i] = arr[i];
		else
			delete[] arr[k++];
	delete[] arr;
	arr = PopBackBuffer;
	row -= value;
}
template <typename T>
void PopRowFront(T**& arr, int& row, int value)
{
	T** PopFrontBuffer = new T*[row - value]{};
	for (int k = 0, i = 0; i < row; i++)
		if (i >= value)
			PopFrontBuffer[k++] = arr[i];
		else
			delete[] arr[i];
	delete[] arr;
	arr = PopFrontBuffer;
	row -= value;
}
template <typename T>
void EraseRow(T**& arr, int& row, int col, int value)
{
	bool o;
	int buffer;
	int* IndexBuffer = new int[value];
	for (int i = 0; i < value; i++)
		do {
			o = true;
			cout << "Введите номер " << i + 1 << "-й удаляемой строки: ";
			cin >> IndexBuffer[i];
			for (int j = 0; j < i; j++)
				IndexBuffer[j] == IndexBuffer[i] ? o = false : j;
		} while (1 > IndexBuffer[i] || IndexBuffer[i] > row || !o);
		for (int i = 0; i < value; i++)
			for (int j = i + 1; j < value; j++)
				if (IndexBuffer[j] < IndexBuffer[i]) {
					buffer = IndexBuffer[i];
					IndexBuffer[i] = IndexBuffer[j];
					IndexBuffer[j] = buffer;
				}
		T** EraseBuffer = new T*[row - value]{};
		for (int k = 0, v = 0, i = 0; i < row - value; i++)
			if (v != IndexBuffer[k] - 1)
				EraseBuffer[i] = arr[v++];
			else
				k++, delete[] arr[v++], i--;
		delete[] arr;
		arr = EraseBuffer;
		row -= value;
}
template <typename T>
void PushColBack(T**& arr, int row, int& col, int value)
{
	T** PushBackBuffer = new T*[row] {};
	for (int i = 0; i < row; i++) {
		PushBackBuffer[i] = new T[col + value]{};
		for (int j = 0; j < col + value; j++)
			j < col ? PushBackBuffer[i][j] = arr[i][j] : PushBackBuffer[i][j];
		delete[] arr[i];
	}
	delete[] arr;
	arr = PushBackBuffer;
	col += value;
}
template <typename T>
void PushColFront(T**& arr, int row, int& col, int value)
{
	T** PushFrontBuffer = new T*[row] {};
	for (int i = 0; i < row; i++) {
		PushFrontBuffer[i] = new T[col + value]{};
		for (int k = -value, j = 0; j < col + value; j++, k++)
			j < value ? PushFrontBuffer[i][j] : PushFrontBuffer[i][j] = arr[i][k];
		delete[] arr[i];
	}
	delete[] arr;
	arr = PushFrontBuffer;
	col += value;
}
template <typename T>
void InsertCol(T**& arr, int row, int& col, int value)
{
	bool o;
	int buffer;
	int* IndexBuffer = new int [value] {};
	for (int i = 0; i < value; i++)
		do {
			o = true;
			cout << "Введите номер для " << i + 1 << "-го столбца: ";
			cin >> IndexBuffer[i];
			for (int j = 0; j < i; j++)
				IndexBuffer[j] == IndexBuffer[i] ? o = false : j;
		} while (1 > IndexBuffer[i] || IndexBuffer[i] > col + value || !o);
		for (int i = 0; i < value; i++)
			for (int j = i + 1; j < value; j++)
				if (IndexBuffer[j] < IndexBuffer[i]) {
					buffer = IndexBuffer[i];
					IndexBuffer[i] = IndexBuffer[j];
					IndexBuffer[j] = buffer;
				}
		T** InsertBuffer = new T*[row] {};
		for (int i = 0; i < row; i++) {
			InsertBuffer[i] = new T[col + value]{};
			for (int k = 0, v = 0, j = 0; j < col + value; j++)
				j == IndexBuffer[k] - 1 ? InsertBuffer[i][j] = 0, k++ : InsertBuffer[i][j] = arr[i][v++];
			delete[] arr[i];
		}
		delete[] arr;
		arr = InsertBuffer;
		col += value;
}
template <typename T>
void PopColBack(T**& arr, int row, int& col, int value)
{
	T** PopBackBuffer = new T*[row] {};
	for (int i = 0; i < row; i++) {
		PopBackBuffer[i] = new T[col - value]{};
		for (int j = 0; j < col - value; j++)
			PopBackBuffer[i][j] = arr[i][j];
		delete[] arr[i];
	}
	delete[] arr;
	arr = PopBackBuffer;
	col -= value;
}
template <typename T>
void PopColFront(T**& arr, int row, int& col, int value)
{
	T** PopFrontBuffer = new T*[value] {};
	for (int i = 0; i < row; i++) {
		PopFrontBuffer[i] = new T[col - value]{};
		for (int k = value, j = 0; j < col - value; j++)
			PopFrontBuffer[i][j] = arr[i][k++];
		delete[] arr[i];
	}
	delete[] arr;
	arr = PopFrontBuffer;
	col -= value;
}
template <typename T>
void EraseCol(T**& arr, int row, int& col, int value)
{
	bool o;
	int buffer;
	int* IndexBuffer = new int[value];
	for (int i = 0; i < value; i++)
		do {
			o = true;
			cout << "Введите номер " << i + 1 << "-го удаляемого столбца: ";
			cin >> IndexBuffer[i];
			for (int j = 0; j < i; j++)
				IndexBuffer[j] == IndexBuffer[i] ? o = false : j;
		} while (1 > IndexBuffer[i] || IndexBuffer[i] > col || !o);
		//Сортировка индексов:
		for (int i = 0; i < value; i++)
			for (int j = i + 1; j < value; j++)
				if (IndexBuffer[j] < IndexBuffer[i]) {
					buffer = IndexBuffer[i];
					IndexBuffer[i] = IndexBuffer[j];
					IndexBuffer[j] = buffer;
				}

		T** EraseBuffer = new T*[row] {};
		for (int i = 0; i < row; i++) {
			EraseBuffer[i] = new T[col - value];
			for (int s = 1, k = 0, v = 0, j = 0; j < col - value; j++, v++)
				j == IndexBuffer[k] - 1 ? k++, s++, j-- : EraseBuffer[i][j] = arr[i][v];
			delete[] arr[i];
		}
		delete[] arr;
		arr = EraseBuffer;
		col -= value;
}
template <typename T>
void Clear(T**& arr, int row)
{
	for (int i = 0; i < row; i++)
		delete[] arr[i];
	delete[] arr;
}