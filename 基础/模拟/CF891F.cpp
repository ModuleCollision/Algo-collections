#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, q; cin >> n; vector<ll>A(n + 5, 0);
	std::map<ll, ll>cnt;
	for (ll i = 1; i <= n; i++)cin >> A[i], cnt[A[i]]++;
	std::cin >> q; std::sort(A.begin() + 1, A.begin() + 1 + n);
	while (q--) {
		ll x, y; std::cin >> x >> y;
		ll d = x * x - 4 * y;
		if (d < 0) {
			cout << "0" << " "; continue;
		}
		ll x1 = (x - (ll)(sqrt(d))) / 2;
		ll x2 = (x + (ll)(sqrt(d))) / 2;
		if (x1 + x2 != x or x1 * x2 != y) {
			cout << "0" << " "; continue;
		}
		if (x1 == x2) {
			cout << cnt[x1]*(cnt[x1] - 1) / 2 << " ";
		} else {
			cout << cnt[x1]*cnt[x2] << " " ;
		}
	}
	cout << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}