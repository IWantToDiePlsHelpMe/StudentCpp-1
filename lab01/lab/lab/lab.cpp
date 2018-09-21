// lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float n1, n2, ch; //ch = choice
	float res;
	char yn;
	int n_sqr;

	cout << "Hello my dear. What are the numbers?\n";
	cout << "Number 1:";
	cin >> n1;
	cout << "Number 2:";
	cin >> n2;

	cout << "\nWhat do you want to do?\n1. +\n2. -\n3. *\n4. /\n5. square\n6. sqrt\nYour answer:";
	cin >> ch;
	if (ch == 1) {
		res = n1 + n2;
	}
	if (ch == 2) {
		res = n1 - n2;
	}
	if (ch == 3) {
		res = n1 * n2;
	}
	if (ch == 4) {
		res = n1 / n2;
	}
	if (ch == 5) {
		cout << "\nWhich number do you want to use? 1/2\n";
		cin >> n_sqr;
		cout << "\n";
		if (n_sqr == 1) {  //добавить защиту от других символов
			res = n1 * n1;
		}
		if (n_sqr == 2) {
			res = n2 * n2;
		}
	}
	if (ch == 6) {
		cout << "\nWhich number do you want to use? 1/2\n";
		cin >> n_sqr;
		cout << "\n";
		if (n_sqr == 1) { //добавить защиту от других символов
			res = sqrt(n1);
		}
		if (n_sqr == 2) {
			res = sqrt(n2);
		}
	}
	cout << "Result = " << res << "\n";

	cout << "Do you want to try again? y/n\n";
	cin >> yn;
	if (yn == 'Y' || yn == 'y') { //добавить защиту от других символов
		main();
	}
	if (yn == 'N' || yn == 'n') {
		return 0;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
