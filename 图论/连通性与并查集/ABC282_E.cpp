#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct DSU {
	vector<ll>fa;
	void init(ll n) {
		fa.resize(n + 5, 0);
		for (ll i = 1; i <= n; i++)fa[i] = i;
	}
	ll find(ll x) {
		while (x != fa[x]) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	}
	void merge(ll x, ll y) {
		ll a = find(x), b = find(y);
		fa[a] = b;
	}
} dsu;
struct edge {
	ll u; ll v; ll w;
};
void solve() {
	ll N, M;
	std::cin >> N >> M;
	vector<ll>A(N + 5, 0);
	for (ll i = 1; i <= N; i++)std::cin >> A[i];
	ll ans = 0;
	auto ksm = [&](ll x, ll y)->ll {
		ll ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % M;
			x = x * x % M;
			y >>= 1;
		}
		return ret % M;
	};
	dsu.init(N); vector<edge>e;
	for (ll i = 1; i <= N; i++) {
		for (ll j = i + 1; j <= N; j++) {
			ll tmp = (ksm(A[i], A[j]) % M + ksm(A[j], A[i])) % M;
			e.push_back({i, j, tmp});
		}
	}
	std::sort(e.begin(), e.end(), [&](edge a, edge b)->bool{
		return a.w > b.w;
	});
	for (auto [u, v, w] : e) {
		if (dsu.find(u) == dsu.find(v))continue;
		ans += w;
		dsu.merge(u, v);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}