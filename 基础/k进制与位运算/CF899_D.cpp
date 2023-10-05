#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e7 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n; vector<ll>A(n + 1, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	vector<vector<ll>>tr(n + 1);
	for (ll i = 1; i <= n - 1; i++) {
		ll u, v; std::cin >> u >> v; tr[u].push_back(v);
		tr[v].push_back(u);
	}
	vector<ll>dp(n + 1, 0); auto sz = dp;
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		sz[u] = 1;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			sz[u] += sz[v];
			dp[u] += sz[v] * (A[u] ^ A[v]) + dp[v];
		}
	};
	vector<ll>ans(n + 1, 0);
	function<void(ll, ll)>dfs2 = [&](ll u, ll f) {
		ans[u] = dp[u];
		for (auto v : tr[u]) {
			if (v == f)continue;
			ll szv = sz[v], szu = sz[u], dpu = dp[u], dpv = dp[v];
			dp[u] -= dp[v] + sz[v] * (A[u] ^ A[v]); sz[u] -= sz[v];
			dp[v] += sz[u] * (A[u] ^ A[v]) + dp[u];
			sz[v] += sz[u];
			dfs2(v, u);
			dp[u] = dpu; dp[v] = dpv; sz[u] = szu; sz[v] = szv;
		}
	};
	dfs(1, 0); dfs2(1, 0);
	for (ll i = 1; i <= n; i++)cout << ans[i] << " ";
	cout << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T --) solve();
}