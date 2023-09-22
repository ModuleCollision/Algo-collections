#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, a, b; std::cin >> n >> a >> b;
	vector<vector<ll>>tr(n + 1);
	for (ll i = 1; i <= n; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	vector<ll>dep(n + 1);
	vector<ll>fa(n + 1); vector<bool>vis(n + 1);
	vector<bool>mp(n + 1);
	vector<ll>c(n + 1);
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		dep[u] = dep[f] + 1;
		fa[u] = f;
		vis[u] = true;
		for (auto v : tr[u]) {
			if (not vis[v])dfs(v, u);
			else if (v != f) {
				if (dep[v] < dep[u]) {
					for (ll j = u; j != v; j = fa[j]) {
						mp[j] = true;
					}
					mp[v] = true;
					return;
				}
			}
		}
		vis[u] = false;
		return;
	};
	dfs(1, 0);
	auto bfs = [&](ll t) {
		queue<ll>q;
		q.push(t); c[t] = t;
		while (q.size()) {
			auto u = q.front(); q.pop();
			for (auto v : tr[u]) {
				if (c[v] or mp[v])continue;
				c[v] = t; q.push(v);
			}
		}
	};
	if (a == b) {
		puts("NO"); return;
	}
	if (mp[b]) {
		puts("YES"); return;
	} else {
		for (ll i = 1; i <= n; i++)if (mp[i])bfs(i);
		ll t = c[b];
		vector<ll>dis(n + 1, -1);
		auto bfs2 = [&](ll u) {
			queue<ll>q; q.push(u); dis[u] = 1;
			while (q.size()) {
				auto u = q.front(); q.pop();
				for (auto v : tr[u]) {
					if (dis[v] != -1)continue;
					dis[v] = dis[u] + 1;
				}
			}
		};
		bfs2(t);
		if (dis[b] >= dis[a])puts("NO");
		else puts("YES");
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}