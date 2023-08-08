#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
ll N, K;
ll dp[maxn][maxn];
vector<pair<ll, ll>>tr[maxn];
ll sz[maxn];
void solve() {
	std::cin >> N >> K;
	for (ll i = 1; i <= N - 1; i++) {
		ll u, v, w; std::cin >> u >> v >> w;
		tr[u].push_back({v, w});
		tr[v].push_back({u, w});
	}
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		dp[u][0] = dp[u][1] = 1; sz[u] = 1;
		for (auto s : tr[u]) {
			ll w = s.second, v = s.first;
			if (v == f)continue;
			dfs(v, u);
			vector<ll>tmp(sz[u] + sz[v] + 5, 0);
			for (ll i = 0; i <= min(K, sz[u]); i++) {
				for (ll j = 0; j <= min(K - i, sz[v]); j++) {
					ll k = i * j * w + (sz[u] - i) * (sz[v] - j) * w;
					tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j] + k);
				}
			}
			for (ll i = 0; i <= sz[u] + sz[v]; i++) {
				dp[u][i] = tmp[i];
			}
			sz[u] += sz[v];
		}
	};
	dfs(1, 1);
	cout << dp[1][K] << endl;
}
signed main() {
	solve();
}