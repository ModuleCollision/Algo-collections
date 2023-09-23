/*期望dp*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, p; std::cin >> n >> p;
	vector dp(n + 5, 0);
	dp[0] = 0;
	auto inv = [&](ll x) {
		ll b = mod - 2; ll ret = 1;
		while (b) {
			if (b & 1)ret = ret * x % mod;
			x = x * x % mod;
			b >>= 1;
		}
		return ret;
	};
	ll w = p * inv(100) % mod;
	ll ws = ((1 - w) % mod + mod) % mod;
	for (ll i = 1; i <= n; i++) {
		ll v = (dp[i - 1] * ws % mod + dp[max(0ll, i - 2)] % mod * w % mod) % mod;
		dp[i] = (dp[i] % mod + v % mod + 1) % mod;
	}
	cout << dp[n] % mod << endl;
}
signed main() {
	solve();
}