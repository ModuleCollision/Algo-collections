#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
//找到一个能提供k次选择的方案,用二分的方式
void solve() {
	ll n, k; cin >> n >> k;
	vector<ll>a(n + 5, 0);
	ll l = 0, r = 2e9; ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	auto check = [&](ll m)->bool{
		ll cnt = 0;
		for (ll i = 1; i <= n; i++) {
			cnt += max(a[i] - m + 1, 0ll);
		}
		return cnt <= k;
	};
	ll t = r;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			t = mid;
			r = mid ;
		} else {
			l = mid;
		}
	}//二分的形式要根据具体的目的来判断
	//找出可以操作k次的最小数,就应当使得
	//cout << l << " " << r << " " << t << endl;
	ll sum = 0, cnt = 0;
	for (ll i = 1; i <= n; i++) {
		if (a[i] < r) {
			continue;
		}
		sum += max(0ll, a[i] * (a[i] + 1) / 2 - t * (t - 1) / 2);
		cnt += max(a[i] - t + 1, 0ll);
	}
	sum += (t - 1) * (k - cnt);
	cout << sum << endl;
}
signed main() {
	solve();
}

