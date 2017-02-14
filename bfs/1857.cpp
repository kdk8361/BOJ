#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#pragma warning (disable:4996)
using namespace std;

int m, n;
long long a[31][31] = { 0, };
// d[i][j] = sx,sy에서 i,j까지 가려고 할 때 필요한 최소 방석 개수
long long d[31][31] = { 0, };
// 들렀나 체크
bool check[31][31] = { false, };
int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };

int main()
{
	cin >> m >> n;
	int sx, sy, tx, ty;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 3)
			{
				sx = i; sy = j;
			}
			if (a[i][j] == 4)
			{
				tx = i; ty = j;
			}
			if (a[i][j] == 2)
				d[i][j] = -1e9;
		}
	}
	
	deque<pair<int, int> > q;
	q.push_back(make_pair(sx, sy));
	d[sx][sy] = 0;
	d[tx][ty] = 9223372036854775807;
	
	long long ans = 0;
	while (!q.empty())
	{
		int i = 0;
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > m || ny > n) continue;
			if (check[nx][ny]) continue;
			if (a[nx][ny] == 3 || a[nx][ny] == 2) continue;
			if (a[nx][ny] == 4)
			{
				if (d[nx][ny] == d[x][y])
				{
					ans += 1;
				}
				else if (d[nx][ny] > d[x][y])
				{
					ans = 1;
					d[nx][ny] = min(d[nx][ny], d[x][y]);
				}
			}
			if (a[nx][ny] == 1)
			{
				check[nx][ny] = true;
				q.push_front(make_pair(nx, ny));
				d[nx][ny] = d[x][y];
			}
			if (a[nx][ny] == 0)
			{
				check[nx][ny] = true;
				q.push_back(make_pair(nx, ny));
				d[nx][ny] = d[x][y] + 1;
			}
		}
	}
	/*printf("\n");
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%lld ", d[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
	
	if (d[tx][ty] == 9223372036854775807)
		printf("-1\n");
	else
	{
		printf("%lld\n", d[tx][ty]);
		printf("%lld\n", ans);
	}
	return 0;
}