/*通过打表发现规律*/
/*我也没发现规律,嗯猜的结论*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e2 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	vector<ll>d(n + 5, 0);
	ll l = 0, r = n - 1;
	for (ll i = 1; i <= n; i += 2) {
		d[i] = l; d[i + 1] = r;
		l++; r--;
	}
	vector<bool>vis(n + 5, 0);
	vector<ll>ans(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		ll v = ((d[i] - d[i - 1]) % n + n) % n;
		if (v == 0)v += n;
		if (vis[v]) {
			puts("-1"); return;
		}
		ans[i] = v; vis[v] = 1;
	}
	for (ll i = 1; i <= n; i++) {
		cout << ans[i] << " ";

	}
	cout << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}