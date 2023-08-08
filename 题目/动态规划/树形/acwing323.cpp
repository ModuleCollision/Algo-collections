#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N, dp[maxn][2];
ll u, v; vector<ll>tr[maxn];
void solve() {
	for (ll i = 1; i <= N; i++) {
		tr[i].clear();
	}
	memset(dp, 0, sizeof(dp));
	for (ll i = 1; i <= N - 1; i++) {
		std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		dp[u][0] = 0; dp[u][1] = 1;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			dp[u][1] += min(dp[v][1], dp[v][0]);
			dp[u][0] += dp[v][1];
		}
	};
	dfs(1, 1);
	cout << min(dp[1][1], dp[1][0]) << endl;
}
signed main() {
	while (cin >> N)solve();
}