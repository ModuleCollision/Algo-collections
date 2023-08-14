#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll p[maxn], cnt[maxn], tt = 0;
ll n;
void pre() {
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			p[++tt]	= i;
			ll tmp = 0;
			while (n % i == 0) {
				n /= i; tmp++;
			}
			cnt[tt] = tmp;
		}
	}
	if (n > 1) {
		p[++tt] = n;
		cnt[tt] = 1;
	}
}
void solve() {
	std::cin >> n; pre();
	auto lg = [&](ll a, ll b) {
		ll ret = 0, r = 1;
		while (r <= b) {
			r *= a; ret++;
		}
		if (r > b) {
			r /= a; ret--;
		}
		return ret;
	};
	//cout << lg(2, 8) << endl;
	auto check = [&](ll mid) {
		for (ll i = 1; i <= tt; i++) {
			ll pp = p[i], tmp = mid, tot = 0;
			ll k = lg(pp, mid);
			ll ans = 0; ll cur = 1;
			for (ll i = 1; i <= k; i++) {
				cur *= pp;
				ans += mid / cur;
			}
			if (ans < cnt[i]) {
				return false;
			}
		}//其阶乘最多能为该素数因子提供的幂次
		return true;
	};
	ll l = 1, r = inf;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << r << endl;
}
signed main() {
	solve();
}