#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N, w[maxn];
vector<ll>tr[maxn];
ll dp[maxn][2];
ll r, d[maxn];
void solve() {
	std::cin >> N;
	for (ll i = 1; i <= N; i++) {
		std::cin >> w[i];
	}
	for (ll i = 1; i <= N - 1; i++) {
		ll u, v; std::cin >> u >> v;
		tr[v].push_back(u);
		d[u]++;
	}
	for (ll i = 1; i <= N; i++) {
		if (not d[i]) {
			r = i; break;
		}
	}
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		dp[u][1] = w[u];
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			dp[u][1] += dp[v][0];
			dp[u][0] += max(dp[v][1], dp[v][0]);
		}
	};
	dfs(r, r);
	cout << max(dp[r][1], dp[r][0]) << endl;
}
signed main() {
	solve();
}