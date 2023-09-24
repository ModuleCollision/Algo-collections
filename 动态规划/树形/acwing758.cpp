#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll N; std::cin >> N;
	vector<ll>c(N + 5, 0);
	vector<vector<ll>>tr(N + 5);
	vector<vector<ll>>dp(N + 5, vector<ll>(4, 0));
	for (ll i = 2; i <= N; i++) {
		ll p; std::cin >> p; p++;
		tr[p].push_back(i);
	}
	for (ll i = 1; i <= N; i++)cin >> c[i];
	auto inv = [&](ll x) {
		ll ret = 1; ll b = mod - 2;
		while (b) {
			if (b & 1)ret = ret * x % mod;
			x = x * x % mod;
			b >>= 1;
		}
		return ret;
	};
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		if (c[u] == 0) {
			dp[u][0] = 1; dp[u][1] = 0;
			for (auto v : tr[u]) {
				if (v == f)continue;
				dfs(v, u);
				dp[u][0] = (dp[u][0] % mod) * (dp[v][1] % mod + dp[v][0]) % mod;
			}
		} else {
			dp[u][0] = 0; dp[u][1] = 1;
			for (auto v : tr[u]) {
				if (v == f)continue;
				dfs(v, u);
				dp[u][1] = (dp[u][1] % mod) * (dp[v][0] % mod + dp[v][1] % mod) % mod;
			}
			for (auto v : tr[u]) {
				if (v == f)continue;
				ll k = inv((dp[v][0] % mod + dp[v][1]) % mod) % mod;
				dp[u][0] = (dp[u][0] % mod + dp[v][0] % mod * dp[u][1] % mod * k % mod) % mod;
			}
		}
	};
	dfs(1, 1);
	cout << dp[1][0] << endl;
}
signed main() {
	solve();
}
