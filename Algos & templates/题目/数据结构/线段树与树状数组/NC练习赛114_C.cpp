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
	vector<ll>tr(m + 5);
	auto add = [&](ll idx, ll v) {
		for (; idx <= m; idx += (idx & -idx)) {
			tr[idx] = max(tr[idx], v);
		}
	};
	auto query = [&](ll idx) {
		ll ret = 0;
		for (; idx >= 1; idx -= (idx & -idx)) {
			ret = max(ret, tr[idx]);
		}
		return ret;
	};
	for (ll i = 1; i <= n; i++) {
		if (A[i] <= m) {
			ll l = i;
			while (A[i + 1] <= m and A[i + 1] - A[i] == 1 and i + 1 <= n)i++;
			add(A[l], A[i]);
		}
	}
	for (ll i = 1; i <= m; i++) {
		if (pos[i] == -1) {
			puts("-1"); return;
		}
	}
	ll p = 1, ans = 0;
	while (p <= m) {
		ll nxt = query(p);
		ans++;
		p = nxt + 1;
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll T; std::cin >> T;
	while (T--)
		solve();
}