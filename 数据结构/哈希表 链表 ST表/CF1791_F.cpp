/*对于任何区间操作 + 单点删除 + 单点查询的题目*/
/*都可以使用set 套链表解决*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll n;
struct sq {
	ll pre; ll nxt; ll v;
} tr[maxn];
void solve() {
	ll q;
	std::cin >> n >> q; vector<ll>A(n + 5, 0);
	std::set<ll>st;
	auto cal = [&](ll x) {
		ll ret = 0;
		while (x) {
			ret += x % 10;
			x /= 10;
		}
		return ret;
	};
	for (ll i = 1; i <= n; i++) {
		std::cin >> A[i]; st.insert(i);
		tr[i].pre = i - 1;
		tr[i].nxt = i + 1;
	}
	auto del = [&](ll i) {
		st.erase(i);
		tr[tr[i].nxt].pre = tr[i].pre;
		tr[tr[i].pre].nxt = tr[i].nxt;
	};
	while (q--) {
		ll o; std::cin >> o;
		if (o == 1) {
			ll l, r; std::cin >> l >> r;
			ll e = *st.lower_bound(l);
			for (ll j = e; j <= r and j; j = tr[j].nxt) {
				A[j] = cal(A[j]);
				if (cal(A[j]) == A[j]) {
					del(j);
				}
			}
		} else {
			ll udx; std::cin >> udx; cout << A[udx] << endl;
		}
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}