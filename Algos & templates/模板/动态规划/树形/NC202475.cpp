#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
vector<ll>tr[maxn]; ll n;
ll dp[maxn]; ll w[maxn];
void solve() {
	std::cin >> n;
	for (ll i = 1; i <= n; i++) {
		std::cin >> w[i];
	}
	for (ll i = 1; i <= n - 1; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	ll ans = -inf;
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		dp[u] = w[u]; ans = max(ans, dp[u]);
		for (auto v : tr[u]) {
			if (v == f) {
				continue;
			}
			dfs(v, u);
			ans = max(ans, dp[u] + dp[v]);
			dp[u] = max(dp[u], w[u] + dp[v]);
		}
	};
	dfs(1, 0);
	cout << ans << endl;
}
signed main() {
	solve();
}