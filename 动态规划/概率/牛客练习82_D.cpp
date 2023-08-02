#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll inv[5050], invfac[5050], fac[5050], f[5050];
ll a[5050], b[5050], dp[5050], p, q, n;
void solve() {
	f[1] = 1; inv[1] = 1; fac[1] = 1;
	fac[0] = 1; inv[0] = 1;
	invfac[0] = invfac[1] = 1;
	for (ll i = 2; i <= 5e3; i++) {
		f[i] = (f[i - 1] % mod + f[i - 2]) % mod;
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		invfac[i] = invfac[i - 1] % mod * inv[i] % mod;
		fac[i] = fac[i - 1] % mod * i % mod;
	}
	auto C = [&](ll n, ll m) {
		return fac[n] % mod * invfac[n - m] % mod * invfac[m] % mod;
	};
	auto ksm = [&](ll a, ll b) {
		ll ret = 1;
		while (b) {
			if (b & 1) {
				ret = ret * a % mod;
			}
			a = a * a % mod;
			b >>= 1;
		}
		return ret % mod;
	};
	std::cin >> n >> p >> q;
	a[0] = b[0] = 1;
	a[1] = p % mod * ksm(q, mod - 2) % mod;
	b[1] = ((1 - a[1]) % mod + mod) % mod;
	for (ll i = 2; i <= n; i++) {
		a[i] = (a[i - 1] % mod * a[1]) % mod;
		b[i] = (b[i - 1] % mod * b[1]) % mod;
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= i; j++) {
			dp[i] = (dp[i] % mod + C(i, j) % mod  * a[j] % mod * b[i - j] % mod * dp[i - j]) % mod;
		}
		dp[i] = (dp[i] % mod + f[i] % mod) % mod * ksm(((1 - b[i]) % mod + mod) % mod, mod - 2) % mod;
	}
	cout << dp[n] % mod << endl;
}
signed main() {
	solve();
}