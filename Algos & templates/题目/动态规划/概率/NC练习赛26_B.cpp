#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll n, k;
db p[maxn];
db dp[maxn][105];
void solve() {
	std::cin >> n >> k;
	db e = 0;
	for (ll i = 1; i <= n; i++) {
		std::cin >> p[i]; e += p[i];
	}
	dp[0][0] = 1.0;
	for (ll i = 1; i <= n; i++) {
			for (ll j = 0; j <= k; j++) {
				dp[i][j] += dp[i - 1][j] * (1 - p[i]);
				if (j)
					dp[i][j] += dp[i - 1][j - 1] * (p[i]);
			}
		}
	printf("%5ld\n", e);
	printf("%5ld\n", dp[n][k]);
}
signed main() {
	solve();
}