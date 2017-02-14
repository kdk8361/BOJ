#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#pragma warning (disable:4996)
using namespace std;

long long min(long long a, long long b)
{
	return a > b ? b : a;
}

int main()
{
	long long n, m;
	cin >> n >> m;

	long long a[10001];

	long long g = 1;
	long long max_a = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		max_a = max(max_a, a[i]);
	}

	// ÃÖ¾ÇÀÇ °æ¿ì = (n-(m-1))/m

	long long right = (n + (m - 1)) / m * max_a;
	long long left = 1;
	long long ans = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < m; i++)
		{
			sum += (mid + a[i] - 1) / a[i];
		}
		if (sum >= n)
			right = mid - 1; 
		else 
		{
			ans = mid;
			left = mid + 1;
		}
	}

	vector<pair<long long, long long> > v;
	long long sum = 0;
	for (long long i = 0; i < m; i++)
	{
		v.push_back(make_pair(ans%a[i], i + 1));
		sum += (ans + a[i] - 1) / a[i];
	}

	sort(v.begin(), v.end());
	/*for (int i = 0; i < m; i++)
	{
		printf("%d %d\n", v.at(i).first, v.at(i).second);

	}*/

	printf("%d\n", v.at(n - sum - 1).second);

	return 0;
}