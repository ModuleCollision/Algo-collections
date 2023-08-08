#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll dp[maxn][2], N, A, B;
//长度为i结尾为元/辅音的总单词数
void solve() {
	std::cin >> N >> A >> B;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = dp[0][1] = 1;
	auto ksm = [&](ll x, ll y) {
		ll ret = 1;
		while (y) {
			if (y & 1) {
				ret = ret * x % mod;
			}
			x = x * x % mod;
			y >>= 1;
		}
		return ret;
	}; ll ans = 0;
	for (ll i = 1; i <= N; i++) {
		for (ll j = i - 1; j >= max(0ll, i - A); j--) {
			dp[i][0] = (dp[i][0] % mod + dp[j][1] % mod * ksm(5, i - j)) % mod;
		}
		for (ll j = i - 1; j >= max(0ll, i - B); j--) {
			dp[i][1] = (dp[i][1] % mod + dp[j][0] % mod * ksm(21, i - j)) % mod;
		}
		ans = (ans % mod + dp[i][0]) % mod;
		ans = (ans % mod + dp[i][1]) % mod;
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}