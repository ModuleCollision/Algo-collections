#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll n, A[maxn], sz[maxn];
ll dp[maxn][2];
void solve() {
	auto check = [&](ll x) {
		ll q = (ll)sqrt(x);
		return q * q == x;
	};
	cin >> n;
	for (ll i = 1; i <= n; i++)cin >> A[i];
	vector<vector<ll>>tr(n + 1);
	for (ll i = 1; i <= n - 1; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		sz[u] = 1;
		ll cs = 0;
		vector<bool>tmp(tr[u].size() + 1, 0);
		for (ll i = 0; i < tr[u].size(); i++) {
			ll v = tr[u][i];
			if (v == f)continue;
			dfs(v, u);
			dp[u][0] += max(dp[v][1], dp[v][0]);
			if (dp[v][1] >= dp[v][0]) {
				tmp[i] = true; cs += dp[v][1];
			} else {
				tmp[i] = false; cs += dp[v][0];
			}
			sz[u] += sz[v];
		}
		for (ll i = 0; i < tr[u].size(); i++) {
			if (tr[u][i] == f)continue;
			ll v = tr[u][i]; ll t = cs;
			if (check(A[u] * A[v])) {
				t -= dp[v][tmp[i]];
				t += dp[v][0];
				dp[u][1] = max(dp[u][1], t + 2);
			}
		}
	};
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]) << endl;
}
signed main() {
	solve();
}