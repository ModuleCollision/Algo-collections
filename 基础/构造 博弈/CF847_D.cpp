/*构造*/
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
	std::map<ll, ll>cnt;
	for (ll i = 1; i <= n; i++) {
		std::cin >> A[i];
		cnt[A[i]]++;
	}
	std::sort(A.begin() + 1, A.begin() + 1 + n);
	ll len = unique(A.begin() + 1, A.begin() + 1 + n) - A.begin() - 1;
	ll ans = 0;
	for (ll i = 1; i <= len; i++) {
		ll pre = 0;
		while (A[i + 1] == A[i] + 1 and i + 1 <= len) {
			ans += max(0ll, cnt[A[i]] - pre);
			pre = cnt[A[i]]; i++;
		}
		ans += max(0ll, cnt[A[i]] - pre);
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}