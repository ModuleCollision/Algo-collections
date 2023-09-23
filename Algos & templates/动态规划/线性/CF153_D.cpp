#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	string s; std::cin >> s; ll n = s.size(); s = " " + s;
	vector dp(n + 5, vector(n + 5, vector<ll>(6000, inf)));
	dp[0][0][3000] = 0;
	ll cnt = 0; for (ll i = 1; i <= n; i++)if (s[i] == '1')cnt++;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= cnt; j++) {
			for (ll z = 500; z <= 5500; z++) {
				if (s[i] == '1') {
					ll p = i - j;//第i位置是否转换
					if (j >= 1)
						dp[i][j][z] = min(dp[i][j][z], dp[i - 1][j - 1][z + p]);
					dp[i][j][z] = min(dp[i][j][z], dp[i - 1][j][z - j] + 1);
				} else {
					dp[i][j][z] = min(dp[i][j][z], dp[i - 1][j][z - j]);
					if (j >= 1) {
						ll p = i - j;
						dp[i][j][z] = min(dp[i][j][z], dp[i - 1][j - 1][z + p] + 1);
					}
				}
			}
		}
	}
	cout << dp[n][cnt][3000] / 2 << endl;
}
signed main() {

	solve();
}