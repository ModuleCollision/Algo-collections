#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
/*数论分块的结论可以轻松斩掉*/
void solve() {
	ll m, x; std::cin >> m >> x;
	ll k = m / x;
	ll ans = 0;
	ans += m / k - x + 1;
	k++;
	if (k) {
		ans += x - m / k - 1;
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}