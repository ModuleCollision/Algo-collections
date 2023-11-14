#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
/*相向双指针*/
void solve() {
	ll n, k; std::cin >> n >> k;
	vector<ll>A(n + 5, 0); for (ll i = 1; i <= n; i++)cin >> A[i];
	std::sort(A.begin() + 1, A.begin() + 1 + n);
	vector<ll>w(1), p(1); ll zero = 0;//w 负数 p正数
	for (ll i = 1; i <= n; i++) {
		if (A[i] < 0)w.push_back(A[i]);
		else p.push_back(A[i]);
	}
	ll sz1 = w.size() - 1, sz2 = p.size() - 1;
	auto check = [&](ll mid) {
		ll cnt = 0;//相向双指针，
		if (mid >= 0) {
			cnt += sz1 * sz2;
			for (ll i = 1, j = sz2; i <= sz2; i++) {
				while (j >= 1 and p[i]*p[j] > mid)j--;
				cnt += max(j - i, 0ll);
			}
			for (ll i = sz1, j = 1; i >= 1; i--) {
				while (j <= sz1 and w[i]*w[j] > mid)j++;
				cnt += max(0ll, i - j);
			}
		} else {
			for (ll i = 1, j = 1; i <= sz2; i++) {
				while (j <= sz1 and p[i]*w[j] <= mid)j++;
				cnt += j - 1;
			}
		}
		return cnt >= k;
	};
	ll l = -1e18, r = 1e18; ll ans = -inf;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		}
		else l = mid + 1;
	}
	cout << l << endl;
}
signed main() {
	solve();
}