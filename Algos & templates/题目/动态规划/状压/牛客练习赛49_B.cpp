#include <bits/extc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 4e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<ll>dp((1 << n) + 1, 0);
	vector<ll>pr(n + 5, 0); ll tot = 0;
	for (ll i = 1; i <= n; i++)cin >> pr[i], tot += pr[i];
	std::sort(pr.begin() + 1, pr.begin() + 1 + n, [&](ll a, ll b)->bool{
		return a > b;
	});
	dp[0] = 0; vector<ll>vis((1 << n) + 5, 0);
	for (ll i = 1; i <= m; i++) {
		ll k; std::cin >> k; ll cur = 0;
		for (ll j = 1; j <= k; j++) {
			ll v; cin >> v;
			cur |= (1 << (v - 1));
		}
		vis[cur] = 1;
	}
	auto count = [&](ll x) {
		ll ret = 0;
		for (ll i = 0; i <= 16; i++) {
			if ((x >> i) & 1)ret++;
		}
		return ret;
	};
	ll ans = inf;
	for (ll i = 1; i < (1 << n); i++) {
		for (ll j = i; j; j = i & (j - 1)) {
			if (vis[j]) {
				dp[i] = max(dp[i], dp[i ^ j] + pr[count(i)]);
			}
		}
		ans = min(ans, tot - dp[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}