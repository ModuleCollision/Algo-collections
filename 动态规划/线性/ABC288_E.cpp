#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
ll lg[maxn]; ll st[maxn][20];
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<ll>A(n + 5, 0), C(n + 5, 0);
	std::vector<bool>vis(m + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	for (ll i = 1; i <= n; i++)cin >> C[i], st[i][0] = C[i];
	for (ll i = 1; i <= m; i++) {
		ll v; std::cin >> v;
		vis[v] = 1;
	}
	for (ll i = 2; i < maxn; i++)lg[i] = (lg[i >> 1] + 1);
	for (ll len = 1; (1 << len) <= n; len++) {
		for (ll i = 1; (i + (1 << len) - 1) <= n; i++) {
			st[i][len] = min(st[i][len - 1], st[i + (1 << (len - 1))][len - 1]);
		}
	}
	auto query = [&](ll l, ll r) {
		int x = lg[r - l + 1];
		return min(st[l][x], st[r - (1 << x) + 1][x]);
	};
	vector dp(n + 5, vector<ll>(n + 5, inf));
	dp[0][0] = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= i; j++) {
			if (j)dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + A[i] + query(i - j + 1, i));
			if (not vis[i])dp[i][j] = min(dp[i][j], dp[i - 1][j]);
		}
	}
	ll ans = inf;
	for (ll i = 0; i <= n; i++)ans = min(ans, dp[n][i]);
	cout << ans << endl;
}
signed main() {
	solve();
}