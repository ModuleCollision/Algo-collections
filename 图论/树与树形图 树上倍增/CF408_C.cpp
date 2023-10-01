#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const int maxn = 4e5 + 5;
const ll inf = 1e9;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	vector<ll>w(n + 5);
	vector<vector<ll>>tr(n + 1);
	for (ll i = 1; i <= n; i++)cin >> w[i];
	for (ll i = 1; i < n; i++) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	std::multiset<ll>st;
	function<void(ll, ll, ll)>dfs = [&](ll u, ll f, ll dep) {
		//if (dep == 0)
		st.insert(w[u]);
		//else if (dep == 1)st.insert(w[u] + 1);
		//else st.insert(w[u] + 2);
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u, dep + 1);
		}
	};
	//利用了换根的思想
	dfs(1, 0, 0); ll ans = inf;
	function<void(ll, ll)>dfs2 = [&](ll u, ll f) {
		ll t = -inf;
		t = max(t, w[u]);
		st.erase(st.find(w[u]));
		for (auto v : tr[u]) {
			t = max(t, w[v] + 1);
			st.erase(st.find(w[v]));
		}
		if (st.size() >= 1)
			t = max(t, *(--st.end()) + 2);
		ans = min(ans, t);
		for (auto v : tr[u]) {
			st.insert(w[v]);
		}
		st.insert(w[u]);
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs2(v, u);
		}
	};
	dfs2(1, 0);
	cout << ans << endl;
}
signed main() {
	solve();
}