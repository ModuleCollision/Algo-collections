#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
struct sq {
	ll u; ll w; ll idx;
};
void solve() {
	ll n; std::cin >> n;
	vector<sq>st(n + 5), st2(n + 5);
	ll mv = inf;
	for (ll i = 1; i <= n; i++) {
		cin >> st[i].u >> st[i].w;
		st2[i] = st[i];
	}
	std::sort(st.begin() + 1, st.begin() + 1 + n, [&](sq x, sq y)->bool{
		return x.u + x.w > y.u + y.w;
	});
	std::sort(st2.begin() + 1, st2.begin() + 1 + n, [&](sq x, sq y)->bool{
		return x.w > y.w;
	});
	auto check = [&](ll x) {
		vector<ll>p, q;
		for (ll i = 1; i <= n; i++)if (st[i].u >= x)p.push_back(st[i].u + st[i].w);
		for (ll i = 1; i <= n; i++)if (st2[i].u < x)q.push_back(st2[i].w);
		if (p.size() < q.size())return false;
		for (ll i = 0; i < q.size(); i++) {
			if (p[i] - q[i] < x)return false;
		}
		return true;
	};
	ll l = 0, r = 1e15, ans = 0;
	while (l < r) {
		ll mid = (l + r + 1) >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}