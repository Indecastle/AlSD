/*
8. Максимальный неподпалиндром
В заданной строке S найти максимальную по длине подстроку, которая не является палиндромом.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool eqchar(string& s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[0]) return false;
    }
    return true;
}

int main()
{
	string S;
	cin >> S;
	if(eqchar(S)) {
		cout << "-1";
	}
	else {
		string copy(S);
		reverse(copy.begin(), copy.end());
		if(S == copy)
			cout << S.size() - 1;
		else
			cout << S.size();
	}

	return 0;
}