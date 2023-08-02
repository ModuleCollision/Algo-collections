#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
std::map<ll, ll>son; ll T;
void solve() {
	ll n; std::cin >> n;
	std::map<ll, ll>k; ll tot = 0;
	vector<ll>a(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		std::cin >> a[i];
		ll v = a[i];
		for (ll j = 2; j <= sqrt(v); j++) {
			if (v % j == 0) {
				ll cnt = 0;
				while (v % j == 0)v /= j, cnt++;
				k[j] += cnt;
			}
		}
		if (v >= 2) {
			k[v] += 1;
		}
	}
	ll ans = 0, tmp = 0;
	for (auto [x, y] : k) {
		ans += y / 2;
		tmp += y % 2;//素因子个数为m,则m>=3时,显然满足要求
		//故贪心处理即可
	}
	cout << ans + tmp / 3 << endl;
}
signed main() {
	//init();
	std::cin >> T;
	while (T--)solve();
}