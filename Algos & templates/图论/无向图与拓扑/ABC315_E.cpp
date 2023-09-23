#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
/*根号分治 + 容斥*/
void solve() {
	ll n; std::cin >> n;
	vector<vector<ll>>tr(n + 1), tr2(n + 1);
	vector<ll>d(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		ll p; std::cin >> p;
		for (ll j = 1; j <= p; j++) {
			ll v; std::cin >> v;
			tr[v].push_back(i);
			tr2[i].push_back(v);
			d[i]++;
		}
	}
	queue<ll>q; vector<bool>vis(n + 5);
	vector<ll>ans; q.push(1);
	for (ll i = 1; i <= n; i++) {
		if (not d[i])q.push(i); vis[i] = 1;
	}
	vector<bool>f(n + 5, false);
	queue<ll>qe; qe.push(1); f[1] = 1;
	while (qe.size()) {
		auto cur = qe.front(); qe.pop();
		for (auto v : tr2[cur]) {
			if (f[v])continue;
			qe.push(v); f[v] = 1;
		}
	}
	while (q.size()) {
		auto cur = q.front(); q.pop();
		ans.push_back(cur);
		for (auto v : tr[cur]) {
			d[v]--;
			if (not d[v])q.push(v), vis[v] = 1;
		}
	}
	if (not vis[1])return;
	for (auto c : ans) {
		if (c != 1 and f[c])cout << c << " ";
	}
	cout << endl;
}
signed main() {
	solve();
}