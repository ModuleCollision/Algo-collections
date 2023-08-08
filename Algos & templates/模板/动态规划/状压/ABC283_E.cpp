/*与状压dp相同的思路,枚举状态查看是否可以转移*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N, M, a[maxn][maxn]; ll dp[maxn][2][2];//定义在第i行处 ,i-1和i是否
//翻转的情况下除第i行外没有孤立点所能达到的最大价值
void solve() {
	auto check = [&](ll u, ll x, ll y, ll z) {
		for (ll i = 1; i <= M; i++) {
			if (a[u][i] != a[u][i - 1] and
			        a[u][i] != a[u][i + 1] and
			        (a[u][i]^y) != (a[u - 1][i]^x) and (a[u][i]^y) != (a[u + 1][i]^z)) {
				return false;
			}
		}//只需判定第u行五孤立点即可
		return true;
	};
	memset(a, 0xff, sizeof(a));
	std::cin >> N >> M;
	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= M; j++) {
			std::cin >> a[i][j];
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[1][0][0] = 0; dp[1][0][1] = 1;
	for (ll i = 2; i <= N + 1; i++) {
		for (ll j = 0; j < 2; j++) {
			for (ll k = 0; k < 2; k++) {
				for (ll z = 0; z < 2; z++) {
					if (check(i - 1, j, k, z)) {
						dp[i][k][z] = min(dp[i][k][z], dp[i - 1][j][k] + z);
					}
				}
			}
		}
	}
	ll ans = inf;
	for (ll i = 0; i < 2; i++) {
		for (ll j = 0; j < 2; j++) {
			ans = min(ans, dp[N + 1][i][j]);
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}