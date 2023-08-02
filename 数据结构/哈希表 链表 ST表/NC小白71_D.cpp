#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll u; ll v; ll idx;
} t1[maxn], t2[maxn]; ll tot = 0;
std::set<ll>p;
void solve() {
	ll n, m;
	std::cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		std::cin >> t1[i].u;
		t1[i].idx = i;
	}
	for (ll i = 1; i <= n; i++) {
		std::cin >> t1[i].v;
	}
	for (ll i = 1; i <= m; i++) {
		std::cin >> t2[i].u;
		t2[i].idx = i;
	}
	for (ll i = 1; i <= m; i++) {
		std::cin >> t2[i].v;
	}
	ll prev = 0;
	std::sort(t1 + 1, t1 + 1 + n, [&](sq a, sq b)->bool{
		return a.u < b.u;
	});
	std::sort(t2 + 1, t2 + 1 + m, [&](sq a, sq b)->bool{
		return a.v < b.v;
	});
	p.clear();
	vector<ll>ans(n + 5, 0);
	for (ll i = 1, j = 1; i <= n; i++) {
		ll val = t1[i].u;
		while (t2[j].v <= val and j <= m) {
			p.insert(t2[j].u);
			j++;
		}
		ll idx = t1[i].idx;
		if (p.size() == 0) {
			ans[idx] = -1; continue;
		}
		auto it = p.end(); it--;
		if (*it >= t1[i].v) {
			ans[idx] = *it;
		} else {
			ans[idx] = -1;
		}
	}
	for (ll i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
}
signed main() {
	solve();
}