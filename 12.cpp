/*
12. Большой куш
Известный фокусник Донни разбогател на очень простой игре. Он играл в нее на деньги с самыми богатыми и знаменитыми личностями, 
но никто ни разу не смог его обхитрить. И тут очередь дошла до вас. Вы белорусский бизнесмен и хотите удвоить свое состояние. 
Обыграйте Донни и сорвите куш! Так же вы можете отказаться от игры, если, при виде начальной позиции, на вас нападет плохое предчувствие.

Правила игры следующие: Изначально дано число X. За один ход разрешается отнять от числа X любую цифру, кроме 0, которая входит в число
 X. Проигрывает тот, кто не может ходить, то есть когда будет получено число 0.
*/

#include <iostream>
using namespace std;

int main()
{
    long long X;
    cin >> X;
    if(X%10 != 0)
        cout << X%10;
    else
        cout << "NO";
}