#include <iostream>
using namespace std;
int test18()
{
	int Y;
	cin >> Y;
	cout << (((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0) ? "YES" : "NO");
	return 0;
}