#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <stack>
#pragma warning (disable:4996)
using namespace std;
int main()
{
	stack<char> left, right;
	char ar[100001];
	scanf("%s", &ar);
	int len = strlen(ar);
	for (int i = 0; i < len; i++)
		left.push(ar[i]);
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		if (str == "P")
		{
			string temp;
			cin >> temp;
			int len2 = temp.length();
			for (int i = 0; i < len2; i++)
				left.push(temp[i]);
		}
		else if (str == "L")
		{
			if (left.size() != 0)
			{
				right.push(left.top());
				left.pop();
			}
		}
		else if (str == "D")
		{
			if (right.size() != 0)
			{
				left.push(right.top());
				right.pop();
			}
		}
		else if (str == "B")
		{
			if (left.size() != 0)
			{
				left.pop();
			}
		}
	}
	len = left.size();
	for (int i = 0; i < len; i++)
	{
		right.push(left.top());
		left.pop();
	}
	len = right.size();
	for (int i = 0; i < len; i++)
	{
		printf("%c", right.top());
		right.pop();
	}
	printf("\n");
	return 0;
}