#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, k; std::cin >> n >> k; string s; cin >> s; s = " " + s;
	vector pre(n + 5, vector<ll>(n + 5, 0)); vector suf(n + 5, vector<ll>(n + 5, 0));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= n; j++) {
			if (s[i] == '0')
				pre[i][j] = max(pre[i][j], pre[i - 1][j] + 1);
			else if (j >= 1)pre[i][j] = max(pre[i][j], pre[i - 1][j - 1] + 1);
		}
	}
	for (ll i = n; i >= 1; i--) {
		for (ll j = 0; j <= n; j++) {
			if (s[i] == '0')suf[i][j] = max(suf[i][j], suf[i + 1][j] + 1);
			else if (j >= 1)suf[i][j] = max(suf[i][j], suf[i + 1][j - 1] + 1);
		}
	}
	vector<ll>w(n + 5), t(n + 5);
	for (ll i = 1; i <= n; i++) {
		if (s[i] == '0')continue;
		ll l = i; w[i] = l - 1;
		while (i + 1 <= n and s[i + 1] == '1') {
			i++; w[i] = l - 1;
		}
	}
	for (ll i = n; i >= 1; i--) {
		if (s[i] == '0')continue;
		ll l = i; t[i] = l + 1;
		while (i - 1 >= 1 and s[i - 1] == '1') {
			i--; t[i] = l + 1;
		}
	}
	vector<ll>p(n + 5), q(n + 5);
	for (ll i = 1; i <= n; i++) {
		p[i] = max(p[i], p[i - 1]);
		if (s[i] == '1')p[i] = max(p[i], i - w[i]);
	}
	for (ll i = n; i >= 1; i--) {
		q[i] = max(q[i], q[i + 1]);
		if (s[i] == '1')q[i] = max(q[i], t[i] - i);
	}
	ll ans = 0; ll len1 = 0, len2 = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= k; j++) {
			ll v1 = pre[i][j] + suf[i + 1][k - j];
			ll v2 = max(p[i - pre[i][j]], q[i + suf[i][k - j]]);
			if (v1 > len1) {
				len1 = v1, len2 = v2;
			} else if (v1 == len1) {
				if (v2 > len2)len2 = v2;
			} else continue;
		}
	}
	for (ll i = 1; i <= n; i++) {
		cout << len1*i + len2 << " ";
	}
	cout << endl;
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}