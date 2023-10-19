/*期望dp+状态机模型*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e2 + 5;
const ll inf = 21474835648;
const ll mod = 1e9 + 7;
db dp[maxn][maxn][maxn << 1], p[maxn];
void solve() {
	ll N, L, K;
	std::cin >> N >> L >> K;
	if (K > N) {
		K = N;
	}
	db ans = 0;
	dp[0][0][N + K] = 1;
	for (ll i = 1; i <= N; i++) {
		std::cin >> p[i];
		p[i] /= 100;
	}
	for (ll i = 1; i <= N; i++) {
		ll x; std::cin >> x;
		for (ll j = 1; j <= i; j++) {
			for (ll k = 0; k <= N + N; k++) {
				if (k + x >= 0) {
					dp[i][j][min(2 * N, k + x)] += p[i] * dp[i - 1][j - 1][k];
					dp[i][j][k] += (1 - p[i]) * dp[i - 1][j][k];
					//转移:由前i次挑战且第j次挑战赢或者不赢的概率转移而来
				}
			}
		}
	}
	for (ll j = L; j <= N; j++) {
		for (ll k = N; k <= (maxn << 1); k++) {
			ans += dp[N][j][k];
		}
	}
	printf("%.6lf", ans);
}
signed main() {
	solve();
}

