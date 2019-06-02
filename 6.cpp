/*
6. RMQ наоборот
Дано M троек чисел Li, Ri, Vi. Необходимо найти такую последовательность Ai, состоящую из N целых чисел, у которой минимум на отрезке [Lj, Rj], будет равен Vj (для всех 1 ≤ j ≤ M).
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ull;

int compare(const void * x1, const void * x2)
{
    ull a = *((ull*)x1+2), b = *((ull*)x2+2);
    if(a < b) return 1;
    if(a > b) return -1;
    return 0;
}

int main()
{
    ull N, M;
    cin >> N >> M;
    ull request[M][3] = {0};
    for (int i = 0; i < M; i++)
    {
        cin >> request[i][0] >> request[i][1] >> request[i][2];
        request[i][0]--; request[i][1]--;
    }

    qsort(request, M, sizeof(ull)*3, compare);

	ull** ss = new ull*[N+1];
    ull nums[N+1];
    //int *zero = new int(-1);
    for(int i = 0; i < N+1; i++){
		nums[i] = -1;
		ss[i] = NULL;
		//cout << nums[i] << ' ';
	}
	//cout << endl;

    for(int i = 0; i < M; i++)
    {
        ull L = request[i][0], R = request[i][1], V = request[i][2];
        ull *a = new ull(L);
        for(int j = L; j <= R;)
        {
            if(ss[j] == NULL)
            {
            	nums[j] = V;
            	ss[j] = a;
            	*ss[j] = j+1;
            	j++;
			}
			else
			{
				j = *ss[j];
			}
		}	
    }

    for(int i = 0; i < N; i++){
        cout << nums[i] << ' ';
    }
    return 0;
}
