/*
19. Инверсии
Перестановкой чисел  назовем такую последовательность А длины N, что 1 ≤ Ai ≤ N, и все числа последовательности различны.

Инверсией в пeрестановке A размера N называется всякая пара индексов (i, j) такая, что i < j и Ai > Aj.

В данной задаче необходимо найти число инверсий в заданной перестановке.
*/

#include <iostream>
using namespace std;
#include <ctime>

int* merge_sort(int *up, int *down, unsigned int left, unsigned int right);
unsigned long int counter = 0;
int main()
{
    int N;
    cin >> N;
    int *ar = new int[N], *temp = new int[N];
    for(int i = 0; i < N; i++){
        cin >> ar[i];
    }
    double tt = clock();
    merge_sort(ar, temp, 0, N-1);
    cout << counter;
    //cout << endl << (clock()-tt)/1000;
}



int* merge_sort(int *up, int *down, unsigned int left, unsigned int right)
{
    if (left == right)
    {
        down[left] = up[left];
        return down;
    }

    unsigned int middle = (left + right) / 2;


    int *l_buff = merge_sort(up, down, left, middle);
    int *r_buff = merge_sort(up, down, middle + 1, right);


    int *target = l_buff == up ? down : up;

    unsigned int l_cur = left, r_cur = middle + 1;
    for (unsigned int i = left; i <= right; i++)
    {
        if (l_cur <= middle && r_cur <= right)
        {
            if (l_buff[l_cur] < r_buff[r_cur])
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
                counter += middle-left+1 - (l_cur-left);
            }
        }
        else if (l_cur <= middle)
        {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else
        {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}
