#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m; std::cin >> n >> m;
	auto inv = [&](ll x) {
		ll b = mod - 2;
		ll ret = 1;
		while (b) {
			if (b & 1) {
				ret = ret % mod * x % mod;
			}
			x = x % mod * x % mod;
			b >>= 1;
		}
		return ret % mod;
	};
	ll p = inv(2) % mod;
	auto ksm = [&](ll a, ll b) {
		ll ret = 1;
		while (b) {
			if (b & 1)ret = ret % mod * a % mod;
			a = a % mod * a % mod;
			b >>= 1;
		}
		return ret % mod;
	};
	ll ans = 1; ll pre = 0;
	for (ll l = n, r; l <= n + m - 1; l = r + 1) {
		ll cur = 0;
		while ((1ll << cur) <= l + 1)cur++;
		cur--;
		r = min((1ll << (cur + 1)) - 2ll, n + m - 1);
		ll s = ((1ll - ksm(p, cur)) % mod + mod) % mod;
		ans = ans % mod * ksm(s, max(0ll, r - l + 1)) % mod;
	}
	cout << ans % mod << "\n";
	return 0;
}