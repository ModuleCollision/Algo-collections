#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
bool mp[maxn]; ll n; vector<ll>tr[maxn];
ll fa[maxn], dep[maxn]; bool vis[maxn];
ll c[maxn];
void dfs1(ll u, ll f) {
	dep[u] = dep[f] + 1;
	fa[u] = f;
	vis[u] = true;
	for (auto v : tr[u]) {
		if (not vis[v]) {
			dfs1(v, u);
		} else if (v != f) {
			if (dep[v] < dep[u]) {
				for (ll j = u; j != v; j = fa[j]) {
					mp[j] = true;
				}
				mp[v] = true;
				return;
			}
		}
	}
	return;
}
void solve() {
	std::cin >> n;
	for (ll i = 1; i <= n; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	dfs1(1, 0);//dfs生成树
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
	for (ll i = 1; i <= n; i++) {
		if (mp[i])bfs(i);
	}
	ll q; std::cin >> q;
	while (q--) {
		ll u, v; std::cin >> u >> v;
		if (c[u] == c[v]) {
			puts("Yes");
		} else puts("No");
	}
}
signed main() {
	solve();
}