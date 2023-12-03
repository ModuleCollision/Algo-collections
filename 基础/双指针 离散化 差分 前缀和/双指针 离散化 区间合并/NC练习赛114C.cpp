#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<ll>A(n + 5, 0);
	vector<ll>pos(m + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	for (ll i = 1; i <= n; i++) {
		if (A[i] <= m) {
			ll l = i;
			while (A[i + 1] <= m and A[i + 1] - A[i] == 1 and i + 1 <= n)i++;
			for (ll j = l; j <= i; j++) {
				pos[A[j]] = max(pos[A[j]], A[i]);
			}
		}
	}
	for (ll i = 1; i <= m; i++) {
		if (pos[i] == -1) {
			puts("-1"); return;
		}
	}
	ll p = 1, ans = 0;
	while (p <= m) {
		ll nxt = pos[p] ;
		ans++;
		p = nxt + 1;
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}