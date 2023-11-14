#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N, M;
std::vector<ll>p[maxn];
ll dp[maxn][maxn];
void solve() {
	std::cin >> N >> M;
	for (ll i = 1; i <= N; i++) {
		p[i].push_back(0);
		for (ll j = 1; j <= M; j++) {
			ll v; std::cin >> v;
			p[i].push_back(v);
		}
		sort(p[i].begin() + 1, p[i].begin() + 1 + M);
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= M; j++) {
			p[i][j] += p[i][j - 1];
		}
	}
	for (ll i = 1; i <= N; i++) {
		for (ll j = i; j <= i * M; j++) {//满足需求的下限和生产上限
			for (ll k = 0; k <= M; k++) {
				if (j - k >= i - 1) {//满足前i - 1天的需求
					dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + p[i][k] + k * k);//转移方程
				}
			}
		}
	}
	ll ans = inf;
	for (ll i = 0; i <= N * M; i++) {
		ans = min(ans, dp[N][i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}

