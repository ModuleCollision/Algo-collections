#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll inv[maxn], invfac[maxn], fac[maxn];
void pre() {
	inv[0] = invfac[0] = 1;
	inv[1] = invfac[1] = 1;
	fac[1] = 1;
	for (ll i = 2; i <= 1e6; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		invfac[i] = invfac[i - 1] * inv[i] % mod;
		fac[i] = fac[i - 1] * i % mod;//递推逆元以及阶乘逆元, (虽然不常用)
	}
}
ll C(ll n, ll m) {
	return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}
//可以打表确定规律
signed main() {
	pre();
	ll m, x, y, p;
	while (std::cin >> m >> x >> y >> p) {
		if (x == 1 or y == 0) {
			cout << p << endl;
			continue;
		}
		ll ans = 0;
		for (ll i = 0; i <= y; i++) {
			ans = (ans + C(x - 1, i)) % mod;
		}
		ans = ans * p % mod;
		cout << ans << endl;
	}
	return 0;
}