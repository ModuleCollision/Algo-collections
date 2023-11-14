#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
ll N, M;
struct sq {
	ll u; ll w; ll id;
};
struct cmp {
	bool operator()(array<ll, 2>x, array<ll, 2>y) {
		return x[0] >= y[0];
	}
};
ll u, v, w;
;
void solve() {
	std::cin >> N >> M;
	vector<ll>dis(N + 5, inf); vector<bool>vis(N + 5);
	vector<vector<sq>>tr(N + 5);
	for (ll i = 1; i <= M; i++) {
		std::cin >> u >> v >> w;
		tr[u].push_back({v, w, i});
		tr[v].push_back({u, w, i});
	}
	priority_queue<array<ll, 2>, vector<array<ll, 2>>, cmp>q;
	q.push({0, 1});
	dis[1] = 0; vector<ll>fa(N + 5);
	while (q.size()) {
		auto [d, u] = q.top();
		q.pop();
		vis[u] = 1;
		for (auto [v, w, idx] : tr[u]) {
			if (dis[v] > w + dis[u]) {
				dis[v] = min(dis[v], w + dis[u]);
				if (not vis[v]) {
					q.push({dis[v], v});
					fa[v] = idx;
				}
			}
		}
	}
	for (ll i = 2; i <= N; i++) {
		cout << fa[i] << " ";
	}
	cout << endl;
}
signed main() {

	solve();
}
