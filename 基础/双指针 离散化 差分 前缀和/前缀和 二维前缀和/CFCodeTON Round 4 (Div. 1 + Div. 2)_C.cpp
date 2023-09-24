#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, c, d; std::cin >> n >> c >> d;
	vector<ll>A(n + 5, 0); std::set<ll>st;
	ll p = 0;
	for (ll i = 1; i <= n; i++) {
		std::cin >> A[i]; if (st.count(A[i]))p += c;
		else st.insert(A[i]);
	}
	vector<ll>k(n + 5, 0); ll tot = 0;
	for (auto c : st) {
		k[++tot] = c;
	}
	ll ans = inf;
	for (ll i = 1; i <= tot; i++) {
		ans = min(ans, (k[i] - i) * d + (tot - i) * c);
	}
	ans = min(ans, tot * c + d);
	cout << ans + p << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}