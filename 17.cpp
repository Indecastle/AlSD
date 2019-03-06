#include <iostream>
using namespace std;

int main()
{
    int N;
    long long temp;
    bool b1=false, b2=false , b3=false,   b12=false, b13=false, b23=false,   b01=false;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        if(temp == 1021)
            b1 = true;
        else if(temp == 1031)
            b2 = true;
        else if(temp == 1033)
            b3 = true;

        else if(temp == 1087388483)
            b01 = true;

        else if(temp == 1052651) //1021*1031
            b12 = true;
        else if(temp == 1054693) //1021*1033
            b13 = true;
        else if(temp == 1065023) //1031*1033
            b23 = true;
    }
    cout << (b1&&b2&&b3 || b01 || b12&&b3 || b13&&b2 || b23&&b1 ? "YES" : "NO");
}

