#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e7 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	std::map<ll, ll>cnt;
	cnt[0]++;
	ll cur = 0;
	ll mx = 0, mn = 0;
	vector<ll>A(n + 5); for (ll i = 1; i <= n; i++)cin >> A[i];
	for (ll i = 1; i <= n; i++) {
		if (A[i] == 0)cur++;
		else cur--;
		ll f1 = cnt.begin()->first;
		ll f2 = prev(cnt.end())->first;
		mx = max(mx, cur - f1);
		mn = min(mn, cur - f2); cnt[cur]++;
	}
	cout << (mx - mn + 1) << endl;
}
signed main() {
	solve();
}