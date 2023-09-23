#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m, k; std::cin >> n >> m >> k;
	vector dp(k + 2, vector<ll>(n + 1, 0));
	std::vector<vector<ll>>tr(n + 1);
	std::set<pair<ll, ll>>st;
	while (m--) {
		ll u, v; std::cin >> u >> v; if (u > v)swap(u, v);
		tr[u].push_back(v); tr[v].push_back(u);
	}
	dp[0][1] = 1; ll pre = 1;
	for (ll i = 1; i <= k; i++) {
		ll cur = pre; pre = 0;
		for (ll j = 1; j <= n; j++) {
			dp[i][j] = (dp[i][j] % mod + (cur - dp[i - 1][j]) % mod + mod) % mod;
			for (auto v : tr[j]) {
				dp[i][j] = ((dp[i][j] - dp[i - 1][v]) % mod + mod) % mod;
			}
			pre = (pre % mod + dp[i][j]) % mod;
		}
	}
	cout << dp[k][1] % mod << endl;
}
signed main() {
	solve();
}