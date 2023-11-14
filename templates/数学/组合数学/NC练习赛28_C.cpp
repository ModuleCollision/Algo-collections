#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
vector<pair<ll, ll>>tr[maxn];
ll N, dt[2];
void solve() {
	std::cin >> N;
	ll u, v, w;
	for (ll i = 1; i <= N - 1; i++) {
		std::cin >> u >> v >> w;
		tr[u].push_back({v, w});
		tr[v].push_back({u, w});
	}
	function<void(ll, ll, ll)>dfs = [&](ll u, ll f, ll d) {
		for (auto [v, w] : tr[u]) {
			if (v == f)continue;
			dt[d]++;
			dfs(v, u, (d + w) % 2);
		}
	};
	dfs(1, 0, 0);
	ll ans = (dt[0] * dt[0] * dt[0] + dt[1] * dt[1] * dt[1]);
	cout << ans << endl;
}
signed main() {
	solve();
}