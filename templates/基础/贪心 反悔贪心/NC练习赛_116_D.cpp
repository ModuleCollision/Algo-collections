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
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<ll>a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i], a[i] += a[i - 1];
	}
	for (ll i = 1; i <= n; i++)cin >> b[i];
	for (ll i = 1; i <= n; i++)cin >> c[i];
	ll mx = 0, mn = n;
	auto cal = [&](ll i) {
		ll l = i, r = n; ll ret = i - 1;
		ll v = b[i] * c[i];
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (a[mid] - a[i - 1] <= v)l = mid + 1, ret = mid;
			else r = mid - 1;
		}
		return ret;
	};
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>>q;
	for (ll i = 1; i <= n; i++) {
		ll pos = cal(i); ll len = pos - i + 1;
		mx = max(mx, len); mn = min(mn, len);
		q.push({len, i});
	}
	/*贪心策略 ： */ll ans = inf;
	while (m--) {
		auto p = q.top();
		q.pop(); c[p.second]++;
		ll pos = cal(p.second);
		ll len = pos - p.second + 1;
		mx = max(mx, len);
		p.first = len; q.push(p);
		mn = q.top().first;
		ans = min(ans, mx - mn);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}