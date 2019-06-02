/*
16. Следующее
Дано число X. Надо найти наименьшее число большее, чем X, которое может быть получено из X перестановкой цифр.
*/

#include <iostream>
#include <string.h>
using namespace std;

void Sort(char *a, int size)
{
	for(int i=1; i < size;i++) 
    	for (int j=size-1; j >= i; j--) 
    		if (a[j-1] > a[j])
    		{
				char x = a[j-1]; 
				a[j-1] = a[j];
				a[j] = x;
			}
}

void swap(char *a, int size)
{
	char *min = a+1;
	for(int i = 2; i < size; i++) {
		if( (a[i] < *min) && (a[i] > *a) )
			min = &a[i];
	}
	char temp = *min; 
	*min = *a;
	*a = temp;
}

int main()
{
	char X[8];
	bool OK = false;
	cin >> X;
	for(int i = strlen(X) - 1; i > 0; i--) {
		if(X[i-1] < X[i]) {
			char *ch = &X[i-1];
			swap(ch, strlen(ch));
			Sort(ch+1, strlen(ch+1));
			OK = true;
			break;
		}
	}
	if(OK)
		cout << X;
	else
		cout << -1;

	return 0;
}