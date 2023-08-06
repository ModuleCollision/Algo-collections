/*概率dp模型*/
/*不外乎两种,概率dp与期望dp,注意概率与期望的递推是不同的*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll dp[maxn][maxn], N, M, K;
void solve() {
	std::cin >> N >> M >> K;
	dp[0][0] = 1;//通过几步到达哪个坐标的概率
	auto inv = [&](ll x) {
		ll ret = 1, b = mod - 2;
		while (b) {
			if (b & 1) {
				ret = ret * x % mod;
			}
			x = x * x % mod;
			b >>= 1;
		}
		return ret % mod;
	};
	//此为概率顺推
	for (ll i = 0; i <= K; i++) {//枚举期望步数
		for (ll j = 0; j < N; j++) {//枚举坐标
			for (ll k = 1; k <= M; k++) {//枚举前进格子数
				if (j + k <= N) {
					dp[i + 1][j + k] = (dp[i + 1][j + k] % mod + dp[i][j] % mod * inv(M) % mod) % mod;
				} else {
					dp[i + 1][2 * N - j - k] = (dp[i + 1][2 * N - j - k] % mod + dp[i][j] % mod * inv(M) % mod) % mod;
				}
			}
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= K; i++) {
		ans = ans % mod + dp[i][N] % mod;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}