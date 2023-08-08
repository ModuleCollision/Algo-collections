/*All glory, all honor, victory is upon us!*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll tr[maxn], n, q, w, x, a[maxn], p;
//map<ll, ll>st;
void solve() {
	cin >> n >> q >> w; w += 2;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i]; a[i]++;
		//st[i] = a[i];
	}
	//std::sort(a + 1, a + 1 + n);
	auto lowbit = [&](ll x)->ll{
		return x & -x;
	};
	auto add = [&](ll id, ll v) {
		for (; id <= w; id += lowbit(id)) {
			tr[id] += v;
		}
	};
	auto query = [&](ll id)->ll{
		ll ret = 0;
		for (; id >= 1; id -= lowbit(id)) {
			ret += tr[id];
		}
		return ret;
	};
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll s = w - a[i];
		add(a[i], 1);
		ans += query(s);
	}
	while (q--) {
		std::cin >> p >> x; x++;
		ll cur = a[p]; a[p] = x;
		//st[p] = x;
		ans -= query(w - cur);
		add(cur, -1);
		add(x, 1);
		ans += query(w - x);
		cout << ans << endl;
	}
/*本质是一个差分*/
}
signed main() {
	solve();
}