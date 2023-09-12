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
	vector dp(n + 5, vector<ll>(k + 5, 0));
	vector pre(n + 5, vector<ll>(k + 5, 0));
	ll off = 1;
	dp[0][0 + off] = 1;
	pre[0][0 + off] = 1;
	for (ll j = 1; j <= k; j++)pre[0][j + off] = pre[0][j - 1 + off];
	for (ll i = 1; i <= n; i++) {
		for (ll j = i; j <= k; j++) {
			ll s = min(j, m);
			ll v = ((pre[i - 1][j - 1 + off] - pre[i - 1][j - s - 1 + off]) % mod + mod) % mod;

			dp[i][j + off] = (dp[i][j + off] % mod + v) % mod;
		}
		for (ll j = 1; j <= k; j++) {
			pre[i][j + off] = (pre[i][j + off - 1] % mod + dp[i][j + off]) % mod;
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= k; i++)ans = (ans % mod + dp[n][i + off]) % mod;
	cout << ans << endl;
}
signed main() {
	solve();
}