
#include <iostream>
#include <time.h>
#include <random>
using namespace std;
/*e��� ������ 'arr' �� 10-�� ���������, ����������� ���������� �������. ����� ������� ��� ��� ������� 'even' � 'odd' ���������� ���������� �������, � ������ 'even' ����� ����������� ��� ������ �������� �� ��������� �������, � � ������
'odd' - ��������. ������� 'even' � 'odd' ������� �� �����.*/

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
	cout << "������� ���������� ��������� �������" << endl;
	cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	print(arr, n);
	int value;
	cout << "������� ����������� ��������" << endl;
	cin >> value;
	push_back(arr, n, value);
	print(arr, n);

	cout << endl;

	cout << "������� ����������� ��������" << endl;
	cin >> value;
	push_front(arr, n, value);
	print(arr, n);


	cout << "�������� ���������� ��������" << endl;
	pop_back(arr, n);
	print(arr, n);

	cout << "�������� �������� ��������" << endl;
	pop_front(arr, n);
	print(arr, n);

	cout << "������� erase �������� �������� �� ���������� ������� " << endl;
	erase(arr, n);
	print(arr, n);

	cout << "������� insert �������� �������� �� ���������� ������� " << endl;
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
	// 1) ������� ������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	// 2) �������� ��� �������� �� ������ ������ � ������ 
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];

	}
	// 3) ����� ���� ��� ������ �����������, ������� �������� �����
	delete[] arr;
	//4) ��������� ����� ��������� �� �������� ������
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ����� �������
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		// �������� �������� �� ��������� �� ���� ������� ������
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
	//��� ����, ����� ������� ������� �� ������� � �������� ������ ����� ����������� ��� �������� ����� ����������
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

/*������� ������� �� ������� �� ��������� �������*/

void erase(int*& arr, int& n)
{
	int* buffer = new int[n - 1]{};
	int a;
	cout << "������� ����� �������� ��� ��������" << endl;
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

//�������� 
void insert(int*& arr, int& n)
{
	int* buffer = new int[n + 1]{};
	int q;
	cout << "������� ������ ��� ���������� �����" << endl;
	cin >> q;
	int a;
	cout << "������� ����� ������� �� ������ ��������" << endl;
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

