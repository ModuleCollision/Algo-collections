//维护最大最小值
//题干对第二维有要求,故需要维护第二维状态
//否则就是类背包问题,直接每个状态枚举选择转移(选 or 不选)即可
//没有对第二维的0做初始化则在做dp的过程中一定要维护到!!!
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll K, N, D, A[maxn]; //维护最大最小值
ll dp[105][105][105];
void solve() {
	std::cin >> N >> K >> D;
	for (ll i = 1; i <= N; i++) {
		std::cin >> A[i];
	}
	for (ll i = 0; i <= N; i++) {
		for (ll j = 0; j <= K; j++) {
			for (ll k = 0; k <= D; k++) {
				dp[i][j][k] = -inf;
			}
		}
	}
	dp[0][0][0] = 0;
	for (ll i = 1; i <= N; i++) {
		for (ll j = 0; j <= K; j++) {
			for (ll s = 0; s < D; s++) {
				if (dp[i - 1][j][s] != -inf) {
					dp[i][j][s] = max(dp[i][j][s], dp[i - 1][j][s]);
				}
				if (j >= 1) {
					if (dp[i - 1][j - 1][s] != -inf)
						dp[i][j][(s + A[i]) % D] = max(dp[i - 1][j - 1][s] + A[i], dp[i][j][(s + A[i]) % D]);
				}
			}
		}
	}
	if (dp[N][K][0] == -inf)puts("-1");
	else cout << dp[N][K][0] << endl;
}
signed main() {
	solve();
}
