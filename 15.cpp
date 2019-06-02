/*
15. Выравнивание
Дана последовательность Ai, состоящая из N целых чисел. За одно действие можно зафиксировать произвольный промежуток 
одинаковых элементов последовательности и увеличить все элементы этого промежутка на 1. Необходимо за минимальное количество действий уравнять все элементы.
*/

#include <iostream>

using namespace std;
typedef long long ull;


int main()
{
	long long counter = 0, max = 0, N;
	cin >> N;
	ull* A = new ull[N+1];
	for (ull i = 0; i < N; i++)
		cin >> A[i+1];

	for (ull i = 0; i < N; i++)
		if (A[i + 1] > max)
			max = A[i + 1];

	A[0] = max;

	for (ull i = 0; i < N; i++)
		if (A[i] > A[i + 1])
			counter += A[i] - A[i + 1];

	cout << counter;

	delete [] A;


	return 0;

}