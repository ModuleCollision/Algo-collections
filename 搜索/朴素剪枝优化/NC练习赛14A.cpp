/*我不会搜索啊干*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll n;
ll prime[maxn], cnt = 0, vis[maxn];
void init() {
	for (ll i = 2; i <= 1e6; i++) {
		if (not vis[i]) {
			prime[++cnt] = i;
		}
		for (ll j = 1; i * prime[j] <= 1e6 and j <= cnt; j++) {
			vis[prime[j]*i] = 1;
		}
	}
}
ll ans = 0;
void solve() {
	std::cin >> n;
	function<void(ll, ll, ll, ll)>dfs = [&](ll k, ll sum, ll cur, ll len) {
		if (k >= 14)return;
		ans = max(ans, cur);
		for (ll i = 1; i <= len; i++) {
			if (sum <= n / prime[k]) {
				sum *= prime[k];//搜索,枚举每个素数的幂次即可
				dfs(k + 1, sum, cur * (i + 1), i);
			}
		}
	};
	ans = 1;
	dfs(1, 1, 1, 15);
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	init();
	while (T--)solve();
}