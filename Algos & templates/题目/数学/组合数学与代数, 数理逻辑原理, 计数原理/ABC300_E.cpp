#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>b = {2, 3, 5};
	std::map<ll, ll>cnt;
	for (ll i = 0; i < 3; i++) {
		if (n % b[i] == 0) {
			ll k = 0;
			while (n % b[i] == 0) {
				n /= b[i]; k++;
			}
			cnt[b[i]] = k;
		}
	}
	auto inv = [&](ll x) {
		ll b = mod - 2; ll ret = 1;
		while (b) {
			if (b & 1)ret = ret * x % mod;
			x = x * x % mod;
			b >>= 1;
		}
		return ret;
	};
	ll d = inv(5);
	ll x = cnt[2], y = cnt[3], z = cnt[5];
	ll dp[x + 5][y + 5][z + 5];
	for (ll i = 0; i <= x; i++) {
		for (ll j = 0; j <= y; j++) {
			for (ll k = 0; k <= z; k++)dp[i][j][k] = 0;
		}
	}
	if (n != 1) {
		puts("0"); return;
	}
	dp[0][0][0] = 1;
	for (ll i = 0; i <= x; i++) {
		for (ll j = 0; j <= y; j++) {
			for (ll k = 0; k <= z; k++) {
				if (i + 1 <= x)
					dp[i + 1][j][k] = (dp[i + 1][j][k] % mod + dp[i][j][k] % mod * d) % mod;
				if (j + 1 <= y)
					dp[i][j + 1][k] = (dp[i][j + 1][k] % mod + dp[i][j][k] % mod * d) % mod;
				if (k + 1 <= z)
					dp[i][j][k + 1] = (dp[i][j][k + 1] % mod + dp[i][j][k] % mod * d) % mod;
				if (i + 2 <= x)
					dp[i + 2][j][k] = (dp[i + 2][j][k] % mod + dp[i][j][k] % mod * d) % mod;
				if (i + 1 <= x and j + 1 <= y)
					dp[i + 1][j + 1][k] = (dp[i + 1][j + 1][k] % mod + dp[i][j][k] % mod * d) % mod;
			}
		}
	}
	cout << dp[x][y][z] % mod << endl;
}
signed main() {
	solve();
}