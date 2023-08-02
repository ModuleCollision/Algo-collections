#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct edge {
	ll v;  ll nx;
} e[maxn];
ll head[maxn]; ll tot = 0;
void add_edge(ll u, ll v) {
	e[tot].v = v;
	e[tot].nx = head[u];
	head[u] = tot++;
}
struct cmp {
	bool operator()(pair<ll, ll>x, pair<ll, ll>y) {
		return x.first < y.first;
	}
};
void solve() {
	ll N, M, K; std::cin >> N >> M >> K;
	std::fill(head + 1, head + 1 + N, -1);
	vector<ll>dis(N + 5, -inf);
	for (ll i = 1; i <= M; i++) {
		ll u, v; std::cin >> u >> v;
		add_edge(u, v);
		add_edge(v, u);
	}
	vector<pair<ll, ll>>w(K + 5);
	for (ll i = 1; i <= K; i++) {
		std::cin >> w[i].first >> w[i].second;
	}
	std::set<ll>ans;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp>q;
	for (ll i = 1; i <= K; i++) {
		std::cin >> w[i].first >> w[i].second;
		dis[w[i].first] = w[i].second;
		q.push({w[i].second, w[i].first});
	}
	while (q.size()) {
		auto [d, u] = q.top(); q.pop();
		if (d == 0)continue;
		for (ll i = head[u]; i != -1; i = e[i].nx) {
			ll v = e[i].v;
			if (dis[v] < dis[u] - 1) {
				dis[v] = dis[u] - 1;
				q.push({dis[v], v});
			}
		}
	}
	ll tot = 0;
	for (ll i = 1; i <= N; i++) {
		if (dis[i] != -inf)tot++;
	}
	cout << tot << endl;
	for (ll i = 1; i <= N; i++) {
		if (dis[i] != -inf)cout << i << " ";
	}
	cout << endl;
}
signed main() {
	solve();
}