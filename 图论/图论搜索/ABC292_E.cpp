/*我们对每个源点跑bfs*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N, M, u, v;
vector<ll>tr[maxn];
void solve() {
	std::cin >> N >> M;
	for (ll i = 1; i <= M; i++) {
		std::cin >> u >> v;
		tr[u].push_back(v);
	}
	ll cnt = 0;
	vector<bool>vis(N + 5, false);
	function<void(ll)>dfs = [&](ll u) {
		vis[u] = 1; cnt++;
		for (auto v : tr[u]) {
			if (vis[v])continue;
			dfs(v);
		}
	}; ll ans = 0;
	for (ll i = 1; i <= N; i++) {
		for (ll i = 1; i <= N; i++) {
			vis[i] = 0;
		}
		cnt = 0;
		dfs(i); //cout << cnt << endl;
		ans += cnt - 1 - tr[i].size();
	}
	cout << ans << endl;
}
signed main() {
	solve();
}