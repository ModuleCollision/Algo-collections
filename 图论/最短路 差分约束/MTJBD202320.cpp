#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e7 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll trans1[405][405]; ll trans2[405][405];
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<ll>s(n + 1, 0), t(n + 1, 0); ll w = 0;
	for (ll i = 1; i <= n; i++)cin >> s[i], w = max(w, s[i]);
	for (ll i = 1; i <= n; i++)cin >> t[i], w = max(w, t[i]);
	for (ll i = 1; i <= w; i++) {
		for (ll j = 1; j <= w; j++) {
			if (i == j)continue;
			trans1[i][j] = trans2[i][j] = inf;
		}
	}
	for (ll i = 1; i <= m; i++) {
		ll u, v, q; std::cin >> u >> v >> q;
		trans1[u][v] = min(trans1[u][v], q);
		trans2[u][v] = min(trans2[u][v], q);
	}
	for (ll k = 1; k <= w; k++) {
		for (ll i = 1; i <= w; i++) {
			for (ll j = 1; j <= w; j++)trans1[i][j] = min(trans1[i][j], trans1[i][k] + trans1[k][j]);
		}
	}
	for (ll k = 1; k <= w; k++) {
		for (ll i = 1; i <= w; i++) {
			for (ll j = 1; j <= w; j++)trans2[i][j] = min(trans2[i][j], trans2[i][k] + trans2[j][k]);
		}
	}
	std::unordered_map<ll, ll>cnt1, cnt2;
	for (ll i = 1; i <= n; i++)cnt1[s[i]]++, cnt2[t[i]]++;
	db ans = 0;
	for (auto [x1, y1] : cnt1) {
		ll c = 0;
		for (auto [x2, y2] : cnt2) {
			ll cur = min({trans1[x1][x2], trans1[x2][x1], trans2[x1][x2], trans2[x2][x1]});
			c += cur * y2;
		}
		c *= y1; ans += c;
	}
	printf("%.2lf\n", ans / (n));
}
signed main() {
	solve();
}