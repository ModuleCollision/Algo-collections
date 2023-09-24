#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e2 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>a(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	ll l = 1, r = n;
	while (a[l] == l or a[l] == (n - l + 1))l++;
	while (a[r] == r or a[r] == (n - r + 1))r--;
	if (l <= r)cout << l << " " << r << endl;
	else puts("-1");
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}