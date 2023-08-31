#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll fa[maxn]; ll sz[maxn];
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<vector<ll>>tr(n + 1);
	vector<vector<ll>>p(n + 1);
	for (ll i = 1; i <= n - 1; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	for (ll i = 1; i <= m; i++) {
		ll u, v; std::cin >> u >> v;
		p[u].push_back(v); p[v].push_back(u);
	}
	for (ll i = 1; i <= n; i++)fa[i] = i;
	auto find = [&](ll x) {
		while (x != fa[x])x = fa[x] = fa[fa[x]];
		return x;
	};
	auto merge = [&](ll a, ll b) {
		ll x = find(a), y = find(b);
		if (x == y)return;
		fa[x] = y; sz[y] += sz[x];
	};
	vector<ll>f(n + 5, 0);
	vector<ll>dep(n + 5); vector<vector<ll>>ws;
	dep[1] = 1;
	auto bfs = [&]() {
		deque<ll>q; q.push_back(1);
		while (q.size()) {
			ll sz = q.size();
			vector<ll>lay;
			for (ll i = 0; i < sz; i++) {
				auto cur = q.front();
				q.pop_front();
				lay.push_back(cur);
				for (auto v : tr[cur]) {
					if (dep[v])continue;
					dep[v] = dep[cur] + 1;
					f[v] = cur;
					q.push_back(v);
				}
			}
			ws.push_back(lay);
		}
	};
	bfs();
	vector<ll>dp(n + 5, 0);
	for (ll i = ws.size() - 1; i >= 0; i--) {
		if (not ws[i].size())continue;
		auto &lay = ws[i];
		for (auto u : ws[i]) {
			if (tr[u].size() == 1) {
				dp[u] = 1; continue;
			}
			for (auto v : tr[u]) {
				if (v == f[u])continue;
				dp[u] = (dp[u] % mod + dp[v]) % mod;
			}
		}
		for (auto u : lay) {
			sz[u] = dp[u] % mod;
		}
		for (auto u : lay) {
			for (auto v : p[u])merge(u, v);
		}
		for (auto u : lay) {
			dp[u] = sz[find(u)] % mod;
		}
	}
	cout << dp[1] % mod << endl;
}
signed main() {
	solve();
}