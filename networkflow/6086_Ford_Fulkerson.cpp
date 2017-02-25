#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct MaximumFlow {
	struct Edge {
		int to;                    // target vertex
		int capacity;
		Edge *rev;                // reverse edge
		Edge(int to, int capacity) : to(to), capacity(capacity) {
		}
	};
	int n;
	int source, sink;
	vector<vector<Edge *>> graph;
	vector<bool> check;
	// n : # of vertex
	MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
		graph.resize(n);
		check.resize(n);
	};
	void add_edge(int u, int v, int cap) {
		Edge *ori = new Edge(v, cap);
		Edge *rev = new Edge(u, 0);                // reverse
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	int dfs(int x, int c) {
		if (check[x]) return 0;
		check[x] = true;
		if (x == sink) {
			return c;
		}
		for (int i = 0; i<graph[x].size(); i++) {
			if (graph[x][i]->capacity > 0) {        // �ܿ��뷮�� �ְ�
				int nc = graph[x][i]->capacity;
				if (c != 0 && c < nc) {                // �ܿ��뷮���� ���Է��� ������
					nc = c;                            // �ܿ��뷮���� ���� �� �����Ƿ� ���ⷮ = ���Է� 
				}
				int f = dfs(graph[x][i]->to, nc);    // �������� dfs ����. ��������� ��ũ���� augmenting path���� flow�� �ּҰ��� ��ȯ��.
				if (f) {                            // ���� �������� ���� augmenting path�� �ִٸ�
					graph[x][i]->capacity -= f;        // residual capacity - m
					graph[x][i]->rev->capacity += f;    // reverse residual capacity + m (��ȯ���ɿ뷮)
					return f;
				}
			}
		}
		return 0;                                    // augmenting path�� ���ٸ� ������ ������ 0����
	}
	int flow() {                                    // maximum flow ã��
		int ans = 0;
		while (true) {
			fill(check.begin(), check.end(), false);
			int f = dfs(source, 0);                    // source���� dfs����
			if (f == 0) break;                        // ���� augmenting path�� ������ break
			ans += f;                                // source���� �ö�� reverse residual capacity ����.
		}
		return ans;
	}
};
int node(string s) {
	if (s[0] >= 'A' && s[0] <= 'Z') {
		return s[0] - 'A';
	}
	else {
		return s[0] - 'a' + 26;
	}
}
int main() {
	int m;
	cin >> m;
	MaximumFlow mf(52, 0, 'Z' - 'A');
	for (int i = 0; i<m; i++) {
		string us, vs;
		int f;
		cin >> us >> vs >> f;
		int u = node(us);
		int v = node(vs);
		mf.add_edge(u, v, f);
		mf.add_edge(v, u, f);
	}
	cout << mf.flow() << '\n';
	return 0;
}