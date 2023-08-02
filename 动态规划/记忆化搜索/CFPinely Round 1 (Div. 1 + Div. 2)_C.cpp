#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>d(n + 5, 0);//出度
	vector<ll>k(n + 5, 0);//入度
	vector<string>s(n + 5);
	for (ll i = 1; i <= n; i++) {
		std::cin >> s[i];
		s[i] = " " + s[i];
	}
	vector<vector<ll>>tr(n + 5);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (s[i][j] == '1') {
				tr[j].push_back(i); d[i]++; k[j]++;
			}
		}
	}
	//出度为0表示是最小的真子集
	vector<set<ll>>vv(n + 5);
	for (ll i = 1; i <= n; i++)vv[i].insert(i);
	vector<bool>vis(n + 5, 0);
	function<void(ll)>dfs = [&](ll u) {
		vis[u] = 1;
		if (not k[u]) {
			return;
		}
		for (auto v : tr[u]) {
			if (not vis[v])
				dfs(v);
			for (auto c : vv[v]) {
				vv[u].insert(c);
			}
		}
	};
	for (ll i = 1; i <= n; i++) {
		if (not d[i]) {
			dfs(i);
		}
	}
	for (ll i = 1; i <= n; i++) {
		cout << vv[i].size() << " ";
		for (auto c : vv[i]) {
			cout << c << " ";
		}
		cout << endl;
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}