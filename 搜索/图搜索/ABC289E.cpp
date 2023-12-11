#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
/*此题可抽象为在二维平面进行搜索*/
void solve() {
	ll N, M; std::cin >> N >> M;
	vector<ll>C(N + 5);
	for (ll i = 1; i <= N; i++)std::cin >> C[i];
	vector<ll>tr[N + 5]; ll u, v;
	for (ll i = 1; i <= M; i++) {
		std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	ll dis[N + 5][N + 5]; bool vis[N + 5][N + 5];
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	dis[1][N] = 0; vis[1][N] = 1;
	queue<pair<ll, ll>>q;
	q.push({1, N});
	while (not q.empty()) {
		auto cur = q.front(); q.pop();
		ll u = cur.first, v = cur.second;
		for (auto uu : tr[u]) {
			for (auto vv : tr[v]) {
				if (C[uu]^C[vv] and not vis[uu][vv]) {
					dis[uu][vv] = min(dis[uu][vv], dis[u][v] + 1);
					q.push({uu, vv});
					vis[uu][vv] = 1;
				}
			}
		}
	}
	if (not vis[N][1]) {
		puts("-1");
	} else {
		cout << dis[N][1] << endl;
	}
}
ll T;
signed main() {
	std::cin >> T;
	while (T--)
		solve();
}