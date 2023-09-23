#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m; std::cin >> n >> m;
	std::map<ll, db>dp;
	vector<vector<pair<ll, ll>>>tr(n + 5);
	for (ll i = 1; i <= m; i++) {
		ll u, v, w; std::cin >> u >> v >> w;
		tr[u].push_back({v, w});
	}
	function<db(ll)>dfs = [&](ll u) {
		if (dp.count(u))return dp[u];
		dp[u] = 0.0;
		db ret = 0.0;
		db k = 1.0 / (tr[u].size());
		for (auto [v, w] : tr[u]) {
			ret += ((db)dfs(v) + w) * k;
		}
		dp[u] = ret;
		return ret;
	};
	printf("%.2lf", dfs(1));
}
signed main() {
	solve();
}