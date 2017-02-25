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
		int to;
		int capacity;
		Edge *rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {
		}
	};
	int n;
	int source, sink;
	vector<vector<Edge *>> graph;
	MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
		graph.resize(n);
	};
	void add_edge(int u, int v, int cap) {
		Edge *ori = new Edge(v, cap);
		Edge *rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	int bfs() {
		vector<bool> check(n, false);
		vector<pair<int, int>> from(n, make_pair(-1, -1));				//
		queue<int> q;
		q.push(source);
		check[source] = true;
		while (!q.empty()) {													// bfs실행
			int x = q.front();
			q.pop();
			for (int i = 0; i<graph[x].size(); i++) {					// edge 돌면서
				if (graph[x][i]->capacity > 0 && !check[graph[x][i]->to]) {		// 간적없고 잔여용량이 0이넘는
					q.push(graph[x][i]->to);									// 간선따라가서 vertex를 push
					check[graph[x][i]->to] = true;
					from[graph[x][i]->to] = make_pair(x, i);					// to에 도달한 vertex와 간선을 push
				}
			}											// residual capacity가 0이 넘는 간선만 따라가기 때문에 bfs 회를 거듭할수록 그래프는 갱신되고
		}												// residual capacity가 남아있는 간선만 dfs가 된다.
		
		if (!check[sink]) {					// sink에 도달못했으면
			return 0;
		}
		int x = sink;												// residual capacity가 계속해서 갱신되고 그때마다 dfs가 되기 떄문에
		int c = graph[from[x].first][from[x].second]->capacity;		// 항상 capacity가 남아있는 vertex에서 sink에 도달했을 경우만 저장된다. 
		while (from[x].first != -1) {								// 도달한 간선을 역추적해서 flow 최소값 저장
			if (c > graph[from[x].first][from[x].second]->capacity) {
				c = graph[from[x].first][from[x].second]->capacity;
			}
			x = from[x].first;
		}
		x = sink;
		while (from[x].first != -1) {								
			Edge *e = graph[from[x].first][from[x].second];			// 도달한 간선 역추적하면서
			e->capacity -= c;										// residual capacity 갱신
			e->rev->capacity += c;									// reverse residual capacity 갱신
			x = from[x].first;
		}
		return c;													// source로 최종 갱신된 reverse residual capacity가 반환된다.
	}
	int flow() {
		int ans = 0;
		while (true) {
			int f = bfs();
			if (f == 0) break;
			ans += f;							// reverse residual capacity 누적
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