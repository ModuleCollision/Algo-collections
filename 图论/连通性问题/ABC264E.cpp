#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct DSU {
	vector<ll>fa; vector<ll>siz;
	void init(ll n) {
		fa.resize(n + 5); siz.resize(n + 5, 1);
		for (ll i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
	ll find(ll x) {
		while (x != fa[x]) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	}
} dsu;
ll N, M, Q, E;
pair<ll, ll>e[maxn];
ll qd[maxn]; ll ed[maxn], ans[maxn];
void solve() {
	std::cin >> N >> M >> E;
	for (ll i = 1; i <= E; i++) {
		std::cin >> e[i].first >> e[i].second;
	}
	std::cin >> Q;
	for (ll i = 1; i <= Q; i++) {
		std::cin >> ed[i];
		qd[ed[i]] = 1;
	}
	dsu.init(N + M + 5);
	ll tot = 0;
	auto check = [&](ll mid) ->bool {
		return mid >= N + 1 and mid <= N + M;
	};
	for (ll i = 1; i <= E; i++) {
		if (not qd[i]) {
			ll a = dsu.find(e[i].first);
			ll b = dsu.find(e[i].second);
			if (a != b) {
				if (a > b)swap(a, b);
				dsu.fa[a] = b;
				if ((not check(a)) and check(b)) {
					tot += dsu.siz[a];
				}
				dsu.siz[b] += dsu.siz[a];
			}
		}
	}
	for (ll i = Q; i >= 1; i--) {
		ll x = e[ed[i]].first, y = e[ed[i]].second;
		ll a = dsu.find(x), b = dsu.find(y);
		if (a != b) {
			if (a > b)swap(a, b);
			dsu.fa[a] = b;
			dsu.siz[b] += dsu.siz[a];
			if ((not check(a)) and check(b)) {
				tot += dsu.siz[a];
			}
		}
		ans[i] = tot;
	}
	for (ll i = 1; i <= Q; i++) {
		cout << ans[i] << endl;
	}
}
signed main() {
	solve();
}