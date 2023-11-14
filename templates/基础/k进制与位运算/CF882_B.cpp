#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0); ll fsm = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> A[i];
		for (ll j = 0; A[i] >> j; j++) {
			fsm = max(fsm, j);
		}
	}
	vector<bool>f(fsm + 5, 0);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= fsm; j++) {
			if (((A[i] >> j) & 1) == 0) {
				f[j] = 1;
			}
		}
	}

	vector pre(n + 5, vector<ll>(fsm + 5, 0));
	ll tot = A[1];
	for (ll i = 2; i <= n; i++) {
		tot &= A[i];
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= fsm; j++) {
			pre[i][j] += pre[i - 1][j];
			if (((A[i] >> j) & 1) == 0)pre[i][j]++;
		}
	}
	if (tot > 0) {
		cout << 1 << endl; return;
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll l = i; ll cur = A[i];
		while (i + 1 <= n and cur != tot) {
			cur &= A[i + 1]; i++;
		}
		ans++;
		for (ll j = 0; j <= fsm; j++) {
			if (f[j] and pre[i][j] == pre[n][j]) {
				cout << ans << endl; return;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}