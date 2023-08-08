#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
void solve() {
	ll n, m; std::cin >> n >> m;
	auto fac = [&](ll x) {
		ll ret = 1;
		for (ll i = 1; i <= x; i++) {
			ret = ret * i; if (ret > m)return m + 1;
		}
		return ret;
	};
	auto getax = [&](ll idx) {
		ll rk = m;
		ll k = 1;//求出第m大的排列中第idx位的数
		while (fac(k) < m)k++;
		vector<bool>st(20, 0);
		if (idx <= n - k)return idx;//贪心的找, 枚举后 k 位 , 前 n - k 位为对应的数
		for (ll i = n - k + 1; i <= n; i++) {
			for (ll j = 1; i <= k; j++) {//第i位的数找到了
				if (not st[j]) {
					ll t = fac(n - i);
					if (t < rk) {
						rk -= t;
					} else {
						if (i == idx)return j + n - k;
						st[j] = true;
						break;
					}
				}
			}
		}
		return -1ll;
	};
	auto check = [&](ll x) {
		string t = to_string(x);
		for (auto c : t) {
			if (c != '4' and c != '7')return false;
		}
		return true;
	};
	ll ans = 0;
	function<void(ll)>dfs = [&](ll x) {
		if (x > n)return;
		if (x and check(getax(x)))ans++;
		dfs(10 * x + 4);
		dfs(10 * x + 7);
	};
	if (fac(n) < m) {
		puts("-1"); return;
	}
	dfs(0); cout << (ans ? ans : -1) << endl;
}
signed main() {
	solve();
}