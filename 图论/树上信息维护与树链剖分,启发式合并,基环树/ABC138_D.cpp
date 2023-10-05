#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e7 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll dfn[maxn]; ll rk[maxn]; ll sz[maxn]; ll cnt = 0;
ll d[maxn];
void solve() {
	ll n, q; std::cin >> n >> q;
	vector<vector<ll>>tr(n + 1);
	for (ll i = 1; i <= n - 1; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		++cnt; dfn[u] = cnt; rk[cnt] = u; sz[u] = 1;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			sz[u] += sz[v];
		}
	};
	dfs(1, 0);
	while (q--) {
		ll p, x; std::cin >> p >> x;
		d[dfn[p]] += x;
		d[dfn[p] + sz[p]] -= x;
	}
	for (ll i = 1; i <= n; i++)d[i] += d[i - 1];
	for (ll i = 1; i <= n; i++)cout << d[dfn[i]] << " ";
}
signed main() {
	solve();
}