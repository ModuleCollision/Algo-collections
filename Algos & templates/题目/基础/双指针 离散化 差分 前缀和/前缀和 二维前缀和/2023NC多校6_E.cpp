#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, q; std::cin >> n >> q;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	vector<ll>pre(n + 5, 0);
	ll cur = 0; std::set<ll>st;
	vector<ll>cnt(n + 5); vector<ll>idx(n + 5, 0);
	ll tot = 0;
	for (ll i = 1; i <= n; i++) {
		if (A[i] & 1)pre[i] = i, cur = i, st.insert(i), idx[i] = ++tot;
		else pre[i] = cur;
		cnt[i] += cnt[i - 1];
		cnt[i] += (A[i] & 1);
	}
	st.insert(0);
	cur = n + 1; vector<ll>suf(n + 5, 0);
	for (ll i = n; i >= 1; i--) {
		if (A[i] & 1)suf[i] = i, cur = i;
		else suf[i] = cur;
	}
	st.insert(n + 1);
	bool curr = 0;
	vector ct(n + 5, array<ll, 2> {0, 0});
	for (ll i = 1; i <= n; i++) {
		ct[i][0] += ct[i - 1][0];
		ct[i][1] += ct[i - 1][1];
		if (A[i] & 1)curr ^= 1;
		else {

			ct[i][curr] += 1;
		}
	}
	while (q--) {
		ll l, r, k; std::cin >> l >> r >> k;
		ll f = cnt[r] - cnt[l - 1];
		if (r - l + 1 < k) {
			puts("NO"); continue;
		}
		if (not f) {
			puts("YES"); continue;
		}
		if (f & 1) {
			puts("NO"); continue;
		}
		f /= 2;
		auto p1 = st.lower_bound(l);
		ll ws = idx[*p1]; ll pre = 0;
		if (ws & 1) {
			pre = ct[r][0] - ct[l - 1][0];
		} else pre = ct[r][1] - ct[l - 1][1];
		ll high = pre + f;
		if (k > high)puts("NO");
		else puts("YES");
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T --)
		solve();
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, q; std::cin >> n >> q;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	vector<ll>pre1(n + 5, 0), pre2(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		A[i] += A[i - 1];
		pre1[i] += pre1[i - 1];
		pre2[i] += pre2[i - 1];
		if (A[i] & 1)pre2[i]++;
		else pre1[i]++;

	}
	while (q--) {
		ll l, r, k; std::cin >> l >> r >> k;
		ll f = cnt[r] - cnt[l - 1];
		if (A[l - 1] & 1) {
			if (pre2[r] - pre2[l - 1] >= k and (A[r] - A[l - 1]) % 2 == 0) {
				puts("YES");
			} else puts("NO");
		} else {
			if (pre1[r] - pre1[l - 1] >= k and (A[r] - A[l - 1]) % 2 == 0) {
				puts("YES");
			} else puts("NO");
		}
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T --)
		solve();
}