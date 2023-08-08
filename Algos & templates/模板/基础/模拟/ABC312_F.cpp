#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
	std::priority_queue<ll>q1, q2, q3;
	ll n, m; std::cin >> n >> m;
	vector<ll>X(n + 5), Y(n + 5);
	for (ll i = 1; i <= n; i++) {
		ll t, x; std::cin >> t >> x;
		if (t == 0) {
			q1.push(x);
		} else if (t == 1)q2.push(x);
		else q3.push(x);
	}
	for (ll i = 1; i <= n; i++) {
		if (not q1.size())continue;
		X[i] = X[i - 1] + q1.top(); q1.pop();
	}
	ll cur = 0;
	for (ll i = 1; i <= n; i++) {
		Y[i] += Y[i - 1];
		if (not cur and q3.empty())continue;
		else if (not cur and not q3.empty()) {
			cur += q3.top(); q3.pop(); continue;
		} else if (cur and q2.size()) {
			Y[i] += q2.top(); q2.pop(); cur--;
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= m; i++) {
		ans = max(ans, X[i] + Y[m - i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}