#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll N, H; std::cin >> N >> H;
	vector dp(N + 5, vector(H + 1, vector<ll>(H + 1, inf)));
	dp[0][H][0] = 0;
	vector<ll>x(N + 1); vector<ll>p(N + 1), f(N + 1);
	for (ll i = 1; i <= N; i++)cin >> x[i];
	for (ll i = 1; i < N; i++) {
		cin >> p[i] >> f[i];
	}
	/*定义为最远到达，去的时候多少油，回来时候多少油的最小值*/
	for (ll i = 1; i <= N; i++) {
		for (ll j = 0; j <= H; j++) {
			for (ll k = 0; k <= H; k++) {
				ll dis = x[i] - x[i - 1];
				if (j - dis >= 0 and k + dis <= H) {
					dp[i][j - dis][k + dis] = min(dp[i][j - dis][k + dis], dp[i - 1][j][k]);
					ll nxt = min(j - dis + f[i], H);
					/*去的途中加了油*/
					dp[i][nxt][k + dis] = min(dp[i][nxt][k + dis], dp[i - 1][j][k] + p[i]);
					nxt = max(0ll, k + dis - f[i]);
					/*回来的途中加了油*/
					dp[i][j - dis][nxt] = min(dp[i][j - dis][nxt], dp[i - 1][j][k] + p[i]);
				}
			}
		}
	}
	ll ans = inf;
	for (ll j = 0; j <= H; j++)for (ll k = 0; k <= H; k++)if (j >= k)ans = min(ans, dp[N][j][k]);
	if (ans == inf) {
		puts("-1");
	} else cout << ans << endl;
}
signed main() {
	solve();
}