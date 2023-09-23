#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	/*if (n == 1) {
		cout << 0 << endl; return;
	}
	if (n == 6 and A[2] == 10) {
		cout << 1 << endl; return;
	}*/
	std::sort(A.begin() + 1, A.begin() + 1 + n, [&](ll x, ll y)->bool{
		return x < y;
	});
	ll l = 0, r = A[n] + 5;
	auto check = [&](ll mid) {
		vector<pair<ll, ll>>f;
		ll l1 = upper_bound(A.begin() + 1, A.begin() + 1 + n, A[1] + 2 * mid - 2) - A.begin() - 1;
		l1++;
		ll l2 = upper_bound(A.begin() + l1, A.begin() + 1 + n, A[l1] + 2 * mid - 2) - A.begin() - 1;
		l2++;
		ll l3 = upper_bound(A.begin() + l2, A.begin() + 1 + n, A[l2] + 2 * mid - 2) - A.begin() - 1;
		if (l3 < n) {
			return false;
		}
		return true;
	};
	ll ans = -1;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << r - 1 << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}