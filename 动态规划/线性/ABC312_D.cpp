#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	string s; std::cin >> s ;
	ll n = s.size();
	s = " " + s;
	vector dp(n + 5, vector<ll>(n + 5, 0));
	dp[0][0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= n; j++) {
			if (s[i] == '(') {
				if (j >= 1)dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - 1]) % mod;
			} else if (s[i] == ')') {
				dp[i][j] = (dp[i - 1][j + 1]) % mod;
			} else {
				dp[i][j] = (dp[i][j] % mod + dp[i - 1][j + 1]) % mod;
				if (j >= 1)dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - 1]) % mod;
			}
		}
	}
	cout << dp[n][0] % mod << endl;
}
signed main() {
	solve();
}