typedef long long ll;
const ll mod = 1e9 + 7;
ll fac[20005];
void init() {
	fac[0] = 1;
	for (ll i = 1; i <= 2e4; i++)fac[i] = fac[i - 1] % mod * i % mod;
}
ll ksm(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y & 1)ret = ret % mod * x % mod;
		x = (x % mod) * (x % mod) % mod;
		y >>= 1;
	}
	return ret % mod;
}
ll inv(ll x) {
	return ksm(x, mod - 2) % mod;
}
ll comb(ll n, ll m) {
	return fac[n] % mod * inv(fac[m] % mod * fac[n - m]) % mod;
}
class Solution {
public:
	int idealArrays(int n, int maxValue) {
		init();
		vector<vector<ll>>p(maxValue + 1);
		for (ll i = 2; i <= maxValue; i++) {
			ll x = i;
			for (ll j = 2; j <= sqrt(x); j++) {
				if (x % j == 0) {
					ll cnt = 0; while (x % j == 0)x /= j, cnt++;
					p[i].push_back(cnt);
				}
			}
			if (x > 1)p[i].push_back(1);
		}
		ll ans = 0;
		for (ll i = 1; i <= maxValue; i++) {
			ll w = 1;
			for (auto j : p[i])w = (w % mod * comb(n + j - 1, j)) % mod;
			ans = (ans % mod + w) % mod;
		}
		return ans % mod;
	}
};