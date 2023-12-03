/*要求实现单点修改的数据结构,每次查询前k大的和*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
/*模拟题的要领 : 选取恰当的数据结构*/
struct cmp {
	bool operator()(const ll&x, const ll&y)const {
		return x < y;
	}
};
void solve() {
	std::multiset<ll, cmp>st1, st2;
	ll n, k, q; std::cin >> n >> k >> q;
	for (ll i = 1; i <= k; i++)st1.insert(0);
	for (ll i = 1; i <= n - k; i++)st2.insert(0);
	vector<ll>A(n + 5, 0); ll ans = 0;
	while (q--) {
		ll x, y;
		std::cin >> x >> y;
		if (st1.count(A[x])) {
			st1.erase(st1.find(A[x]));
			ans -= A[x];
		} else {
			st2.erase(st2.find(A[x]));
		}
		A[x] = y;
		if (st2.size() and (*st2.rbegin()) <= y) {
			st1.insert(y); ans += y;
		} else {
			st2.insert(y);
		}
		while (st1.size() < k) {
			ll tmp = *st2.rbegin();
			st2.erase(st2.find(tmp));
			st1.insert(tmp);
			ans += tmp;
		}
		while (st2.size() < n - k) {
			ll tmp = *st1.begin();
			st1.erase(st1.begin());
			st2.insert(tmp);
			ans -= tmp;
		}
		cout << ans << endl;
	}
}
signed main() {
	solve();
}