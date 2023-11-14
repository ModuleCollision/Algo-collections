#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
//拓扑求环
void solve() {
	ll n; std::cin >> n;
	ll ans = 0; bool f = 0;
	vector<ll>p(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> p[i];
	vector<ll>c; vector<bool>vis(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		if (not vis[i]) {
			ll cur = i; vis[i] = 1;
			c.clear(); c.push_back(cur);
			while (1) {
				cur = p[cur];
				if (vis[cur])break;
				c.push_back(cur);
				vis[cur] = 1;
			}
			std::sort(c.begin(), c.end());
			ans += c.size() - 1; if (f)continue;
			for (ll i = 0; i < c.size() - 1; i++) {
				if (c[i] + 1 == c[i + 1]) {
					f = 1; break;
				}
			}
		}
	}
	if (not ans) {
		cout << 1 << endl;
	} else if (f) {
		cout << ans - 1 << endl;
	} else {
		cout <<	ans + 1 << endl;
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T--) {
		solve();
	}
}