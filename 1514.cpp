#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int init[101];
int pw[101];

// 거리차이
int dx(int a, int b)
{
	int dif = a - b;
	if (a - b > 5)
		return a - b - 10;
	else if (a - b < -4)
		return a - b + 10;
	else
		return a - b;
}

/*
행동목록
-연산 = -1
행동하지않고 index 이동 혹은 초기 = 0
+연산 = 1
+11 = 2
-11 = 3
+111 = 4
-111 = 5

x = 현재 계산하고있는 index
a = 이전 행동
*/
int dp(int x, int a, int cnt)
{
	if (x == 0) return 0;
	// -9 -8 -7 -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 9
	// -4 -3 -2 -1 0 1 2 3 4 5
	int dif = dx(init[x], pw[x]);
	int dif2 = dx(init[x - 1], pw[x - 1]);
	int dif3 = dx(init[x - 2], pw[x - 2]);

	if (dif == dif2)
	{
		if (dif2 == dif3)
			return dp(x - 3, dif > 0 ? 4 : 5, cnt + abs(dif));
		else
			return dp(x - 2, dif > 0 ? 2 : 3, cnt + abs(dif));
	}
	else
	{
		int temp = dp(x - 1, dif > 0 ? 1 : -1, cnt + (abs(dif) + 2) / 3);
		
	}

	
	int temp = 0;
		
	temp = dp(x, 1, (cnt + dif + 2) / 3);	// (cnt + dif + 2) / 3 = 차이가 5면 -> (5+2)/3 = 2번 계산
	/*if (a == 0 || a == 1 || a == 2)
	{
		int temp = dp(x, 0, cnt + 1);
		for (int i = 1; i <= 7; i++)
		{
			if (i == 3 || i == 4 || i == 5) continue;
			temp = min(temp, dp(x, i, cnt + 1));
		}
		return temp;
	}
	if (a == 3 || a == 4 || a == 5)
	{
		int temp = dp(x, 3, cnt + 1);
		for (int i = 4; i <= 7; i++)
		{
			temp = min(temp, dp(x, i, cnt + 1));
		}
		return temp;
	}
	if (a == 6 || a == 7)
	{
		int temp = dp(x, 0, cnt + 1);
	}*/
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%1d", &init[i]);
	for (int i = 1; i <= n; i++) scanf("%1d", &pw[i]);

	
	return 0;
}