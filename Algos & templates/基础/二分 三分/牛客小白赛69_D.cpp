#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 20000311;
ll n, m, c;
struct edge {
	ll u; ll v; ll w;
};
void solve() {
	std::cin >> n >> m >> c;
	vector<edge>e(m + 5);
	for (ll i = 1; i <= m; i++) {
		std::cin >> e[i].u >> e[i].v >> e[i].w;
	}
	std::sort(e.begin() + 1, e.begin() + 1 + m, [&](edge a, edge b)->bool{
		return a.w < b.w;
	});
	vector<ll>fa(n + 5, 0), sz(n + 5, 1);
	auto init = [&](ll n) {
		for (ll i = 1; i <= n; i++) {
			fa[i] = i;
		}
	};
	auto find = [&](ll x) {
		while (x != fa[x]) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	};
	auto merge = [&](ll u, ll v) {
		ll x = find(u), y = find(v);
		if (x == y)return;
		fa[x] = y;
	};
	auto check = [&](ll mid) {
		ll cnt = 0; for (ll i = 1; i <= n; i++)fa[i] = i;
		ll ret = 0;
		vector<ll>vv;
		for (ll i = 1; i <= m; i++) {
			ll u = e[i].u, v = e[i].v, w = e[i].w;
			ll a = find(u), b = find(v);
			if (a == b)continue;
			fa[a] = b;
			vv.push_back(w);
		}
		std::sort(vv.begin(), vv.end(), [&](ll x, ll y)->bool{
			return x > y;
		});
		for (auto q : vv) {
			if (q <= mid)q = 0;

			ret += q * (++cnt);
		}
		return ret <= c;//满足题意的条件
	};
	ll l = 0, r = inf;//注意二分边界: 0 ---> inf
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid ;
		} else {
			l = mid + 1;
		}
	}
	cout << r << endl;
}
signed main() {
	solve();
}