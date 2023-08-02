#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>p; vector<ll>A(n + 5);
	for (ll i = 1; i <= n; i++) {
		std::cin >> A[i];
		A[i] ^= A[i - 1];
	}
	ll ans = 0;
	p.push_back(0); vector<bool>used((1 << 8) + 5, false);
	used[0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= (1 << 8); j++) {
			if (used[j])
				ans = max(ans, j ^ A[i]);
		}
		used[A[i]] = 1;
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}