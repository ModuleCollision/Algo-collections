/*dp求概率*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll inv[maxn], p[maxn], n, a, b;
ll w[maxn];
void solve() {
	inv[1] = 1;
	for (ll i = 2; i <= 1e6; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
	std::cin >> n >> a >> b;
	ll P = a * inv[b] % mod;
	for (ll i = 1; i <= n; i++) {
		std::cin >> w[i];
	}
	for (ll i = 1; i <= n; i++) {
		std::cin >> a >> b;
		p[i] = a % mod * inv[b] % mod;
	}
	vector<ll>dp(maxn, 0);
	ll ans = 0;
	dp[1] = p[1] % mod;
	ans += dp[1] * w[1] % mod;
	for (ll i = 2; i <= n; i++) {
		dp[i] = (dp[i] % mod + dp[i - 1] % mod * (p[i] + P) % mod) % mod;
		dp[i] = (dp[i] % mod + (1 - dp[i - 1] + mod) % mod * p[i] % mod) % mod;
		ans = (ans % mod + dp[i] % mod * w[i]) % mod;
	}
	/*此为根据∑x * px的定义求取期望*/
	
	cout << ans % mod << endl;
}
signed main() {
	solve();
}