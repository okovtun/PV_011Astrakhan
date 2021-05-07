https://github.com/okovtun/PV_011Astrakhan
https://github.com/okovtun/DynamicAstrakhan
https://www.youtube.com/watch?v=ZzIIEXZ5yfU&list=PLeqyOOqxeiIMGEfDteoklYzplaPhrM2wp&index=2&t=1504s
https://meet.google.com/cig-beeg-wjp?authuser=0
https://meet.google.com/mho-khdw-fhj

/////////////////////////////////////////////////////////////////////////
https://doc.qt.io/qt-5/gettingstarted.html
https://doc.qt.io/qt-5/qtwidgets-tutorials-notepad-example.html
https://doc.qt.io/qt-5/qtdoc-tutorials-alarms-example.html
https://www.boost.org/doc/libs/1_76_0/?view=categorized
/////////////////////////////////////////////////////////////////////////

TODO:
Реализовать игру Пятнашки.

DONE:
0	1	1	2	3	5	8	13	21
1. Написать рекурсивную функцию Fibonacci, которая выводит на экран ряд чисел Фибоначчи, до указанного числа;
2. Написать рекурсивную функцию Fibonacci, которая выводит на экран заданное количество чисел Фибоначчи;

TODO:
Упростить функции:
void to_lower(char str[]);
void to_upper(char str[]);
bool is_int_number(char str[]);
int to_int_number(char str[]);
bool is_hex_number(char str[]);
используя стандартные функции из библиотек: string.h, stdlib.h, ctype.h
http://cplusplus.com/reference/cstring/
http://cplusplus.com/reference/cstdlib/
http://cplusplus.com/reference/cctype/

DONE:
void shrink(char str[]);		//Удаляет из строки лишние пробелы, например:				DONE
								//Хорошо        живет     на   свете    Винни      Пух
								//Хорошо живет на свете Винни Пух
bool is_palindrome(char str[]);	//Определяет, является ли строка палиндромом				DONE

bool is_int_number(char str[]);	//Определяет, является ли строка целым числом				DONE
								//Строка является целы числом, когда она состоит только из цифр.
int  to_int_number(char str[]);	//Если строка - целое число, функция вернет его числовое значение.	DONE

bool is_bin_number(char str[]);	//Проверяет, является ли строка двоичным числом				DONE
int  bin_to_dec(char str[]);	//Если строка - двоичное число, функция вернет его десятичное значение.	
???  dec_to_bin(int decimal);	//Функция принимает десятичное число, и возвращает его двоичное значение. !!!!TODO

bool is_hex_number(char str[]);	//Проверяет, является ли функция шестнадцатеричным числом	DONE
int  hex_to_dec(char str[]);	//Если строка - Шестнадцатеричное число, функция вернет его десятичное значение		DONE
???  dec_to_hex(int decimal);	//Функция принимает десятичное число, и возвращает его Шестнадцатеричное значение.

bool is_mac_address(char str[]);//Проверяет, является ли строка MAC-адресом
bool is_ip_address(char str[]);	//Проверяет, является ли строка IP-адресом

Hardcore:
Если строка - целое число, функция вернет его письменное значение кирицей.

Упростить написанные функции используя стандартные функции:
http://cplusplus.com/reference/cstring/
http://cplusplus.com/reference/cstdlib/
http://cplusplus.com/reference/cctype/

void to_upper(char str[]);	//Переводит строку в верхний регистр	DONE
void to_lower(char str[]);	//Переводит строку в нижний регистр		DONE
void cpitalize(char str[]);	//Первую букву каждого слова в предложении делает заглавной DONE


DONE:
От ветки templated создать ветку templated_split, и в ней вынести шаблонные функции в отдельные файлы.

TOREAD:
http://cplusplus.com/doc/tutorial/functions2/ - templates

DONE:
В проект DynamicMemory добавить функции:

??? Allocate(???);	//Выделяет память для динамического массива. Сода нужно вынести код, выделяющий память под массив
??? Clear(???);		//Очищает память, занимаемую массивом

??? push_row_back(???);	//Добавляет пустую строку (заполненную нулями) в конец двумерного массива;	DONE
??? push_row_front(???);	//Добавляет пустую строку в начало двумерного массива;					DONE
??? insert_row(???);	//Добавляет пустую строку в двумерный массив, по указанному индексу;
??? pop_row_back(???);	//Удаляет строку с конца двумерного массива;		DONE
??? pop_row_front(???);	//Удаляет строку с начала двумерного массива;		DONE
??? erase_row(???);		//Удаляет строку с из двумерный массив, по указанному индексу;

void push_col_back(...);	DONE
void push_col_front(...);
void insert_col(...);

void pop_col_back(...);
void pop_col_front(...);
void erase_col(...);

DONE:
1. Код добавления значения в конец массива вынести в функцию ??? push_back(???);
2. В проект DynamicMemory добавить функции:
	??? push_front(???);	//Добавляет значение в начало массива	DONE
	??? insert(???);		//Вставляет значение в массив по указанному индексу
	??? pop_back(???);		//Удаляет последний элемент из массива	DONE
	??? pop_front(???);		//Удаляет нулевой элемент из массива	DONE
	??? erase(???);			//Удаляет элемент из массива по заданному индексу
	Для того чтобы удалить элемент из массива, в буферный массив нужно скопировать все кроме удаляемого элемента.

DONE:
Есть массив 'arr' из 10-ти элементов, заполненный случайными числами. Нужно создать еще два массива 'even' и 'odd' минимально возможного размера, в массив 'even' нужно скопировать все четные значения из исходного массива, а в массив 
'odd' - нечетные. Массивы 'even' и 'odd' вывести на экран.

DONE:
Выучить теорию по указателям, ссылкам, и передачу параметров!!!