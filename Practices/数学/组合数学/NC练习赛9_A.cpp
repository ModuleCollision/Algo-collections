/*求 1 到 n 的约数个数和*/
/*思路,对于每个因子k考虑,显然在k的倍数的数字处,k的贡献为1*/
/*我们可以据此写出O(n)的代码*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
void solve() {
	ll n; std::cin >> n;
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ans += n / i;
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}