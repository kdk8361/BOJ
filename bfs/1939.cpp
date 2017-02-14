#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

#pragma warning (disable:4996)
using namespace std;
int weight[10006] = { 0, };	// weight[i] = s에서 i까지 갈때 최대이동가능중량

int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int n, m;
	int u, v, w;
	int s, e;
	scanf("%d %d", &n, &m);
	vector<pair<int, int> > a[10006];		// 간선, w
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		a[u].push_back(make_pair(v, w));
		a[v].push_back(make_pair(u, w));
	}

	scanf("%d %d", &s, &e);
	weight[s] = 1e9 * 2;
	queue<pair<int, int> > q;		// q.first = 현재 위치, q.second = s -> q.first까지 최대 이동가능중량
	q.push(make_pair(s, weight[s]));
	
	while (!q.empty())
	{
		int nx = q.front().first;
		int nw = q.front().second;
		q.pop();

		int size = a[nx].size();
		for (int i = 0; i < size; i++)
		{
			a[nx].at(i).second = min(a[nx].at(i).second, nw);
			if (weight[a[nx].at(i).first] < a[nx].at(i).second)
			{
				weight[a[nx].at(i).first] = a[nx].at(i).second;
				q.push(make_pair(a[nx].at(i).first, weight[a[nx].at(i).first]));
			}
		}
	}

	printf("%d\n", weight[e]);
	
	return 0;
}