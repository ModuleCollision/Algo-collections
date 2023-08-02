#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6+  5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
vector<ll>tr[maxn]; ll n, x, y;
ll dp[maxn][2];
void solve() {
	std::cin >> n >> x >> y;
	for (ll i = 1; i <= n - 1; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	auto inv = [&](ll a) {
		ll ret = 1, b = mod - 2;
		while (b) {
			if (b & 1) {
				ret = ret * a % mod;
			}
			a = a * a % mod;
			b >>= 1;
		}
		return ret;
	};
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		dp[u][0] = x, dp[u][1] = y;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			dp[u][0] = (dp[u][0] % mod * (dp[v][0] % mod + dp[v][1]) % mod) % mod;
			dp[u][1] = (dp[u][1] % mod * (dp[v][0] % mod + dp[v][1] % mod * (y - 1) % mod * inv(y) % mod) % mod) % mod;
		}
        return;
	};
	dfs(1, 0);
	cout << (dp[1][0] % mod + dp[1][1]) % mod << endl;
}
signed main() {
	solve();
}