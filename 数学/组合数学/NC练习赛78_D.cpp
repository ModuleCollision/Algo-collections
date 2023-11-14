#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	ll l = 0, r = 63;//计算总共有几层
	while (l < r) {
		ll mid = (l + r) >> 1;
		if ((1ll << mid) - 1 >= n)r = mid;
		else l = mid + 1;
	}
	auto lowbit = [&](ll x) {
		return x & -x;
	};
	auto ksm = [&](ll x, ll y) {
		ll ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret % mod;
	};
	auto inv = [&](ll x) {
		return ksm(x, mod - 2) % mod;
	};
	if (n + 1 == lowbit(n + 1)) {
		ll ans = 0;
		for (ll i = 1; i <= r; i++) {
			ans = (ans % mod + ksm(2, i)) % mod;
		}
		ans = ((ans - r) % mod + mod) % mod;
		cout << ans << endl;
	} else {
		ll p = r - 1; ll ps = (1ll << (p)) - 1;//头顶的满二叉树
		ll ans = 0;
		for (ll i = 1; i <= p; i++) {
			ans = (ans % mod + ksm(2, i)) % mod;
		}
		ans = ((ans - p) % mod + mod) % mod;
		ll d = ((n - ps) % mod + mod) % mod; ans = (ans % mod + d) % mod; //统计一个的
		while (d) {
			ans = (ans % mod + d) % mod; d /= 2;
		}
		cout << ans << endl;
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}