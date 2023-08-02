#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll N; std::cin >> N;
	vector<double>dp(N + 5, 0);
	dp[1] = 3.5;
	for (ll i = 2; i <= N; i++) {
		for (ll j = 1; j <= 6; j++) {
			dp[i] += max(dp[i - 1], (double)j) / 6;
		}
	}
	printf("%.6lf", dp[N]);
}
signed main() {
	solve();
}