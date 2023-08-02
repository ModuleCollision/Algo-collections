/*抽象成前缀匹配问题,容易得知乙方赢的方案总数满足卡特兰数*/
/*抽象成出入栈序列,可知前缀中入栈总数大于等于出栈总数*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
/*
void chart() {
	ll s = 0;
	vector<ll>d1, d2;
	function<void(ll, ll)>dfs = [&](ll d, ll cur) {
		if (d == s) {
			for (ll i = 1; i <= (s << 1); i++) {
				if (vis[i]) {
					d1.push_back(i);
				} else {
					d2.push_back(i);
				}
			}
			bool f = 1;
			for (ll i = 0; i < s; i++) {
				if (d1[i] < d2[i]) {
					f = 0; break;
				}
			}
			if (f)cnt++; d1.clear(); d2.clear();
			return;
		}
		for (ll i = cur + 1; i <= (s << 1); i++) {
			if (not vis[i]) {
				vis[i] = 1;
				dfs(d + 1, i); vis[i] = 0;
			}
		}
	};
	s = 5; dfs(0, 0);
	cout << cnt << endl;
}*/
//暴力打表来确定规律
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
	ll T; std::cin >> T;
	while (T--) {
		ll n; std::cin >> n;//卡特兰数的通项为C(2 * n , n) * inv(n + 1)
		cout << C(2 * n, n) % mod * n % mod * inv(n + 1) % mod << " " << C(2 * n, n) % mod * inv(n + 1) % mod << endl;
	}
}
signed main() {
	solve();
}