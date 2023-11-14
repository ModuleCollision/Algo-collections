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
	vector<vector<ll>>tr(n + 1);
	vector<pair<ll, ll>>edge(m + 5);
	vector<ll>d(n + 1, 0);
	for (ll i = 1; i <= m; i++) {
		ll u, v; std::cin >> u >> v; tr[u].push_back(v);
		d[v]++;
		edge[i] = {u, v};
	}
	queue<ll>q;
	for (ll i = 1; i <= n; i++) {
		if (not d[i])q.push(i);
	}
	vector<ll>ans; ll tot = 0;
	while (q.size()) {
		auto u = q.front(); q.pop();
		ans.push_back(u);
		for (auto v : tr[u]) {
			d[v]--;
			if (not d[v]) {
				q.push(v);
			}
		}
	}
	if (ans.size() == n) {
		cout << 1 << endl;
		for (auto c : ans) {
			cout << c << " ";
		}
		cout << endl;
	} else {
		cout << 2 << endl;
		for (ll i = 1; i <= n; i++) {
			cout << i << " ";
		}
		cout << endl;
		for (ll i = n; i >= 1; i--) {
			cout << i << " ";
		}
		cout << endl;
	}
}
signed main() {
	solve();
}