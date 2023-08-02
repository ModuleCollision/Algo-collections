#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e3 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
ll n, w[maxn], dp[maxn][maxn], ro[maxn][maxn];
void solve() {
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (ll i = 1; i <= n; i++) {
		dp[i][i] = w[i]; ro[i][i] = i;
	}
	for (ll len = 2; len <= n; len++) {
		for (ll l = 1; l + len - 1 <= n; l++) {
			ll r = l + len - 1;
			for (ll k = l; k <= r; k++) {
				ll x = (l == k) ? 1 : dp[l][k - 1];
				ll y = (r == k) ? 1 : dp[k + 1][r];
				ll res = (x * y) + w[k];
				if (res > dp[l][r]) {
					dp[l][r] = res;
					ro[l][r] = k;
				}
			}
		}
	}
	cout << dp[1][n] << endl;
	function<void(ll, ll)>dfs = [&](ll l, ll r) {
		if (l > r) {
			return;
		}
		ll k = ro[l][r];
		cout << k << " ";
		dfs(l, k - 1);
		dfs(k + 1, r);
	};
	dfs(1, n);
}
signed main() {
	solve();
}
