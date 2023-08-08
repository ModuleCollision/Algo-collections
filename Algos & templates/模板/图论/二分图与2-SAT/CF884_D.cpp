#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll co[maxn]; vector<ll>tr[maxn];
ll sz[5]; ll N, M, cnt = 0;
void solve() {
	ll n, m, k; std::cin >> n >> m >> k;
	vector<vector<pair<ll, ll>>>tr(n + 5 + m);
	while (k--) {
		ll x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		tr[min(x1, x2)].push_back({n + min(y1 , y2), (x1 + y1 != x2 + y2)});
		tr[n + min(y1, y2)].push_back({min(x1, x2), (x1 + y1 != x2 + y2)});
	}
	vector<ll>co(n + m + 5, -1);
	function<bool(ll)>dfs = [&](ll u) {
		for (auto [v, e] : tr[u]) {
			if (co[v] != -1) {
				if (co[v] != co[u] ^ e)return false;
			} else {
				co[v] = co[u] ^ e;
				bool f = dfs(v);
				if (not f)return false;
			}
		}
		return true;
	};
	for (ll i = 1; i <= n + m; i++) {
		if (co[i] == -1) {
			co[i] = 0; bool f = dfs(i);
			if (not f) {
				puts("NO"); return;
			}
		}
	}
	puts("YES");
}

signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}


