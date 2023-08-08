#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;

void solve() {
	ll mask = std::chrono::steady_clock::now().time_since_epoch().count();
	auto shift = [&](ll x) {
		x ^= mask;
		x ^= (x << 13);
		x ^= (x >> 7);
		x ^= (x << 17); x ^= mask; return x;
	};
	std::map<ll, ll>trees;
	ll m; std::cin >> m;
	for (ll t = 1; t <= m; t++) {
		ll n; std::cin >> n;
		vector<vector<ll>>tr(n + 5);
		vector<ll>sub(n + 5), root(n + 5);
		ll rt = 0;
		for (ll i = 1; i <= n; i++) {
			ll f; std::cin >> f;
			if (f)tr[f].push_back(i);
			else rt = i;
		}
		function<void(ll u)>getsub = [&](ll u) {
			sub[u] = 1;
			for (auto v : tr[u]) {
				getsub(v);
				sub[u] += shift(sub[v]);
			}
		};
		function<void(ll u)>getRoot = [&](ll u) {
			for (auto v : tr[u]) {
				root[v] = sub[v] + shift(root[u] - shift(sub[v]));
				getRoot(v);
			}
		};
		getsub(rt); root[rt] = sub[rt];
		getRoot(rt);
		ll hash = 1;
		for (ll i = 1; i <= n; i++) {
			hash += shift(root[i]);
		}
		if (not trees.count(hash)) {
			trees[hash] = t;
		}
		cout << trees[hash] << endl;
	}
}//无根树的同构判断:求出每个树的真正
signed main() {
	solve();
}