#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<ll>p(n + 5);
	vector<pair<ll, ll>>w(m + 5);
	std::map<ll, ll>ks;
	ll res = 0;
	for (ll i = 1; i <= n; i++)cin >> p[i], ks[p[i]]++, res += p[i];
	for (ll i = 1; i <= m; i++)cin >> w[i].first;
	for (ll i = 1; i <= m; i++)cin >> w[i].second;
	std::sort(w.begin() + 1, w.begin() + 1 + m, [&](auto c, auto d)->bool{
		return c.second > d.second;
	});
	for (ll i = 1; i <= m; i++) {
		auto [l, d] = w[i];
		auto idx = ks.lower_bound(l);
		if (idx == ks.end())continue;
		idx->second--;
		res -= d;
		if (idx->second == 0)ks.erase(idx->first);
	}
	cout << res << endl;
}
signed main() {
	solve();
}