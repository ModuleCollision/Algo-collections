#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	string s, t; std::cin >> s >> t;
	ll n = s.size(), m = t.size();
	s = " " + s; t = " " + t;
	vector dp(n + 5, vector<ll>(n + 5, 0));
	for (ll i = 1; i <= n; i++) {
		if (i > m or s[1] == t[i])dp[i][i] = 2;
	}
	//重构为 t[l -- r]的序列方法数
	for (ll len = 2; len <= n; len++) {
		for (ll l = 1; l + len - 1 <= n; l++) {
			ll r = l + len - 1;
			//向前转移
			if (s[len] == t[l] or len > m)dp[l][r] = (dp[l][r] % mod + dp[l + 1][r]) % mod;
			//向后转移
			if (s[len] == t[r] or len > m)dp[l][r] = (dp[l][r] % mod + dp[l][r - 1]) % mod;
		}
	}
	ll ans = 0;
	for (ll i = m; i <= n; i++) {
		ans = (ans % mod + dp[1][i]) % mod;
	}
	cout << ans << endl;
}
signed main() {
	//ll T; std::cin >> T;
	//while (T--)
	solve();
}