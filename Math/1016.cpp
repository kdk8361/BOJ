#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <memory.h>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#pragma warning(disable:4996) 
using namespace std;

bool pn[1000002];

int main() {
	long long a, b;
	cin >> a >> b;

	long long ans = b - a + 1;
	vector<long long> v;			//�Ҽ������ ����
	v.push_back(2);
	long long right = sqrt(b) + 1;
	for (long long i = 3; i <= right; i += 2) {		//¦���� ���ɾ���
		if (pn[i]) continue;
		long long t = i*i;				//t������ 2,3,4,,,t-1������ ��� �����߱� ������ t*t�� �ٷ� ����
		v.push_back(i);
		while (t <= right) {			//b^(1/2)������ �����ϸ� �ȴ�
			pn[t] = true;
			t += 2 * i;					// t�� Ȧ���̰� Ȧ���� ���ϸ� ¦���̹Ƿ� ��ŵ
		}
	}
	memset(pn, 1, sizeof(pn));
	for (long long i = 0; i < v.size(); i++) {
		long long multi = v[i] * v[i];
		long long left = ((a + multi - 1) / multi)*multi;
		for (long long j = left; j <= b; j += multi)
			pn[j - a] = false;
	}
	int cnt = 0;
	for (int i = 0; i < ans; i++)
		cnt += pn[i];
	cout << cnt << '\n';
	return 0;
}