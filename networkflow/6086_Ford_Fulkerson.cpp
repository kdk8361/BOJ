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
			if (graph[x][i]->capacity > 0) {        // 잔여용량이 있고
				int nc = graph[x][i]->capacity;
				if (c != 0 && c < nc) {                // 잔여용량보다 유입량이 적으면
					nc = c;                            // 잔여용량보다 많을 수 없으므로 유출량 = 유입량 
				}
				int f = dfs(graph[x][i]->to, nc);    // 간선따라 dfs 진행. 현재노드부터 싱크까지 augmenting path에서 flow의 최소값이 반환됨.
				if (f) {                            // 아직 진행하지 않은 augmenting path가 있다면
					graph[x][i]->capacity -= f;        // residual capacity - m
					graph[x][i]->rev->capacity += f;    // reverse residual capacity + m (반환가능용량)
					return f;
				}
			}
		}
		return 0;                                    // augmenting path가 없다면 루프가 끝나고 0리턴
	}
	int flow() {                                    // maximum flow 찾기
		int ans = 0;
		while (true) {
			fill(check.begin(), check.end(), false);
			int f = dfs(source, 0);                    // source에서 dfs시작
			if (f == 0) break;                        // 남은 augmenting path가 없으면 break
			ans += f;                                // source까지 올라온 reverse residual capacity 누적.
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