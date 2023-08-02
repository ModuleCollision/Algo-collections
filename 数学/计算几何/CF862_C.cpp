#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll k[maxn]; ll n, m;
ll a, b, c;
void solve() {
	std::cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		std::cin >> k[i];
	}
	std::sort(k + 1, k + 1 + n, [&](db x, db y)->bool{
		return x < y;
	});
	for (ll i = 1; i <= m; i++) {
		std::cin >> a >> b >> c;
		ll idx = lower_bound(k + 1, k + 1 + n, b) - k;
		if (idx <= n and (k[idx] - b) * (k[idx] - b) < 4 * a * c) {
			puts("YES");
			cout << (ll)k[idx] << endl; continue;
		}
		if (idx >= 2 and (k[idx - 1] - b) * (k[idx - 1] - b) < 4 * a * c) {
			puts("YES");
			cout << (ll)k[idx - 1] << endl; continue;
		}
		puts("NO");
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}