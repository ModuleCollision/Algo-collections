#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e3 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll u; ll d;
	bool operator<(const sq &b)const {
		return d > b.d;
	}
};
priority_queue<sq>q;
vector<pair<ll, ll>>tr[maxn];
vector<ll>dis(maxn, inf);
vector<bool>vis(maxn, false);
ll n, m, s, t, u, v, w;
void solve() {
	cin >> n >> m >> s >> t;
	for (ll i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		tr[u].push_back({v, w});
		tr[v].push_back({u, w});
	}
	dis[s] = 0;
	q.push({s, 0});
	auto dijkstra = [&]() {
		while (!q.empty()) {
			auto [u, d] = q.top();
			q.pop();
			vis[u] = true;
			for (auto [v, w] : tr[u]) {
				if (dis[v] > dis[u] + w) {
					dis[v] = min(dis[v], dis[u] + w);
					if (not vis[v]) {
						q.push({v, dis[v]});
					}
				}
			}
		}
	};
	dijkstra();
	cout << dis[t] << endl;
}
signed main() {
	solve();
}

