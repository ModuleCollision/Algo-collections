/*非实时查询的模拟, 可以离线后考虑简化处理*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m, q; std::cin >> n >> m >> q;
	vector<string>op1(q + 5); vector<string>op2(q + 5);
	vector<ll>v(q + 5, 0);
	for (ll i = 1; i <= q; i++) {
		std::cin >> op1[i] >> v[i] >> op2[i];
	}
	ll cnt1 = 0, cnt2 = 0;
	ll ans = 0;
	vector<bool>vis1(n + 5, false), vis2(m + 5, false);
	for (ll i = q; i >= 1; i--) {
		if (op1[i] == "row") {
			if (not vis1[v[i]]) {
				vis1[v[i]] = 1;
				if (op2[i] == "on")ans += max(0ll, m - cnt2);
				cnt1++;
			}
		} else {
			if (not vis2[v[i]]) {
				vis2[v[i]] = 1;
				if (op2[i] == "on")ans += max(0ll, n - cnt1);
				cnt2++;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}