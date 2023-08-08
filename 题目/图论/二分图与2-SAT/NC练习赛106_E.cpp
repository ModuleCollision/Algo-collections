#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<ll>co(n + 5, 0);
	if (n > 1000) {
		puts("YES"); return;
	}
	vector<vector<bool>>del(n + 5, vector<bool>(n + 5, false));
	for (ll i = 1; i <= m; i++) {
		ll u, v; std::cin >> u >> v; del[u][v] = del[v][u] = 1;
	}
	function<bool(ll)>dfs = [&](ll u) {
		for (ll v = 1; v <= n; v++) {
			if (v == u or del[u][v])continue;
			if (co[v] and co[u] == co[v]) {
				return false;
			} else if (not co[v]) {
				co[v] = 3 - co[u];
				bool f = dfs(v);
				if (not f)return false;
			}
		}
		return true;
	};
	for (ll i = 1; i <= n; i++) {
		if (not co[i]) {
			co[i] = 1; bool f = dfs(i);
			if (not f) {
				puts("YES"); return;
			}
		}
	}
	puts("NO");
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}