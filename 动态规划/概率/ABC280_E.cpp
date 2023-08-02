/*期望dp*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll inv[maxn], N, P; ll dp[maxn]; //为第i天至第0天的期望次数
void pre() {
	inv[1] = 1;
	for (ll i = 2; i <= 3e5; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
}
void solve() {
	pre();
	std::cin >> N >> P; dp[0] = 0;
	for (ll i = 1; i <= N; i++) {
		dp[i] = (dp[i] % mod + (P % mod * inv[100] % mod) * dp[max(i - 2, 0ll)] % mod + dp[i - 1] % mod * (1 - P % mod * inv[100] % mod + mod) % mod + 1) % mod;
	}
	cout << dp[N] << endl;
}
signed main() {
	solve();
}