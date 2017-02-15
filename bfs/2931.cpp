#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>

#pragma warning (disable:4996)
using namespace std;

int sx, sy, tx, ty;
int r, c;
// 상하좌우
int dx[4] = { -1,1,0,0 } ;
int dy[4] = { 0,0,-1,1 };
// 방향 = 상하좌우
int n[4] = { 0,1,2,3 };
// find end
pair<int, int> fe(vector<string> &a, int x, int y)
{
	queue<pair<int, int> > q;
	queue<int> news;
	if ((x == sx && y == sy) || (x == tx && y == ty))
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (a[nx][ny] != '.' && a[nx][ny] != 'Z')
			{
				q.push(make_pair(nx, ny));
				if (a[nx][ny] == '1')
				{
					if (i == 2)
						news.push(1);
					if (i == 0);
					news.push(3);
				}
				else if (a[nx][ny] == '2')
				{
					if (i == 2)
						news.push(0);
					if (i == 1)
						news.push(3);
				}
				else if (a[nx][ny] == '3')
				{
					if (i == 1)
						news.push(2);
					if (i == 3)
						news.push(0);
				}
				else if (a[nx][ny] == '4')
				{
					if (i == 3)
						news.push(1);
					if (i == 0)
						news.push(2);
				}
				else
					news.push(i);
			}
		}
	}
	while (!q.empty())
	{
		int now_x = q.front().first;
		int now_y = q.front().second;
		int now_n = news.front();
		q.pop();
		news.pop();
		int nx = now_x + dx[now_n];
		int ny = now_y + dy[now_n];
		// | - + 1 2 3 4 
		if (a[nx][ny] == '.') return make_pair(nx, ny);
		if (now_n == 0)	// 방향 == 상
		{
			if (a[nx][ny] == '|' || a[nx][ny] == '+')
			{
				q.push(make_pair(nx, ny));
				news.push(now_n);
			}
			else if (a[nx][ny] == '1')
			{
				q.push(make_pair(nx, ny));
				news.push(3);
			}
			else if (a[nx][ny] == '4')
			{
				q.push(make_pair(nx, ny));
				news.push(2);
			}
		}
		else if (now_n == 1) // 방향 == 하
		{
			if (a[nx][ny] == '|' || a[nx][ny] == '+')
			{
				q.push(make_pair(nx, ny));
				news.push(now_n);
			}
			else if (a[nx][ny] == '2')
			{
				q.push(make_pair(nx, ny));
				news.push(3);
			}
			else if (a[nx][ny] == '3')
			{
				q.push(make_pair(nx, ny));
				news.push(2);
			}
		}
		else if (now_n == 2) // 방향 == 좌
		{
			if (a[nx][ny] == '-' || a[nx][ny] == '+')
			{
				q.push(make_pair(nx, ny));
				news.push(now_n);
			}
			else if (a[nx][ny] == '1')
			{
				q.push(make_pair(nx, ny));
				news.push(1);
			}
			else if (a[nx][ny] == '2')
			{
				q.push(make_pair(nx, ny));
				news.push(0);
			}
		}
		else if (now_n == 3) // 방향 == 우
		{
			if (a[nx][ny] == '-' || a[nx][ny] == '+')
			{
				q.push(make_pair(nx, ny));
				news.push(now_n);
			}
			else if (a[nx][now_y + dy[now_n]] == '3')
			{
				q.push(make_pair(nx, ny));
				news.push(0);
			}
			else if (a[nx][ny] == '4')
			{
				q.push(make_pair(nx, ny));
				news.push(1);
			}
		}
	}
}

int pw[28][28][4] = { 0, };
void put_way(vector<string> &a, int x, int y)
{
	char ch = a[x][y];
	if (ch == '|')
	{
		pw[x][y][0] = 1; pw[x][y][1] = 1;
	}
	else if (ch == '-')
	{
		pw[x][y][2] = 1; pw[x][y][3] = 1;
	}
	else if (ch == '+')
	{
		for (int i = 0; i < 4; i++)
			pw[x][y][i] = 1;
	}
	else if (ch == '1')
	{
		pw[x][y][1] = 1; pw[x][y][3] = 1;
	}
	else if (ch == '2')
	{
		pw[x][y][0] = 1; pw[x][y][3] = 1;
	}
	else if (ch == '3')
	{
		pw[x][y][0] = 1; pw[x][y][2] = 1;
	}
	else if (ch == '4')
	{
		pw[x][y][1] = 1; pw[x][y][2] = 1;
	}
	else
	{
		for (int i = 0; i < 4; i++)
			pw[x][y][i] = 0;
	}
}

int main()
{
	cin >> r >> c;
	vector<string> a(r + 2);
	for (int i = 1; i <= r; i++)
	{
		cin >> a[i];
		a[i] = "." + a[i] + ".";
	}
	r += 2;
	c += 2;
	for (int j = 0; j < c; j++)
	{
		a[0] += ".";
		a[r - 1] += ".";
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == 'M')
			{
				sx = i; sy = j;
			}
			if (a[i][j] == 'Z')
			{
				tx = i; ty = j;
			}
		}
	}
	//printf("%d %d %d %d\n", sx, sy, tx, ty);
	// BFS로 구현
	// 파이프가 있으면 cost 0, 없으면 cost 1

	pair<int, int> d1 = fe(a, sx, sy);

	// | - + 1 2 3 4
	/*
	   0 1 2 3 4 5 6
	   | - + 1 2 3 4
	상{1,0,1,0,1,1,0}
	하{1,0,1,1,0,0,1}
	좌{0,1,1,0,0,1,1}
	우{0,1,1,1,1,0,0}
	*/
	
	int x = d1.first;
	int y = d1.second;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		put_way(a, nx, ny);
	}
	char answ;
	if (pw[x + dx[0]][y + dy[0]][1] == 1)
	{
		if (pw[x + dx[1]][y + dy[1]][0] == 1)
		{
			if (pw[x + dx[2]][y + dy[2]][3] == 1)
				answ = '+';
			else
				answ = '|';
		}
		else if (pw[x + dx[2]][y + dy[2]][3] == 1)
		{
			answ = '3';
		}
		else answ = '2';
	}
	else if (pw[x + dx[1]][y + dy[1]][0] == 1)
	{
		if (pw[x + dx[2]][y + dy[2]][3] == 1)
			answ = '4';
		else
			answ = '1';
	}
	else
		answ = '-';
	
	printf("%d %d %c\n", x, y, answ);
	return 0;
}