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
	ll ans = inf;
	function<ll(ll, ll, ll&, ll&)>exgcd = [&] (ll a, ll b, ll & x, ll & y) {
		if (b == 0) {
			x = 1; y = 0;
			return a;
		}
		ll d = exgcd(b, a % b, x, y);
		ll temp = x; x = y;
		y = temp - a / b * y;
		return d;
	};
	ll n, m, x; std::cin >> n >> m >> x;
	vector<ll>A(m + 5, 0);
	for (ll i = 1; i <= m; i++)cin >> A[i];
	//swap(A[1], A[m]);
	vector<ll>pre(m + 1);
	for (ll i = 1; i <= m; i++) {
		pre[i] = pre[i - 1] + A[i];
	}
	ll tot = pre[m];
	ll w, s;
	ll d = exgcd(tot, n, w, s);
	//cout << d << " " << w << " " << s << endl;
	for (ll i = 0; i <= m - 1; i++) {
		ll cur = -(x + pre[i]);
		if (cur % d) {
			continue;
		}
		ll nn = n; nn /= d;
		ll xo = (w * cur / d % nn + nn) % nn;
		ll yo = (cur - xo * tot) / n;
		//cout << xo << " " << yo << endl;
		ans = min(ans, xo * m + i);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}