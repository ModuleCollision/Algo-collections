#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e3 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll N; std::cin >> N;
	vector<pair<ll, ll>>A(2 * N + 5);
	for (ll i = 1; i <= N; i++) {
		std::cin >> A[i].first;
		ll j = i - 1; if (not j)j += N;
		A[j].second = A[i].first;
	}
	for (ll i = N + 1; i <= 2 * N; i++) {
		A[i] = A[i - N];
	}
	ll dp[2 * N + 5][2 * N + 5];
	memset(dp, 0, sizeof(dp));
	for (ll len = 2; len <= 2 * N; len++) {
		for (ll i = 1; i + len - 1 <= 2 * N; i++) {
			ll j = i + len - 1;
			for (ll k = i; k <= j - 1; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + A[i].first * A[k].second * A[j].second);
			}
		}
	}
	ll ans = 0;
	for (ll i = 1; i + N - 1 <= 2 * N; i++) {
		ans = max(ans, dp[i][i + N - 1]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
