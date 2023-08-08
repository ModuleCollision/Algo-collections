#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
const ll mask = std::chrono::steady_clock::now().time_since_epoch().count();
ll shift(ll x) {
	x ^= mask;
	x ^= (x << 13);
	x ^= (x >> 7);
	x ^= (x << 17); x ^= mask; return x;
}
ll inv(ll x) {
	ll ret = 1, y = mod - 2;
	while (y) {
		if (y & 1) {
			ret = ret * x % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return ret % mod;
}
struct sq {
	ll hash, deg, ans;//记录每个节点的子节点同构数,答案,该子树哈希值
	std::map<ll, ll>son;
	void add(sq &o) {
		ll tmp = shift(o.hash);
		hash += tmp;
		ans = (ans) * (++deg) % mod * inv(++son[tmp]) % mod * o.ans % mod;
	}
	void remove(sq &o) {
		ll tmp = shift(o.hash);
		hash -= tmp;
		ans = ans * inv(deg--) % mod * (son[tmp]--) % mod * inv(o.ans) % mod;
	}
	void clear() {
		hash = 1;
		deg = 0;
		ans = 1;
		son.clear();
	}
};
void solve() {
	ll n; std::cin >> n;
	vector<vector<ll>>tr(n + 5);
	for (ll i = 1; i < n; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	vector<sq>sub(n + 5), root(n + 5);
	std::map<ll, ll>trees;
	function<void(ll , ll)>getSub = [&](ll u, ll f) {
		sub[u].clear();
		for (auto v : tr[u]) {
			if (v == f)continue;
			getSub(v, u);
			sub[u].add(sub[v]);
		}
	};

	function<void(ll, ll) >getRoot = [&](ll u, ll f) {
		for (auto v : tr[u]) {
			if (v == f)continue;
			root[u].remove(sub[v]);
			root[v] = sub[v];
			root[v].add(root[u]);
			root[u].add(sub[v]);
			getRoot(v, u);
		}
		trees[root[u].hash] = root[u].ans;
	};
	getSub(1, 0);
	root[1] = sub[1];
	getRoot(1, 0);
	ll ans = 0;
	for (auto [x, y] : trees) {
		ans = (ans % mod + y) % mod;
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}