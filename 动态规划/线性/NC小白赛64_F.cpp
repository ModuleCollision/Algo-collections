#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll dp[4][maxn];
bool vis[4][maxn];
void solve() {
	ll n, m;
	std::cin >> n >> m;
	dp[1][1] = 1;
	ll u, v;
	for (ll i = 1; i <= m; i++) {
		std::cin >> u >> v;
		vis[u][v] = 1;
	}
	for (ll j = 1; j <= n - 1; j++) {
		for (ll i = 1; i <= 3; i++) {
			if (vis[i][j]) {
				dp[max(i - 1, 1ll)][j + 1] = (dp[max(i - 1, 1ll)][j + 1] % mod + dp[i][j]) % mod;
				dp[min(3ll, i + 1ll)][j + 1] = (dp[min(3ll, i + 1)][j + 1] % mod + dp[i][j]) % mod;
				dp[i][min(j + 2ll, n)] = (dp[i][min(j + 2ll, n)] % mod + dp[i][j]) % mod;
			} else {
				dp[i][j + 1] = (dp[i][j + 1] % mod + dp[i][j]) % mod;
			}
		}
	}
	for (ll i = 1; i <= 3; i++) {
		cout << dp[i][n] % mod << endl;
	}
}
signed main() {
	solve();
}