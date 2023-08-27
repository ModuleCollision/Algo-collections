#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, b, p, k;
	std::cin >> n >> b >> p >> k;
	ll Hash = 0;
	string s; cin >> s; s = " " + s;
	for (ll i = 1; i <= n; i++) {
		Hash = (Hash * b + s[i] - 'a' + 1) % p;
	}
	vector dp(n + 5, vector (k + 5, vector<ll>(1005, 0)));
	auto now = dp, pre = dp;
	dp[0][0][0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= k; j++) {
			for (ll l = 0; l < p; l++) {
				for (char q = 'a'; q <= 'z'; q++) {
					if (s[i] == q) {
						if (j and dp[i - 1][j - 1][l]) {
							dp[i][j][(l * b + q - 'a' + 1) % p] = 1;
							now[i][j][(l * b + q - 'a' + 1) % p] = q;
							pre[i][j][(l * b + q - 'a' + 1) % p] = l;
						}
					} else {
						if (dp[i - 1][j][l]) {
							dp[i][j][(l * b + q - 'a' + 1) % p] = 1;
							now[i][j][(l * b + q - 'a' + 1) % p] = q;//到达这个状态的当前字母
							pre[i][j][(l * b + q - 'a' + 1) % p] = l;//到达这个状态的上一个哈希值
						}
					}
				}
			}
		}
	}
	if (not dp[n][k][Hash]) {
		puts("-1"); return;
	}
	ll ps = Hash; string ans = "";
	for (ll i = n, ned = k; i >= 1; i--) {
		ans += now[i][ned][ps];
		ll tmp = ps;
		ps = pre[i][ned][ps];
		if (now[i][ned][tmp] == s[i])ned--;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}