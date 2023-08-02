#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll dp[maxn][maxn];
ll N, M, K;
void solve() {
	std::cin >> N >> M >> K; vector pre(N + 5, vector<ll>(M + 5, 0));
	for (ll i = 1; i <= M; i++) {
		dp[1][i] = 1;
		pre[1][i] = (pre[1][i - 1] % mod + dp[1][i]) % mod;
	}

	for (ll i = 2; i <= N; i++) {
		for (ll j = 1; j <= M; j++) {
			ll l = j - K, r = j + K;
			if (l >= 1) {
				ll v = ((pre[i - 1][l] - pre[i - 1][0]) % mod + mod) % mod;
				dp[i][j] = (dp[i][j] % mod + v) % mod;
			}
			if (r <= M) {
				ll v = ((pre[i - 1][M] - pre[i - 1][r - 1]) % mod + mod) % mod;
				dp[i][j] = (dp[i][j] % mod + v) % mod;
			}
			pre[i][j] = (pre[i][j - 1] % mod + dp[i][j]) % mod;
		}
	}
	ll ans = 0;
	//前i个数在1到j的范围内所能生成的序列数

	cout << pre[N][M] % mod << endl;
}
signed main() {
	solve();
}