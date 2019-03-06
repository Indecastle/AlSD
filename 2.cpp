#include <iostream>

using namespace std;

int test2()
{
	int N;
	cin >> N;
	int *a = new int[N];

	for (int i = 0; i < N; i++)
		cin >> a[i];

	if (N == 2) {
		cout << a[0] * (long long)a[1];
	}
	else {
		int *y = a;
		long long pa = 0, pb = 0, ma = 0, mb = 0;

		for (int i = 0; i < N; i++, y++) {
			if (*y > 0) {
				if (*y >= pa) {
					pb = pa;
					pa = *y;
				}
				else if (*y >= pb) {
					pb = *y;
				}
			}
			else {
				if (*y <= ma) {
					mb = ma;
					ma = *y;
				}
				else if (*y <= mb) {
					mb = *y;
				}
			}
		}
		long long maxp = pa * pb, maxm = ma * mb;
		cout << (maxp > maxm ? maxp : maxm);
	}

	delete[] a;

	return 0;

}