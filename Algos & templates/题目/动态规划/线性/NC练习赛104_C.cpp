
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
char s[maxn]; ll n;
ll dp[maxn][8];
void solve() {
	std::cin >> (s + 1);
	ll n = strlen(s + 1);
	for (ll i = 1; i <= n; i++) {
		dp[i][1] = 1;
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 2; j <= 7; j++) {
			if (j == 2 or j == 4) {
				for (ll k = 1; k <= i - 1; k++) {
					if (s[k] < s[i]) {
						dp[i][j] = (dp[i][j] % mod + dp[k][j - 1]) % mod;
					}
				}
			} else if (j == 3 or j == 5 or j == 6 or j == 7) {
				for (ll k = 1; k <= i - 1; k++) {
					if (s[k] > s[i]) {
						dp[i][j] = (dp[i][j] % mod + dp[k][j - 1]) % mod;
					}
				}
			}
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++)ans = (ans % mod + dp[i][7]) % mod;
	cout << ans % mod << endl;
}
signed main() {
	solve();
}