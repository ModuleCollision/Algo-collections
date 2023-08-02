#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct DSU {
	vector<ll>fa;
	vector<ll>sz;
	void init(ll n) {
		fa.resize(n + 5);
		for (ll i = 1; i <= n; i++) {
			fa[i] = i;
		}
		sz.resize(n + 5, 1);
	}
	ll find(ll x) {
		while (x != fa[x])x = fa[x] = fa[fa[x]];
		return x;
	}
	void merge(ll x, ll y) {
		ll a = find(x), b = find(y);
		if (a == b)return;
		fa[a] = b;
		sz[b] += sz[a];
	}
} dsu; ll N;
struct edge {
	ll u, v, w;
};
vector<edge>e;
void solve() {
	std::cin >> N;
	dsu.init(N);
	for (ll i = 1; i <= N - 1; i++) {
		ll u, v, w; std::cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	std::sort(e.begin(), e.end(), [&](edge a, edge b)->bool{
		return a.w < b.w;
	});
	ll ans = 0;
	for (auto ed : e) {
		ll u = ed.u, v = ed.v, w = ed.w;
		ans += dsu.sz[dsu.find(u)] * dsu.sz[dsu.find(v)] * w;
		dsu.merge(u, v);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}