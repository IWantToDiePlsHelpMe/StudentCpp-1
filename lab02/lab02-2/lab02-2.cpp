#include "pch.h"
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	int f = 0, k = 0, e = 0, j = 0, bd = 0, ad = 0;
	double* con = new double[255];
	char* arr = new char[255];
	cout << "Input numbers:" << endl;
	int dot = 0, i_dot = 255;//перенести в цикл
	do {
		cin.getline(arr, 255);
		con[k] = 0.0;
		for (int i = 0; i < (strlen(arr));) {
			while (i < strlen(arr) && (arr[i]<'0' || arr[i]>'9')) {
				if (arr[i] == 'e' && arr[i + 1] == 'n' && arr[i + 2] == 'd') {
					f = 1;
					break;
				}
				if (arr[i] == '-') {
					e = 1;
					arr[i] = '0';
				}
				if (arr[i] == '.') {
					dot = 1;
					i_dot = i;
					j = i_dot + 1;
				}
				i++;
			}
			if (f == 1) break;
			if (dot = 0) {
				arr[i] -= '0';
				con[k] += (arr[i] * pow(10, strlen(arr) - (i + 1)));

			}
			if (dot = 1) {
				if (i < i_dot) {
					arr[i] -= '0';
					con[k] += (arr[i] * pow(10, strlen(arr) - (i + 1)));
				}
				if (i == i_dot) continue;
				if (i > i_dot) {
					arr[i] -= '0';
					con[k] += (arr[i] * pow(10, strlen(arr) - i));
				}
			}
			i++;
		}
		if (dot == 1) for (int i = 0; i < (strlen(arr) - i_dot); i++) con[k] = con[k] / 10;
		if (f == 1) break;
		if (e == 1) con[k] *= (-1);
		i_dot = 0;
		dot = 0;
		k++;
	} while (f == 0);
	for (int i = 0; i < k; i++) cout << con[i] << endl;
	cout << dot << ' ' << i_dot << endl;
	/*k = k - 3;
	delete[] arr;
	char sym[63];
	char* deistv = new char[255];
	cout << "Input operations:" << endl;
	do {
		cin.getline(deistv, 255);
		for (int i = 0; i < strlen(deistv); i++) {
			if (deistv[i] == '+' || deistv[i] == '-' || deistv[i] == '/' || deistv[i] == '*') {
				sym[i] = deistv[i];
				j++;
			}
			else {
				continue;
			}
		}
		delete[] deistv;
	} while (j <= k);
	//for (int i = 0; i < 2; i++) cout << symb[i] << ' ';
	int res = con[0];
	for (int i = 0; i <= k; i++) {
		switch (sym[i]) {
		case '+':
			res = res + con[i + 1];
			break;
		case '-':
			res = res - con[i + 1];
			break;
		case '/':
			res = res / con[i + 1];
			break;

		case '*':
			res = res * con[i + 1];
			break;
		}
	}
	delete[] con;
	cout << res;
	return 0;*/
}