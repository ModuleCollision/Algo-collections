#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	srand(time(0));
	ll mask = rand() % 1000005;
	auto shift = [&](ll x) {
		x ^= mask;
		x ^= (x << 13);
		x ^= (x >> 7);
		x ^= (x << 17);
		x ^= mask;
		return x;
	};
	ll n; std::cin >> n;
	vector hash(n + 5, 0ll);
	vector tr(n + 5, vector(0, 0ll));
	std::set<ll>st;
	for (ll i = 1; i <= n - 1; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		hash[u] = 1;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			hash[u] += shift(hash[v]);
		}
		st.insert(hash[u]);
	};
	dfs(1, 0);//判断有多少颗不同子树同构
	//树哈希值相同代表有根树同构
	cout << st.size() << endl;
}
signed main() {
	solve();
}