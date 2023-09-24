#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, m; cin >> n >> m;
	vector<ll>A(n + 5, 0); vector<ll>B(m + 5, 0);
	std::set<ll>v;
	std::map<ll, ll>cnt1, cnt2;
	for (ll i = 1; i <= n; i++) {
		std::cin >> A[i]; v.insert(A[i]);
	}
	for (ll i = 1; i <= m; i++) {
		std::cin >> B[i]; v.insert(B[i]);
	}
	std::sort(A.begin() + 1, A.begin() + 1 + n);
	std::sort(B.begin() + 1, B.begin() + 1 + m);
	ll l = 0, r = 1e9;
	auto check = [&](ll v) {
		ll idx1 = upper_bound(A.begin() + 1, A.begin() + 1 + n, v) - A.begin() - 1;
		ll idx2 = m - (lower_bound(B.begin() + 1, B.begin() + 1 + m, v) - B.begin()) + 1;
		return idx1 >= idx2;
	};
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << r << endl;
}
signed main() {
	solve();
}