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
		// upper_bound : a~a+sz사이에서 a[i]보다 큰 값이 처음으로 나오는 위치를 찾아준다.
		// 반환값이 포인터이므로 -a를 해줘야 한다.
		int p = upper_bound(a, a + sz, a[i]) - a;
		if (p == sz) sz++;	//LIS길이
		a[p] = a[i];		//배열갱신
	}
	printf("%d", sz);
	return 0;
}