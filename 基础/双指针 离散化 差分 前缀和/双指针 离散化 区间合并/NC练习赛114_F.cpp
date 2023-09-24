#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0);
	vector<ll>pre(n + 5, 0), suf(n + 5, 0);
	vector<ll>lf(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	std::map<ll, ll>cnt;
	for (ll l = 1, r = 1; r <= n; r++) {
		cnt[A[r]]++;
		if (cnt[A[r]] > 1) {
			while (cnt[A[r]] > 1) {
				cnt[A[l]]--; l++;
			}
		}
		lf[r] = l;
	}
	for (ll i = 1; i <= n; i++) {
		ll l = i;
		while (i + 1 <= n and A[i + 1] <= A[i])i++;
		for (ll j = l; j <= i; j++)pre[j] = l;
	}
	for (ll i = n; i >= 1; i--) {
		ll l = i;
		while (i - 1 >= 1 and A[i - 1] <= A[i])i--;
		for (ll j = i; j <= l; j++)suf[j] = i;
	}
	ll ans = 0;
	vector<ll>w(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		cin >> w[i]; w[i] += w[i - 1];
	}
	for (ll i = 1; i <= n; i++) {
		ll l1 = lf[i], l2 = suf[pre[i]];
		ll l = max(l1, l2);
		//cout << pre[i] << " " << suf[i] << endl;
		ans = max(ans, w[i] - w[l - 1]);
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}