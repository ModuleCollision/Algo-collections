#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll w[maxn][10], T, X, A, N;
ll dp[maxn][10];
void solve() {
	std::cin >> N;
	for (ll i = 1; i <= N; i++) {
		std::cin >> T >> X >> A;
		w[T][X] = A;
	}
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (ll i = 1; i <= 1e5; i++) {//枚举时间
		for (ll j = 0; j <= min(i, 4ll); j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j >= 1)
				//上一个时刻的后一个坐标
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + w[i][j]);
			if (j <= 3)
				//上一个时刻的前一个坐标
				dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + w[i][j]);
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= 4; i++) {
		ans = max(ans, dp[100000][i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}