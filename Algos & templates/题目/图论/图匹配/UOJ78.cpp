#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, m, e; std::cin >> n >> m >> e;
	vector<ll>pa(n + 5, 0), pb(n + 5, 0), vis(n + 5, 0);
	ll dfn = 0, res = 0;
	vector<vector<ll>>tr(n + 5);
	for (ll i = 1; i <= e; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v);
	}
	function<bool(ll)>dfs = [&](ll u) {
		vis[u] = dfn;
		for (auto v : tr[u]) {
			if (not pb[v]) {
				pb[v] = u; pa[u] = v; return true;
			}
		}
		for (auto v : tr[u]) {
			if (vis[pb[v]] != dfn and dfs(pb[v])) {
				pa[u] = v; pb[v] = u; return true;
			}
		}
		return false;
	};
	while (1) {
		dfn++; ll cnt = 0;
		for (ll i = 1; i <= n; i++) {
			if (not pa[i] and dfs(i))cnt++;
		}
		if (not cnt)break;
		res += cnt;
	}
	cout << res << endl;
	for (ll i = 1; i <= n; i++) {
		cout << pa[i] << " ";
	}
	return;
}
signed main() {
	solve();
}