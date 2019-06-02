/*
4. Путешествие с конём
Размеры прямоугольной размеченной квадратами доски n × m. В нижнем левом квадрате доски (1,1) находится шахматный конь. Конь может ходить только согласно шахматным правилам – движение может быть двумя квадратами горизонтально и затем одним вертикально, или двумя квадратами вертикально и одним горизонтально. Например, если n=4 и m=3, и конь находится в квадрате (2,1), то следующим может быть ход (1,3) или (3,3) или (4,2). Для заданных положительных целых значений n, m, i и j требуется определить минимальное необходимое количество ходов коня для перемещения из начальной позиции (1,1) в квадрат (i,j).
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ff(i,j) if(!used[i][j] && i >= 0 && i < M && j >= 0 && j < N)


int main()
{
	pair<int, int> s = { 0, 0 };
	int M, N, x, y;
	cin >> M >> N >> x >> y;
	x--; y--;
	queue<pair<int,int>> q;
	q.push({0,0});
	bool used[101][101] = { false };
	int d[101][101] = { 0 };
	used[0][0] = true;
	bool ok = false;
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		ff(i + 2, j + 1)
		{
			used[i + 2][j + 1] = true;
			q.push({ i + 2,j + 1 });
			d[i + 2][j + 1] = d[i][j] + 1;
		}
		ff(i + 2, j - 1)
		{
			used[i + 2][j - 1] = true;
			q.push({ i + 2,j - 1 });
			d[i + 2][j - 1] = d[i][j] + 1;
		}
		ff(i - 2, j + 1)
		{
			used[i - 2][j + 1] = true;
			q.push({ i - 2,j + 1 });
			d[i - 2][j + 1] = d[i][j] + 1;
		}
		ff(i - 2, j + 1)
		{
			used[i - 2][j - 1] = true;
			q.push({ i - 2,j - 1 });
			d[i - 2][j - 1] = d[i][j] + 1;
		}

		ff(i + 1, j + 2)
		{
			used[i + 1][j + 2] = true;
			q.push({ i + 1,j + 2 });
			d[i + 1][j + 2] = d[i][j] + 1;
		}
		ff(i - 1, j + 2)
		{
			used[i - 1][j + 2] = true;
			q.push({ i - 1,j + 2 });
			d[i - 1][j + 2] = d[i][j] + 1;
		}
		ff(i + 1, j - 2)
		{
			used[i + 1][j - 2] = true;
			q.push({ i + 1,j - 2 });
			d[i + 1][j - 2] = d[i][j] + 1;
		}
		ff(i - 1, j - 2)
		{
			used[i - 1][j - 2] = true;
			q.push({ i - 1,j - 2 });
			d[i - 1][j - 2] = d[i][j] + 1;
		}
		
		if (used[x][y]) {
			ok = true;
			break;
		}
	}
	if (ok)
		cout << d[x][y];
	else
		cout << "NEVAR";

	return 0;
}

