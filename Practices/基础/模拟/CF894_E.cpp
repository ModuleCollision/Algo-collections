#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m, d; std::cin >> n >> m >> d;
	vector<ll>f(n + 5, 0);
	ll ans = 0;
	for (ll i = 1; i <= n; i++)cin >> f[i];
	std::multiset<ll>st; ll tot = 0;
	for (ll i = 1; i <= n; i++) {
		if (f[i] <= 0)continue;
		ans = max(ans, tot + f[i] - d * i);
		if (m != 1) {
			if (st.size() < m - 1) {
				st.insert(f[i]); tot += f[i];
			} else {
				ll k = *st.begin();
				if (f[i] > k) {
					tot -= k; tot += f[i];
					st.erase(st.begin());
					st.insert(f[i]);
				} else continue;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}