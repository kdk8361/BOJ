#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <memory.h>
#include <vector>
#include <queue>
#include <map>
#pragma warning(disable:4996) 
using namespace std;

int main() {
	int t;
	cin >> t;
	int a, b;
	int interval[10] = { 1,1,4,4,2,1,1,4,4,2 };
	int rep[10][5] = {
		{ 10 },
		{ 1 },
		{ 6,2,4,8 },
		{ 1,3,9,7 },
		{ 6,4 },
		{ 5 },
		{ 6 },
		{ 1,7,9,3 },
		{ 6,8,4,2 },
		{ 1,9 }
	};
	while (t--) {
		cin >> a >> b;
		a %= 10;
		cout << rep[a][b%interval[a]] << '\n';
	}

}