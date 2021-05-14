#include<iostream>
//using namespace std;

#define tab "\t"

//#define PI 3.14

const double PI = 3.14;

//#define ALEX_IVLEV
//#define BORN_EVGENY
//#define MARGARITA
#define ALPHIA

void Print(int arr[], const int n);
void shift_left(/*? ? ? */);//Выполняет циклический сдвиг массива на заданное число элементов влево
int sum(int n, ...);

void main()
{
	setlocale(LC_ALL, "");
#ifdef ALEX_IVLEV
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Print(arr, n);
	int number_of_shifts;
	cout << "На сколько элементов сдвинуть массив? "; cin >> number_of_shifts;
	shift_left(? ? ? );
	Print(arr, n);
#endif // ALEX_IVLEV

#ifdef DEBUG
	//delete[] new int[5];
	int n = 5;
	int* arr = new int[n] {};

	int* buffer = arr;

	//delete[] buffer;
	delete[] arr;

	int brr[] = { 3, 5, 8, 13, 21, 34, 55 };
	//delete[] brr;
	for (int i = 0; i < 5; i++)
	{
		brr[i] = rand();
		cout << brr[i] << tab;
	}
	cout << endl;
#endif // DEBUG


#ifdef BORN_EVGENY
	int speed = 0;
	const int MAX_SPEED = 250;
	cout << typeid(250.).name() << endl;
	//http://cplusplus.com/doc/tutorial/constants/
	cout << (double)7 / 2 << endl;
#endif // BORN_EVGENY

#ifdef MARGARITA
	double a = 2.5;	//No conversion
	int b = 2.5;		//
	const int SIZE = 5;
	//SIZE = 5;
	//			l-value = r-value;
	int i = 3;
	i = ++i + i++;
	std::cout << i << std::endl;
	
#endif // MARGARITA

#ifdef NICK
	https ://www.cplusplus.com/reference/cstdarg/va_arg/
#endif //NICK

#ifdef ALPHIA
		   int a = 2;
		   int* pa = &a;
		   std::cout << sizeof(pa) << std::endl;
		   std::cout << pa << std::endl;
#endif // ALPHIA

}