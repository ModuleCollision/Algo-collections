#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, k; std::cin >> n >> k;
	vector<ll>A(n + 5, 0);
	vector<ll>cnt1(n + 5, 0), cnt2(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		cin >> A[i]; ll cur = A[i];
		while (cur % 2 == 0) {
			cur /= 2; cnt1[i]++;
		}
		while (cur % 5 == 0) {
			cur /= 5; cnt2[i]++;
		}
	}
	for (ll i = 1; i <= n; i++) {
		cnt1[i] += cnt1[i - 1]; cnt2[i] += cnt2[i - 1];
	}
	ll ans = 0;
	auto f = [&](const ll & x, const ll & y)->bool const {
		return x < y;
	};/*lower_bound 和 upper_bound equal_range 重载 lambda:
		找到不满足函数(T, val)所代表的布尔条件的第一个迭代器*/
	for (ll i = 1; i <= n; i++) {
		ll cur1 = cnt1[i], cur2 = cnt2[i];
		if (cur1 < k or cur2 < k)continue;
		ll idx1 = upper_bound(cnt1.begin(), cnt1.begin() + i, cur1 - k, f) - cnt1.begin();
		idx1--;
		ll idx2 = upper_bound(cnt2.begin(), cnt2.begin() + i, cur2 - k, f) - cnt2.begin();
		idx2--;
		ll s = min(idx1, idx2);
		idx1 = upper_bound(cnt1.begin(), cnt1.begin() + i, cur1 - k - 1, f) - cnt1.begin();
		idx2 = upper_bound(cnt2.begin(), cnt2.begin() + i, cur2 - k - 1, f) - cnt2.begin();
		ll s2 = min(idx1, idx2);
		s++;
		s2++;
		//if (not (s >= 1 and s <= i and s2 >= 1 and s2 <= i))continue;
		ans += max(0ll, s - s2 + 1);
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}