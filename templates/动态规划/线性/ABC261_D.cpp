#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll N, M; std::cin >> N >> M;
	vector<ll>X(N + 5, 0);
	for (ll i = 1; i <= N; i++)std::cin >> X[i];
	std::map<ll, ll>b;
	for (ll i = 1; i <= M; i++) {
		ll c, y; std::cin >> c >> y; b[c] = y;
	}
	ll dp[N + 5][N + 5];
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 0;
	ll p[N + 5]; memset(p, 0, sizeof(p));
	for (ll i = 1; i <= N; i++) {
		for (ll j = 0; j <= N; j++) {
			if (not j) {
				dp[i][j] = max(dp[i][j], p[i - 1]);
			} else {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + b[j] + X[i]);
			}
			p[i] = max(p[i], dp[i][j]);
		}
	}
	ll ans = -inf;
	for (ll i = 0; i <= N; i++) {
		ans = max(ans, dp[N][i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}


