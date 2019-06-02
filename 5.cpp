/*
5. Кратчайший путь
Задан связный неориентированный взвешенный граф G. В графе возможно наличие нескольких ребер между одной и той же парой вершин. Найдите вес кратчайшего пути между двумя заданными вершинами A и B.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 100000000000000;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<pair<int,int>> *g = new vector<pair<int,int>>[N];
    int tempA, tempB, tempC;
    for (int i = 0; i < M; i++)
    {
        cin >> tempA >> tempB >> tempC;
        --tempA; --tempB;
        g[tempA].push_back({tempB, tempC});
        g[tempB].push_back({tempA, tempC});
    }
    int S, L;
    cin >> S >> L;
    --S; --L;

    vector<long long> d (N, INF);
    vector<int> p (N);
	d[S] = 0;
	vector<char> u (N);
	for (int i=0; i<N; ++i) {
        int v = -1;
		for (int j=0; j<N; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == INF)
			break;
		u[v] = true;

		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first;
            long long len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
	cout << d[L];
}
