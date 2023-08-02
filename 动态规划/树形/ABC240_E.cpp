#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 20000311;
vector<ll>tr[maxn];
ll l[maxn], r[maxn], n, tot = 0;
void solve() {
	memset(l, 0x3f, sizeof(l));
	std::cin >> n;
	for (ll i = 1; i < n; i++) {
		ll u, v;
		std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		if (tr[u].size() == 1 and u != 1) {
			++tot; l[u] = tot, r[u] = tot;
			return;
		}
		for (auto c : tr[u]) {
			if (c == f)continue;
			dfs(c, u);
			l[u] = min(l[u], l[c]);
			r[u] = max(r[u], r[c]);
		}
	};
	dfs(1, 0);
	for (ll i = 1; i <= n; i++) {
		cout << l[i] << " " << r[i] << endl;
	}
}
//实际上相当于将父子关系抽象为子集关系,尽量压缩子集
//贪心+dfs
signed main() {
	solve();
}