#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n; vector<ll>A(n + 5, 0);
	std::map<ll, ll>cnt;
	for (ll i = 1; i <= n; i++) {
		std::cin >> A[i]; cnt[A[i]]++;
	}
	ll q; std::cin >> q;
	if (n == 1) {
		while (q--) {
			ll i, x; std::cin >> i >> x;
			cout << x << " ";
		}
		cout << endl; return;
	}
	std::multiset<ll>st; ll prev = -1;
	for (auto w = cnt.begin(); w != cnt.end(); w++) {
		if (prev != -1)
			st.insert((w->first) - prev);
		prev = w->first;
	}
	cnt[0]++;
	while (q--) {
		ll i, x; std::cin >> i >> x;
		cnt[A[i]]--;
		if (cnt[A[i]] == 0) {
			auto s = cnt.upper_bound(A[i]);
			auto w = cnt.lower_bound(A[i]); w--;
			if (s != cnt.end())st.erase(st.find((s->first) - A[i]));
			if ((w->first) != 0)st.erase(st.find(A[i] - (w->first)));
			if (s != cnt.end() and (w->first != 0))st.insert((s->first) - (w->first));
			cnt.erase(A[i]);
		}
		A[i] = x; cnt[A[i]]++;
		if (cnt[A[i]] == 1) {
			auto s = cnt.upper_bound(A[i]);
			auto w = cnt.lower_bound(A[i]); w--;
			if (s != cnt.end())st.insert((s->first) - A[i]);
			if ((w->first) != 0)st.insert(A[i] - (w->first));
			if (s != cnt.end() and (w->first != 0))st.erase(st.find((s->first) - (w->first)));
		}
		ll ans = (--cnt.end())->first;
		ll p = *(--st.end());
		cout << ans + p << " ";
	}
	cout << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}