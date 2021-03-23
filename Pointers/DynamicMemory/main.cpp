#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);

void pop_back(int*& arr, int& n);	//������� ������� � ����� �������
void pop_front(int*& arr, int& n);

//#define PUSH_BACK

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	int value;	//���������� ��������
	cout << "������� ����������� ��������: "; cin >> value;
#ifdef PUSH_BACK
	//1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������:
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������:
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ����� �������:
	arr[n] = value;
	n++;
#endif // PUSH_BACK
	push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);

	cout << "�������� ���������� ��������:\n";
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
	//1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];	//�������� �������� ��������������
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������:
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������:
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ����� �������:
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1/*�������, �����������*/]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];	//�������� �������� �� ��������� �� ���� ������� ������
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n]{};	//�������� ������ ��������� ���������� ���� ������
	//��� ���� ����� ������� ������� �� �������, 
	//� �������� ������ ����� ����������� ��� �������� ����� ����������:
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