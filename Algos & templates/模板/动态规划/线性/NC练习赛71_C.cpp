#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 20000311;
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<ll>p(m + 5, 0);
	for (ll i = 1; i <= m; i++)std::cin >> p[i];
	std::sort(p.begin() + 1, p.begin() + 1 + m);
	auto inv = [&](ll x) {
		ll y = mod - 2, ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret;
	};
	vector<ll>dp(n + 5, 0);
	vector<ll>fac(n + 5, 0);
	fac[0] = 1;
	for (ll i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] % mod * i % mod;
	}
	dp[1] = fac[p[1]];//维护的是不满足第i个条件但满足前i - 1个条件的总方案数
	for (ll i = 2; i <= m; i++) {
		dp[i] = fac[p[i]] % mod;
		for (ll j = 1; j < i; j++) {
			dp[i] = ((dp[i] - fac[p[i] - p[j]] % mod * dp[j] % mod) % mod + mod) % mod;
		}
	}
	ll ans = fac[n];
	for (ll i = 1; i <= m; i++) {
		ans = ((ans - dp[i] * fac[n - p[i]] % mod) + mod) % mod;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
//这里是容斥原理的一个变式, 可以画韦恩图来理解
