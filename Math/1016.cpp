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
	vector<long long> v;			//소수저장용 벡터
	v.push_back(2);
	long long right = sqrt(b) + 1;
	for (long long i = 3; i <= right; i += 2) {		//짝수는 관심없음
		if (pn[i]) continue;
		long long t = i*i;				//t이전의 2,3,4,,,t-1까지는 모두 조사했기 때문에 t*t로 바로 점프
		v.push_back(i);
		while (t <= right) {			//b^(1/2)까지만 조사하면 된다
			pn[t] = true;
			t += 2 * i;					// t는 홀수이고 홀수를 더하면 짝수이므로 스킵
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