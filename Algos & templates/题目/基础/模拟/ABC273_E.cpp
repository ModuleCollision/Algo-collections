#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll val; ll fa;
} tr[maxn]; ll tot = 0; ll it = 0, x = 0;
std::map<ll, ll>sta; //The page to the state
void init() {
	tr[0].fa = -1;
}
void add(ll x) {
	tr[++tot].fa = it;
	it = tot;
	tr[tot].val = x;
	return;
}
void del() {
	if (not it)return;
	it = tr[it].fa;
	return;
}
void save(ll x) {
	sta[x] = it;
}
void load(ll x) {
	it = sta[x];
}
ll Q; string opt;
void solve() {
	std::cin >> Q; init();
	for (ll i = 1; i <= Q; i++) {
		std::cin >> opt;
		if (opt == "ADD") {
			std::cin >> x; add(x);
		} else if (opt == "DELETE") {
			del();
		} else if (opt == "SAVE") {
			std::cin >> x; save(x);
		} else {
			std::cin >> x; load(x);
		}
		cout << (tr[it].val ? tr[it].val : -1) << " ";
	}
}
signed main() {
	solve();
}
