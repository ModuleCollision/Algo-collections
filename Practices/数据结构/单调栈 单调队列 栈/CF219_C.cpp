#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m, d; std::cin >> n >> m >> d;
	vector<ll>a(m + 5, 0), b(m + 5, 0), t(m + 5, 0);
	for (ll i = 1; i <= m; i++)cin >> a[i] >> b[i] >> t[i];
	vector<ll>q(n + 5, 0);
	vector<vector<ll>>dp(2, vector<ll>(n + 5, -inf));//前i个炮火在第j地
	ll cur = 1;
	for (ll i = 1; i <= n; i++) {
		dp[0][i] = 0;
	}
	for (ll i = 1; i <= m; i++) {
		ll hed = 1, tal = 0; ll k = 1;
		for (ll j = 1; j <= n; j++) {
			for (; k <= min(n, j + d * (t[i] - t[i - 1])); k++) {
				while (hed <= tal and dp[cur ^ 1][q[tal]] <= dp[cur ^ 1][k])tal--;
				q[++tal] = k;//随着j的移动,有限队列中存储的数据下标范围也在移动
			}
			while (hed <= tal and q[hed] < max(1ll, j - d * (t[i] - t[i - 1]))) {
				hed++;
			}//单调队列维护一定下标范围内数据的最小值
			dp[cur][j] = dp[cur ^ 1][q[hed]] - abs(a[i] - j) + b[i];//直接查询即可
		}
		cur ^= 1;//滚动数组优化,因为只可能由前一大维转移而来
	}
	ll ans = -inf;
	for (ll i = 1; i <= n; i++) {
		ans = max(ans, dp[cur ^ 1][i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
