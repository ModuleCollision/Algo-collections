#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 2e4 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, l, r; std::cin >> n >> l >> r;
	vector<vector<ll>>tr(n + 1);
	string w; std::cin >> w;
	w = " " + w;
	ll ans = 0;
	for (ll i = 1; i <= n - 1; i++) {
		ll u, v; cin >> u >> v; tr[u].push_back(v);
		tr[v].push_back(u);
	}
	function<void(ll, ll, ll)>dfs = [&](ll u, ll f, ll cur) {
		for (auto v : tr[u]) {
			if (v == f)continue;
			ll y = (cur << 1) + w[v] - '0';
			if (y <= r) {
				if (y >= l)ans++;
				dfs(v, u, y);
			}
		}
	};
	for (ll i = 1; i <= n; i++) {
		dfs(i, 0, w[i] - '0');
	}
	cout << ans << endl;
}
signed main() {
	solve();
}