#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	std::multiset<ll>st;
	vector<array<ll, 3>>A(n + 5);
	vector<map<ll, ll>>vv(2);
	map<ll, std::set<ll>>re;
	for (ll i = 1; i <= n; i++) {
		cin >> A[i][0] >> A[i][1] >> A[i][2];
		vv[0][A[i][0]] += A[i][2];
		re[A[i][0]].insert(A[i][1]);
		vv[1][A[i][1]] += A[i][2];
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ans = max(ans, vv[0][A[i][0]] + vv[1][A[i][1]] - A[i][2]);
	}

	for (auto [r, v] : vv[1]) {
		st.insert(v);
	}
	st.insert(0);
	for (auto [l, v] : vv[0]) {
		for (auto r : re[l]) {
			ll v = vv[1][r];
			if (st.count(v))st.erase(st.find(v));
		}
		ll k = *(--st.end());
		for (auto r : re[l])st.insert(vv[1][r]);
		ans = max(ans, v + k);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}