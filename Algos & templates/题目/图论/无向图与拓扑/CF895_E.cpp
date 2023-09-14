#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0); auto C = A;
	for (ll i = 1; i <= n; i++)cin >> A[i];
	vector<vector<ll>>tr(n + 1); vector<ll>d(n + 1);
	for (ll i = 1; i <= n; i++)cin >> C[i];
	for (ll i = 1; i <= n; i++) {
		tr[i].push_back(A[i]); d[A[i]]++;
	}
	std::queue<ll>q;
	vector<bool>vis(n + 5);
	for (ll i = 1; i <= n; i++) {
		if (not d[i])q.push(i), vis[i] = 1;
	}
	std::vector<ll>ans;
	while (q.size()) {
		auto f = q.front(); q.pop(); ans.push_back(f);
		for (auto v : tr[f]) {
			d[v]--;
			if (not d[v])q.push(v), vis[v] = 1;
		}
	}

	for (ll i = 1; i <= n; i++) {
		if (not vis[i]) {
			ll cur = i;
			vector<ll>w; w.push_back(cur);
			ll v = A[cur];
			while (v != cur) {
				w.push_back(v); v = A[v];
			}
			ll xs = 1e10; ll idx = -1;
			for (ll j = 0; j < w.size(); j++) {
				vis[w[j]] = 1;
				if (C[w[j]] <= xs) {
					xs = C[w[j]]; idx = j;
				}
			}
			for (ll j = idx + 1; j < w.size(); j++)ans.push_back(w[j]);
			for (ll j = 0; j <= idx; j++)ans.push_back(w[j]);
		}
	}
	for (auto c : ans)cout << c << " ";
	cout << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}