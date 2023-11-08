/*计数dp*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, m; std::cin >> n >> m;
	vector dp(n + 5, vector<ll>(m + 5, 0));
	dp[0][0] = 1;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= m; j++) {
			for (ll k = 0; k <= min(j, A[i]); k++) {
				dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - k]) % mod;
			}
		}
	}
	cout << dp[n][m] % mod << endl;
}
signed main() {
	solve();
}


#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll fac[maxn];
void init() {
	fac[0] = 1;
	for (ll i = 1; i <= 1e6; i++)fac[i] = (fac[i - 1] % mod * i) % mod;
}
ll ksm(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y & 1)ret = ret * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ret % mod;
}
ll inv(ll x) {
	return ksm(x, mod - 2) % mod;
}
ll comb(ll n, ll m) {
	if (n < m)return 0ll;
	return fac[n] % mod * inv(fac[m] % mod * fac[n - m] % mod) % mod;
}
void solve() {
	init();
	ll n, m; std::cin >> n >> m; vector<ll>A(n + 1, 0);
	for (ll i = 0; i < n; i++)cin >> A[i];
	ll res = comb(n + m - 1, n - 1) % mod; ll d = 0;
	for (ll i = 1; i < (1 << n); i++) {
		vector<ll>s; ll cnt = 0;
		for (ll j = 0; j < n; j++)if ((i >> j) & 1)s.push_back(j), cnt++;
		ll p = n + m - 1;
		for (auto c : s) {
			p -= (A[c] + 1);
		}
		ll v = comb(p, n - 1) % mod;
		if (cnt & 1)d = (d % mod + v) % mod;
		else d = ((d - v) % mod + mod) % mod;
	}
	res = ((res - d) % mod + mod) % mod;
	cout << res << endl;
}
signed main() {
	solve();
}