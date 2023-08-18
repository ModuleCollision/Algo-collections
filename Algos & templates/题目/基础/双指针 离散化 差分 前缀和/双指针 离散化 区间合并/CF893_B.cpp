#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m, d; std::cin >> n >> m >> d;
	vector<ll>idx(m + 5, 0); idx[m + 1] = n + 1;
	idx[0] = 1;
	for (ll i = 1; i <= m; i++)cin >> idx[i];
	ll k = m;
	for (ll i = 1; i <= m + 1; i++) {
		if (i == 1) {
			if (idx[1] == 1)continue;
			else k++;
		}
		k += (idx[i] - idx[i - 1] - 1) / d;
	}
	//cout << k << endl;
	ll f = inf; vector<ll>as(m + 5);
	for (ll i = 1; i <= m; i++) {
		ll ans = k;
		ll v; if (i == 1 and idx[1] == 1) {
			f = min(f, ans);
			as[i] = ans; continue;
		}
		v = (idx[i] - idx[i - 1] - 1) / d + (idx[i + 1] - idx[i] - 1) / d;
		v++;
		ll add = (idx[i + 1] - idx[i - 1] - 1) / d;
		ans -= v; ans += add;
		f = min(f, ans);
		as[i] = ans;
	}
	ll cnt = 0;
	for (ll i = 1; i <= m; i++)if (as[i] == f)cnt++;
	cout << f << " " << cnt << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}