/*
1. Добавление
Дан неориентированный граф. Определить минимальное количество ребер, после добавления которых граф станет связным. Вывести -1 если ответа не существует.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> *g;
bool *used;
vector<int> comp;

void dfs (int v) {
	used[v] = true;
	comp.push_back (v);
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (! used[to])
			dfs (to);
	}
}

int find_comps(int N) {
    int counter = 0;
	for (int i=0; i<N; ++i)
		used[i] = false;
	for (int i=0; i<N; ++i)
		if (! used[i]) {
			comp.clear();
			dfs (i);
			counter++;
		}
    return counter;
}

int main()
{
    int N, M;
    cin >> N >> M;

    g = new vector<int>[N];
    used = new bool[N];
    int tempA, tempB;
    for (int i = 0; i < M; i++)
    {
        cin >> tempA >> tempB;
        g[tempA-1].push_back(tempB-1);
        g[tempB-1].push_back(tempA-1);
    }

    int counter = find_comps(N) - 1;
    cout << counter;
}