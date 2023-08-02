#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll fac[maxn];
void solve() {
	fac[0] = 1;
	for (ll i = 1; i <= 1e6; i++) {
		fac[i] = (fac[i - 1] % mod * i) % mod;
	}
	auto inv = [&](ll x) {
		ll y = mod - 2, ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret;
	};
	auto C = [&](ll n, ll m) {
		return fac[n] % mod * inv(fac[n - m] % mod * fac[m] % mod) % mod;
	};
	ll N, M, u, v, k; std::cin >> N >> M >> k;
	vector<ll>d(N + 5, 0);
	for (ll i = 1; i <= M; i++) {
		std::cin >> u >> v;
		d[u]++; d[v]++;
	}
	vector<ll>nums(2, 0);
	for (ll i = 1; i <= N; i++) {
		nums[d[i] & 1]++;
	}
	ll ans = 0;
	for (ll i = 0; i <= nums[1] and i <= k; i += 2) {
		if (k - i <= nums[0])
			ans = (ans % mod + C(nums[1], i) % mod * C(nums[0], k - i)) % mod;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}