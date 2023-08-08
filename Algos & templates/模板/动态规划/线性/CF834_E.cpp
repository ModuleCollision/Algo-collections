#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
typedef vector<ll> ve1;
typedef vector<ve1> ve2;
typedef vector<ve2> ve3;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
//dp i , j表示在前i个数中使用状态为j的最大获得数
void solve() {
	ll n, h; std::cin >> n >> h;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	std::sort(A.begin() + 1, A.begin() + 1 + n);
	vector<vector<ll>>dp(n + 5, vector<ll>(15, -inf));
	for (ll i = 0; i <= 7; i++) {
		ll k = 1;
		if (i & 1)k *= 2;
		if (i & 2)k *= 2;
		if (i & 4)k *= 3;
		dp[0][i] = k * h;
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= 7; j++) {
			if (dp[i - 1][j] > A[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + A[i] / 2);
			for (ll k = j; k; k = j & (k - 1)) {
				ll pre = j ^ k;
				ll s = 1;
				if (k & 1)s *= 2;
				if (k & 2)s *= 2;
				if (k & 4)s *= 3;
				if (dp[i][pre] != -inf)
					dp[i][j] = max(dp[i][j], dp[i][pre] * s);
			}
		}
	}
	vector<ll>ans(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		for (ll k = 0; k <= 7; k++) {
			ans[i] = max(ans[i], dp[i][k]);
		}
	}
	for (ll i = n; i >= 1; i--) {
		if (ans[i] - A[i] / 2 > A[i]) {
			cout << i << endl; return;
		}
	}
	cout << 0 << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--) {
		solve();
	}
}