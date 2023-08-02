#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const int maxn = 4e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, m; std::string A, B;
	std::cin >> n >> A >> m >> B;
	A = " " + A; B = " " + B;
	vector dp(n + 1, vector<ll>(m + 1, inf));
	for (ll i = 0; i <= n; i++) {
		dp[i][0] = i;
	}
	for (ll i = 0; i <= m; i++) {
		dp[0][i] = i;
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
			if (A[i] == B[j]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			} else {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	cout << dp[n][m] << endl;
}
signed main() {
	solve();
}