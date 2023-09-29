#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e7 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll fac[maxn];
void init() {
	fac[0] = 1;
	for (ll i = 1; i <= 1e6; i++)fac[i] = (fac[i - 1] % mod * i) % mod;
}
ll ksm(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b & 1)ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret % mod;
}
ll inv(ll x) {
	return ksm(x, mod - 2) % mod;
}
ll comb(ll n, ll m) {
	return fac[n] % mod * inv(fac[n - m] % mod * fac[m] % mod) % mod;
}

void solve() {
	init();
	ll H, W, A, B; std::cin >> H >> W >> A >> B;
	ll ans = 0;
	for (ll i = 0; i < W - B; i++) {
		//cout << H - A - 1 + i + B << endl;
		ll v = comb(H - A - 1 + i + B, B + i) % mod;
		ll v2 = comb(W - B - i + A - 2, A - 1) % mod;
		ans = (ans % mod + v % mod * v2 % mod) % mod;
	}
	cout << ans % mod << endl;
}
signed main() {
	solve();
}