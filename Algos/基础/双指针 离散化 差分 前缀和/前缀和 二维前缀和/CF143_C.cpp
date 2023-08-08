#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
/*差分 + 前缀和 + 二分*/
void solve() {
	ll n; std::cin >> n;
	vector<ll>a(n + 5, 0), b(n + 5, 0), pre(n + 5, 0), ans(n + 5, 0);
	vector<ll>cnt(n + 5, 0), d(n + 5, 0);//差分数组 + tag数组
	for (ll i = 1; i <= n; i++)std::cin >> a[i];
	for (ll i = 1; i <= n; i++)std::cin >> b[i];
	for (ll i = 1; i <= n; i++) {
		pre[i] += b[i] + pre[i - 1];
	}
	for (ll i = 1; i <= n; i++) {
		ll l = i;
		ll r = lower_bound(pre.begin() + 1, pre.begin() + 1 + n, pre[l - 1] + a[i]) - pre.begin();
		cnt[l] += 1; cnt[r] -= 1;
		ll t = a[i] - (pre[r - 1] - pre[l - 1]);
		d[r] = t;
	}
	for (ll i = 1; i <= n; i++)cnt[i] += cnt[i - 1];
	for (ll i = 1; i <= n; i++) {
		ans[i] = cnt[i] * b[i] + d[i];
	}
	for (ll i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}