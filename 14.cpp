/*
14. Количество способов
Дан неориентированный граф. Определить количество маршрутов (по ребрам можно перемещаться несколько раз) длиной L между вершинами U и V.
*/

#include <iostream>
using namespace std;
typedef unsigned long long ull;
int N;
const ull Module = 1000000007;
ull *Mat, *tempC, *Eye;

ull* mod(ull *A)
{
	for(int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			A[i*N + j] %= Module;
	return A;
}

ull* mult(ull * A, ull * B)
{
	ull* C = tempC;
    for (int i = 0; i < N; ++i)
    {
        ull * c = C + i * N;
        for (int j = 0; j < N; ++j)
            c[j] = 0;
        for (int k = 0; k < N; ++k)
        {
            const ull * b = B + k * N;
            ull a = A[i*N + k];
            for (int j = 0; j < N; ++j) {
                c[j] += a * b[j];
                c[j] %= Module;
            }
        }
    }
	tempC = A;
	return C;
}

ull* binpow(int n)
{
	if (n == 0)
		return Eye;
	if (n % 2 == 1)
		return mult(binpow(n-1), Mat);
	else {
		ull* b = binpow(n / 2);
		return mult(b, b);
	}
}

int main()
{
    int M, U, V, L;
    cin >> N >> M;
    cin >> U >> V >> L;
    --U; --V;
    ull Mat0[N][N], tempC1[N][N], tempC2[N][N];
    Mat = *Mat0; tempC = *tempC1; Eye = *tempC2;
    for(int i = 0; i < N; i++) {
    	for(int j = 0; j < N; j++) {
    		Mat0[i][j] = 0;
    		tempC2[i][j] = 0;
    	}
    	tempC2[i][i] = 1;
    }
    
    
    int at, to;
    for(int i = 0; i < M; i++){
    	cin >> at >> to;
    	--at; --to;
    	Mat0[at][to]++;
    	Mat0[to][at]++;
    }

    ull *dist = binpow(L);
    cout << dist[U*N + V];
}
