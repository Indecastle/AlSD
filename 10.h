#pragma once


//#include "pch.h"
#include <iostream>
#include <string.h>
#include <map>

using namespace std;

struct state {
	int len, link;
	map<char, int> next;
};


const int MAXLEN = 10;
state st[MAXLEN * 2];
int sz, last;

void sa_extend(char c) {
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	int p;
	for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link)
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = sz++;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for (; p != -1 && st[p].next[c] == q; p = st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}

int test10()
{
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	++sz;

	char str[] = "abbb";
	for (int i = 0; i < 4; i++)
		sa_extend(str[i]);



	return 0;

}