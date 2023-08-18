#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 2e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<ll>A(n + 5, 0), B(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		std::cin >> A[i] >> B[i];
	}
	vector<ll>sz(m + 5);
	for (ll i = 1; i <= m; i++)cin >> sz[i];
	vector<ll>pre(n + 5);
	vector<ll>c(max(n, m) + 1, 0); ll id = 0;
	for (ll i = max(1ll, m - n + 1); i <= m; i++) {
		c[++id] = sz[i];
	}
	vector dp(n + 5, vector (n + 5, vector<ll>(200, -inf)));
	for (ll i = 1; i <= n + 1; i++)for (ll k = 0; k <= 200; k++) {
			dp[i][i - 1][k] = 0;
		}
	vector ndp(id + 5, vector<ll>(n + 5, 0));
	for (ll len = 1; len <= n; len++) {
		for (ll i = 1; i + len - 1 <= n; i++) {
			ll j = i + len - 1;
			for (ll k = 0; k <= 200; k++) {
				dp[i][j][k] = max(dp[i][j - 1][k], dp[i][j][k]);
				if (k >= A[j]) {
					dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - A[j]] + B[j]);
				}
			}
		}
	}
	/*区间dp*/
	ll ans = 0;
	for (ll i = 1; i <= id; i++) {
		for (ll j = 0; j <= n; j++) {
			for (ll k = 0; k <= j; k++) {
				ndp[i][j] = max(ndp[i][j], ndp[i - 1][k] + dp[k + 1][j][c[i]]);
				ans = max(ans, ndp[i][j]);
			}
		}
	}
	/*背包dp*/
	cout << ans << endl;
}
signed main() {
	solve();
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
ll dp[205][205][205];
ll pre[205][205]; ll sz[maxn]; ll c[maxn]; ll A[205], B[205];
void solve() {
	ll n, m; std::cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		std::cin >> A[i] >> B[i];
	}
	for (ll i = 1; i <= m; i++)cin >> sz[i];
	ll id = 0;
	for (ll i = max(1ll, m - n + 1); i <= m; i++) {
		c[++id] = sz[i];
	}
	for (ll i = 1; i <= id; i++) {//前i个操作 到达第 j 个房间 用了k的容量
		for (ll j = 0; j <= n; j++) {
			for (ll k = 0; k <= sz[i]; k++) {
				if (j) {
					dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);//打个洞
				}
				if (k >= A[i] and j >= 1) {//从这里穿过去
					dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - A[j]] + B[j]);
				}
				if (not k)
					dp[i][j][0] = max(dp[i][j][0], pre[i - 1][j]);
				pre[i][j] = max(pre[i][j], dp[i][j][k]);
			}
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= id; i++) {
		for (ll k = 0; k <= c[id]; k++) {
			ans = max(ans, dp[i][n][k]);
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}