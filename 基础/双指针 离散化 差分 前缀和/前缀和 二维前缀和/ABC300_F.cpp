#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m, k; string s; std::cin >> n >> m >> k >> s;
	ll tot = 0;
	s = " " + s;
	vector<ll>idx(n + 5);
	for (ll i = 1; i <= n; i++) {
		if (s[i] == 'x')idx[++tot] = i;
	}
	idx[++tot] = n + 1;
	ll cnt = tot - 1;
	auto get = [&](ll i) {
		if (cnt - i + 1 + (m - 1)*cnt < k)return 0ll;
		ll tmp = k;
		ll ret = 0; ll cur = 0;
		ll s1 = min(tmp, cnt - i + 1);
		ret += idx[i] - idx[i - 1];
		ret += idx[i + s1] - idx[i] - 1;
		cur += 1; tmp -= s1;
		if (tmp <= 0)return ret;
		ll mid = max(0ll, tmp / cnt);
		mid = min(mid, m - 1);
		cur += mid;
		ret += mid * n;
		if (cur == m)return ret;
		tmp -= mid * cnt;
		ret += idx[tmp + 1] - 1;
		return ret;
	};
	ll ans = 0;
	for (ll i = 1; i <= cnt; i++) {
		ans = max(ans, get(i));
	}
	cout << ans << endl;
}
signed main() {
	solve();
}