#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
const ll mod = 998244353;
char s1[maxn], s2[maxn];
ll dp[55][55][55][55];
void solve() {
	std::cin >> (s1 + 1) >> (s2 + 1);
	ll len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
	ll res = -inf;
	for (ll l1 = 0; l1 <= len1; l1++) {
		for (ll l2 = 0; l2 <= len2; l2++) {
			for (ll i = 1; i + l1 - 1 <= len1; i++) {
				ll j = i + l1 - 1;
				for (ll k = 1; k + l2 - 1 <= len2; k++) {
					ll l = k + l2 - 1;
					if (l1 + l2 <= 1)dp[i][j][k][l] = 1;
					else {
						dp[i][j][k][l] = 0;
						if (j and s1[i] == s1[j]) {
							dp[i][j][k][l] |= dp[i + 1][j - 1][k][l];
						}
						if (l and s2[k] == s2[l]) {
							dp[i][j][k][l] |= dp[i][j][k + 1][l - 1];
						}
						if (s1[i] == s2[l] and l) {
							dp[i][j][k][l] |= dp[i + 1][j][k][l - 1];
						}
						if (s2[k] == s1[j] and j) {
							dp[i][j][k][l] |= dp[i][j - 1][k + 1][l];
						}
					}
					if (dp[i][j][k][l])res = max(res, l1 + l2);
				}
			}
		}
	}
	cout << res << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}