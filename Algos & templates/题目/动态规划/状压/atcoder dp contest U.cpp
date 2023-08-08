#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll dp[maxn], v[maxn];//定义dp[mask]为状态msk已经分好组的最大价值
ll s[25][25], N;
void solve() {
	std::cin >> N;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			std::cin >> s[i][j];
		}
	}
	for (ll i = 0; i < (1 << N); i++) {
		for (ll j = 0; j < N; j++) {
			for (ll k = j + 1; k < N; k++) {
				if (((i >> j) & 1) and (i >> k) & 1) {
					v[i] += s[j][k];
				}
			}
		}
	}
	for (ll i = 0; i < (1 << N); i++) {
		for (ll j = i; j; j = i & (j - 1)) {
			ll k = i ^ j;
			dp[i] = max(dp[i], dp[k] + v[j]);
		}
	}
	cout << dp[(1 << N) - 1] << endl;
}
signed main() {
	solve();
}