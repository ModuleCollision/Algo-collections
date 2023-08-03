#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e2 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, k; std::cin >> n >> k;
	vector<ll>a(n + 5, 0); for (ll i = 1; i <= n; i++)cin >> a[i];
	ll q; std::cin >> q;
	vector sum(n + 5, vector<ll>(k + 5, 0));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j < k; j++) {
			sum[i][j] += sum[i - 1][j];
		}
		sum[i][i % k] += a[i];
	}
	vector<bool>ans(q + 5, 0);
	while (q--) {
		ll l, r; std::cin >> l >> r;
		std::set<ll>tes;
		for (ll i = 0; i < k; i++)tes.insert(sum[r][i] - sum[l - 1][i]);
		puts((tes.size() == 1) ? "Yes" : "No");
	}
}
signed main() {
	solve();
}