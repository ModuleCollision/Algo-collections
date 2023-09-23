/*dp求期望*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N;
void solve() {
	std::cin >> N;
	vector<ll>A(N + 5, 0);
	for (ll i = 1; i <= N - 1; i++)std::cin >> A[i];
	auto inv = [&](ll x) {
		ll ret = 1, y = mod - 2;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret % mod;
	};
	vector<ll>pre(N + 5, 0);
	vector<ll>dp(N + 5, 0); dp[N] = 0;
	for (ll i = N - 1; i >= 1; i--) {
		dp[i] = (dp[i] % mod + (pre[i + 1] - pre[i + A[i] + 1]) % mod + mod) % mod;
		dp[i] = (dp[i] % mod + (1 + A[i])) % mod;
		dp[i] = dp[i] % mod * inv(A[i]) % mod;
		pre[i] = (pre[i + 1] % mod + dp[i]) % mod;
	}
	cout << dp[1] << endl;
}
signed main() {
	solve();
}