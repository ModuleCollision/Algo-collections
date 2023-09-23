#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 5000011;
void solve() {
	ll n, k; std::cin >> n >> k;
	vector<ll>dp(n + 5, 0);
	dp[0] = 1;
	vector<ll>pre(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		//if (i >= k + 1)
		dp[i] = (dp[i] % mod + dp[max(0ll, i - k - 1)]) % mod;
		//选择放一头公牛
		dp[i] = (dp[i] % mod + dp[i - 1]) % mod;
	}
	cout << dp[n] % mod << endl;
}
signed main() {
	solve();
}