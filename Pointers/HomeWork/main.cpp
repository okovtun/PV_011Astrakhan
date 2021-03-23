/*
1. ��� ���������� �������� � ����� ������� ������� � ������� ??? push_back(???);  +
2. � ������ DynamicMemory �������� �������:
	??? push_front(???);	//��������� �������� � ������ �������  +
	??? insert(???);		//��������� �������� � ������ �� ���������� �������
	??? pop_back(???);		//������� ��������� ������� �� �������  +
	??? pop_front(???);		//������� ������� ������� �� �������
	??? erase(???);			//������� ������� �� ������� �� ��������� �������
	��� ���� ����� ������� ������� �� �������, � �������� ������ ����� ����������� ��� ����� ���������� ��������.*/

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
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;

	int value; //����������� ��������
	cout << "������� ����������� ��������: "; cin >> value;

	push_back(arr, n, value);
	Print(arr, n);
	cout << endl;

	push_front(arr, n, value);
	Print(arr, n);
	cout << endl;

	pop_back(arr, n);
	cout << "��������� ������� ������� ������: " << endl;
	Print(arr, n);

	delete[] arr;
}

void FillRand(int arr[], const int n) //���������� ���������� ����������
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n) //�����
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}

void push_back(int *&arr, int &n, int value) //��������� �������� � ����� �������
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

void push_front(int*& arr, int& n, int value) //��������� �������� � ������ �������
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

void pop_back(int*& arr, int& n) //������� ��������� ������� �� �������
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
