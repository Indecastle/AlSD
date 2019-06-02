/*
13. Удаление
Дан неориентированный граф. Определить минимальное количество ребер, после удаления которых между каждой парой вершин будет 
существовать только один маршрут (без повторений в нем ребер). Вывести -1, если ответа не существует.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> *g;
short *used;
int counter, dop;

void dfs (int v) {
	used[v] = 1;
	int to;
	while(!g[v].empty()) {
		to = g[v].back();
		g[v].pop_back();
        g[to].erase(find(g[to].begin(), g[to].end(), v));
		if (used[to] == 0) {
			dfs (to);
		}
		else {
            ++counter;
            //cout << v+1 << ' ' << to+1 << endl;
        }
	}
}

void find_comps(int N) {
    for (int j=0; j<N; ++j)
            used[j] = 0;
    counter = 0;

    dfs(0);
    for (int i=0; i<N; ++i)
        if(used[i] == 0) {
            counter = -1;
            dop = 0;
            break;
        }
}

int main()
{
    int N, M;
    cin >> N >> M;
    dop = 0;

    g = new vector<int>[N];
    used = new short[N]{0};
    int tempA, tempB;
    for (int i = 0; i < M; i++)
    {
        cin >> tempA >> tempB;
        --tempA; --tempB;
        if(find(g[tempA].begin(), g[tempA].end(), tempB) != g[tempA].end()) {
            ++dop;
            continue;
        }
        g[tempA].push_back(tempB);
        g[tempB].push_back(tempA);
    }
    //cout << endl;
    find_comps(N);
    cout << counter+dop;
}