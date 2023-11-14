#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N, C[15], dp[maxn];
void solve() {
	std::cin >> N;
	for (ll i = 1; i <= 9; i++) {
		std::cin >> C[i];
	}
	for (ll i = 1; i <= 9; i++) {
		for (ll j = 1e6; j >= C[i]; j--) {
			dp[j] = max(dp[j], 10 * dp[j - C[i]] + i);
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= N; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve(); return 0;
}