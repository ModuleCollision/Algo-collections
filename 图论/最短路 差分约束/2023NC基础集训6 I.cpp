#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
struct edge {
	ll u; ll v; ll w; ll nex;
} e[maxn];
ll head[maxn]; ll tot_edge = 0;
void solve() {
	ll n, m; std::cin >> n >> m;
	fill(head + 1, head + 1 + n, -1);
	auto add = [&](ll u, ll v, ll w) {
		e[tot_edge].u = u; e[tot_edge].v = v;
		e[tot_edge].w = w; e[tot_edge].nex = head[u];
		head[u] = tot_edge++;
	};
	ll ans = 0; ll u, v, w;
	for (ll i = 1; i <= m; i++) {
		std::cin >> u >> v >> w;
		add(u, v, w); add(v, u, w);
		if (u == 1 or v == 1)ans = w;
	}
	vector<ll>dis(n + 5, inf); vector<bool>vis(n + 5, 0);
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>>q;
	dis[1] = 0; q.push({0, 1});
	while (q.size()) {
		auto [d, u] = q.top(); q.pop();
		vis[u] = 1;
		for (ll j = head[u]; j != -1; j = e[j].nex) {
			ll v = e[j].v;
			if (dis[v] > d + 1) {
				dis[v] = d + 1;
				if (not vis[v]) {
					q.push({dis[v], v});
				}
			}
		}
	}
	if (dis[n] == m) {
		cout << ans + m - 1 << endl;
	} else {
		cout << dis[n] << endl;
	}
}
signed main() {
	solve();
}