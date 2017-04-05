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

int n, a[100000], sz;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		// upper_bound : a~a+sz���̿��� a[i]���� ū ���� ó������ ������ ��ġ�� ã���ش�.
		// ��ȯ���� �������̹Ƿ� -a�� ����� �Ѵ�.
		int p = upper_bound(a, a + sz, a[i]) - a;
		if (p == sz) sz++;	//LIS����
		a[p] = a[i];		//�迭����
	}
	printf("%d", sz);
	return 0;
}