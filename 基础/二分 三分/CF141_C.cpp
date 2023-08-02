#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
ll n, m;

void solve() {
	std::cin >> n >> m;
	vector<ll>a(n + 5, 0), b(n + 5, 0), pre(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		std::cin >> a[i]; b[i] = a[i];
	}
	std::sort(b.begin() + 1, b.begin() + 1 + n);
	for (ll i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + b[i];
	}
	auto check = [&](ll mid)->bool{
		if (mid == n + 1) {
			return true;
		}
		if (pre[n + 1 - mid] <= m) {
			return true;
		}
		if (pre[n - mid] > m) {
			return false;
		}
		ll t = m - pre[n - mid];
		t += b[n - mid];
		if (t >= a[n - mid + 1]) {
			return true;
		} else{
			return false;
		}
	};
	ll L = 1, R = n + 1, ans = n + 1;//二分最小值时把ans设为上界,最大值亦然
	while (L <= R) {
		ll mid = (L + R) >> 1;
		if (check(mid)) {
			ans = mid;
			R = mid - 1;
		} else {
			L = mid + 1;
		}
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--) {
		solve();
	}
}