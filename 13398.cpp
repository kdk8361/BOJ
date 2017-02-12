#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int n;
int a[100001];

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int b = 0;
	int c = 0;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		c = max(b, c + a[i]);
		b = max(b + a[i], a[i]);
		ans = max(max(ans, b), c);
		//printf("%d %d\n", b, c);
	}

	cout << ans;
	return 0;
}