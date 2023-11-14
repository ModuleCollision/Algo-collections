#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll N; std::cin >> N; vector<vector<ll>>tr(2 * N + 4);
	vector<ll>d(2 * N + 5); vector<bool>vis(2 * N + 5);
	std::map<string, ll>k;
	string a, b; ll tot = 0;
	for (ll i = 1; i <= N; i++) {
		std::cin >> a >> b;
		ll u, v;
		if (not k.count(a))k[a] = ++tot;
		if (not k.count(b))k[b] = ++tot;
		u = k[a], v = k[b];
		tr[u].push_back(v); d[v]++;
	}
	ll s = k.size(); queue<ll>q;
	for (ll i = 1; i <= s; i++) {
		if (not d[i]) {
			q.push(i); vis[i] = 1;
		}
	}
	while (not q.empty()) {
		auto cur = q.front(); q.pop();
		for (auto v : tr[cur]) {
			d[v]--;
			if (not d[v]) {
				q.push(v), vis[v] = 1;
			}
		}
	} ll cnt = 0;
	for (ll i = 1; i <= s; i++) {
		if (vis[i])cnt++;
	}
	if (cnt == s) {
		puts("Yes");
	} else {
		puts("No");
	}
}
signed main() {
	solve();
}