#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
struct edge {
	int v; int w;
};
vector<edge>e[maxn]; int s, n, m, d[maxn], st[maxn];
struct node {
	int low; int u;
	bool operator<(const node &b)const {
		return low < b.low;
	}
};
void bfs() {
	for (int i = 1; i <= n; i++) {
		d[i] = -inf;
	}
	d[s] = inf;
	priority_queue<node>q;
	q.push({d[s], s});
	while (!q.empty()) {
		auto [vol, u] = q.top();
		q.pop();
		st[u] = 1;
		for (auto ed : e[u]) {
			int v = ed.v, w = ed.w;
			if (d[v] < min(w, vol)) {
				d[v] = min(w, vol);
			}
			if (st[v]) {
				continue;
			}
			q.push({d[v], v});
		}
	}
}
signed main() {

	std::cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		e[u].push_back({v, w});
	}
	bfs();
	for (int i = 1; i <= n; i++) {
		if (d[i] == -inf or i == s) {
			cout << -1 << " ";
		} else {
			cout << d[i] << " ";
		}
	}
	return 0;
}
