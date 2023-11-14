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
ll dp[5005];
void solve() {
	ll n; std::cin >> n;
	vector<vector<ll>>tr(n + 1);
	for (ll i = 2; i <= n; i++) {
		ll v; std::cin >> v; tr[i].push_back(v);
		tr[v].push_back(i);
	}
	vector<ll>sz(n + 1);
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		sz[u] = 1;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			sz[u] += sz[v];
		}
	};
	ll ret = 0;
	function<void(ll, ll, ll)>dfs2 = [&](ll u, ll f, ll len) {
		vector<ll>pr; ll tot = 0;
		for (auto v : tr[u]) {
			if (v == f)continue; pr.push_back(sz[v]);
			tot += sz[v];
		}
		if (len == 1) {
			return;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (auto v : pr) {
			for (ll j = tot; j >= v; j--)dp[j] |= dp[j - v];
		}
		ll ans = 0;
		for (ll j = 0; j <= tot; j++)if (dp[j])ans = max(ans, j * (tot - j));
		ret += ans;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs2(v, u, sz[v]);
		}
	};
	dfs(1, 0); dfs2(1, 0, n);
	//for (ll i = 1; i <= n; i++)cout << a[i] << " ";
	cout << ret << endl;
}
signed main() {
	solve();
}