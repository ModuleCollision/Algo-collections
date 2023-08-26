#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m, k, d; std::cin >> n >> m >> k >> d;
	vector dp(m + 5, vector<ll>(d + 5, 0));
	//顺推
	auto inv = [&](ll x) {
		ll b = mod - 2; ll ret = 1;
		while (b) {
			if (b & 1)ret = ret * x % mod;
			x = x * x % mod;
			b >>= 1;
		}
		return ret % mod;
	};
	ll q = k % mod * inv(n) % mod;
	ll p = ((1 - q) % mod + mod) % mod;
	for (ll i = m - 1; i >= 0; i--) {
		for (ll j = d - 2; j >= 0; j--) {
			dp[i][j] = (dp[i][j] % mod + dp[i + 1][j + 1] % mod * p) % mod;//没有获奖
			dp[i][j] = (dp[i][j] % mod + (dp[i + 1][0] + 1) % mod * q) % mod;//获奖了
		}
		dp[i][d - 1] = (dp[i][d - 1] % mod + dp[i + 1][0] + 1) % mod;
	}
	cout << dp[0][0] % mod*n % mod << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}