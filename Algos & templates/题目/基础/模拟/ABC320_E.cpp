#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct cmp {
	bool operator()(const pair<ll, ll>&x, const pair<ll, ll>&y)const {
		return x.se < y.se;
	}
};
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<ll>T(m + 1), W(m + 1), S(m + 1);
	for (ll i = 1; i <= m; i++) {
		cin >> T[i] >> W[i] >> S[i];
	}
	std::multiset<ll>st; std::multiset<pair<ll, ll>, cmp>st2;
	for (ll i = 1; i <= n; i++)st.insert(i);
	vector<ll>ans(n + 1);
	for (ll i = 1; i <= m; i++) {
		while (st2.size() and st2.begin()->se <= T[i]) {
			st.insert(st2.begin()->fi);
			st2.erase(st2.begin());
		}
		if (not st.size())continue;
		auto idx = *st.begin(); st.erase(st.begin());
		ans[idx] += W[i]; st2.insert({idx, T[i] + S[i]});
	}
	for (ll i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
}
signed main() {
	solve();
}