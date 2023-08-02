#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll N; std::cin >> N; vector<ll>A(N + 5);
	for (ll i = 1; i <= N; i++)cin >> A[i];
	vector<string>s(N + 5);
	for (ll i = 1; i <= N; i++) {
		std::cin >> s[i];
		s[i] = " " + s[i];
	}
	vector dp(N + 5, vector<pair<ll, ll>>(N, {N + 1, 0}));
	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			if (i == j)dp[i][j] = {0, 0};
			else if (s[i][j] == 'Y') {
				dp[i][j] = {1, -A[j]};
			}
		}
	}
	//Floyd, 设置两个边权即可
	for (ll k = 1; k <= N; k++) {
		for (ll i = 1; i <= N; i++) {
			for (ll j = 1; j <= N; j++) {
				dp[i][j] = min(dp[i][j], {dp[i][k].first + dp[k][j].first, dp[i][k].second + dp[k][j].second});
			}
		}
	}
	ll Q; std::cin >> Q;
	while (Q--) {
		ll u, v; std::cin >> u >> v;
		if (dp[u][v].first > N) {
			puts("Impossible");
		} else {
			cout << dp[u][v].first << " " << A[u] - dp[u][v].second << endl;
		}
	}
}
signed main() {
	solve();
}