/*
18. Високосный
Високосный год — год в юлианском и григорианском календарях, продолжительность которого равна 366 дням — на одни сутки 
больше продолжительности обычного, невисокосного года. В юлианском календаре високосным годом является каждый четвёртый 
год, в григорианском календаре из этого правила есть исключения. Год в григорианском календаре является високосным, если 
он кратен 4 и при этом не кратен 100, либо кратен 400. Определите, является ли заданный год високосным в григорианском календаре.
*/

#include <iostream>
int main()
{
	int Y;
	std::cin >> Y;
	std::cout << (((Y%4 == 0 && Y%100 != 0) || Y%400 == 0) ? "YES" : "NO");
}