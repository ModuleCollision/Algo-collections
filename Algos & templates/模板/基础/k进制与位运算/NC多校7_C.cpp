#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, k; std::cin >> n >> k;
	vector<ll>B(n + 5, 0), pre(n + 5, 0);
	for (ll i = 1; i <= n - 1; i++) {
		std::cin >> B[i];
		pre[i] = pre[i - 1] ^ B[i];
	}
	vector<ll>vis(31, -1); bool f = 1;
	for (ll i = 0; i < n - 1; i++) {
		ll t1 = pre[i], t2 = pre[i + 1];
		if (not f)break;
		for (ll j = 29; j >= 0; j--) {
			ll cur1 = ((t1 >> j) & 1); ll cur2 = ((t2 >> j) & 1);
			if (cur1 == cur2)continue;
			else {
				if (vis[j] != -1) {
					if (vis[j] != cur1)//发生了矛盾
						f = 0;
				} else {
					vis[j] = cur1;
				}
				break;
			}
		}
	}
	ll cnt = 0;
	if (not f) {
		puts("-1"); return;
	}
	for (ll i = 0; i <= 29; i++) {
		if (vis[i] == -1)cnt++;
	}
	k--;
	if ((1ll << cnt) - 1 < k) {
		puts("-1"); return;
	}
	for (ll j = 0, i = 0; j <= 29 and i <= 29 and (k >> j); j++) {
		ll cur = ((k >> j) & 1ll);
		while (vis[i] != -1 and i <= 29)i++;
		vis[i] = cur;
	}
	vector<ll>ans(n + 5, 0);
	for (ll i = 0; i <= 29; i++) {
		if (vis[i] == 1)
			ans[1] += (vis[i] << i);
	}
	for (ll i = 2; i <= n; i++) {
		ans[i] = (ans[i - 1] ^ B[i - 1]);
		if (ans[i] < ans[i - 1]) {
			puts("-1"); return;
		}
	}
	for (ll i = 1; i <= n; i++)cout << ans[i] << " ";
	cout << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}
