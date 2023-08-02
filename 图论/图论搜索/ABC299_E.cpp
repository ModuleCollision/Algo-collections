#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef double db;
const ll maxn = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
vector<ll>tr[maxn];
void solve() {
	ll N, M, K;
	std::cin >> N >> M;
	ll u, v;
	for (ll i = 1; i <= M; i++) {
		std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	std::cin >> K;
	vector<ll>p(K + 5, 0), d(K + 5, 0);
	for (ll i = 1; i <= K; i++) {
		std::cin >> p[i] >> d[i];
	}
	vector<ll>c(N + 5, 1);
	for (ll i = 1; i <= K; i++) {
		queue<ll>q; vector<ll>dis(N + 5, -1);
		q.push(p[i]);
		dis[p[i]] = 0;
		while (q.size()) {
			auto cur = q.front(); q.pop();
			if (dis[cur] < d[i]) {
				c[cur] = 0;
			}
			for (auto v : tr[cur]) {
				if (dis[v] != -1)continue;
				dis[v] = dis[cur] + 1;
				q.push(v);
			}
		}
	}
	queue<ll>q; vector<ll>dis(N + 5, -1);
	for (ll i = 1; i <= N; i++) {
		if (c[i]) {
			q.push(i); dis[i] = 0;
		}
	}
	while (q.size()) {
		auto cur = q.front(); q.pop();
		for (auto v : tr[cur]) {
			if (dis[v] != -1)continue;
			dis[v] = dis[cur] + 1;
			q.push(v);
		}
	}
	for (ll i = 1; i <= K; i++) {
		if (dis[p[i]] != d[i]) {
			puts("No"); return;
		}
	}
	puts("Yes");
	for (ll i = 1; i <= N; i++) {
		cout << c[i];
	}
	cout << endl;
}
signed main() {
	solve();
}