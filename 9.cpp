/*
9. Инвертирование
Дана строка S и Q запросов. Запрос представляет собой пару чисел L и R — промежуток строки S, на котором нужно инвертировать регистр символов. Требутеся найти строку S после выполнения всех запросов.
*/

#include <iostream>
//#include <string.h>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int Q, N = S.length();
    bool changing = false, *changeInterval = new bool[N] {false};

    cin >> Q;

    int L, R;

    for(int i = 0; i < Q; i++)
    {
        cin >> L >> R;
        if(L > R){
            int temp = L;
            L = R;
            R = temp;
        }
        L--;
        changeInterval[L] = !changeInterval[L];
        changeInterval[R] = !changeInterval[R];
    }

    for(int i = 0; i < S.length(); i++)
    {
        if(changeInterval[i])
            changing = !changing;
        if(changing){
            if(S[i] >= 97 && S[i] <= 122){
                S[i] = toupper(S[i]);
            }
            else if(S[i] >= 65 && S[i] <= 90)
                S[i] = tolower(S[i]);
        }

    }
    cout << S;
    system("pause");
}