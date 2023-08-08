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
	vector<sq>st(n + 5);
	ll mv = inf;
	for (ll i = 1; i <= n; i++) {
		cin >> st[i].u >> st[i].w;
		mv = min(mv, st[i].u);
		st[i].idx = i;
	}
	auto check = [&](ll x) {
		vector<sq>tmp1, tmp2;
		for (ll i = 1; i <= n; i++) {
			if (st[i].u < x)tmp1.push_back(st[i]);
			else tmp2.push_back(st[i]);
		}
		if (tmp2.size() < tmp1.size())return false;
		if (not tmp2.size())return false;
		if (not tmp1.size())return true;
		std::sort(tmp2.begin(), tmp2.end(), [&](sq a, sq b)->bool{
			if (a.u + a.w != b.u + b.w)return a.u + a.w < b.u + b.w;
			if (a.w != b.w)return a.w < b.w;
		});
		ll sz1 = tmp1.size(), sz2 = tmp2.size();
		std::sort(tmp1.begin(), tmp1.end(), [&](sq a, sq b)->bool{
			if (a.w != b.w)return a.w < b.w;
			if (a.u + a.w != b.u + b.w)return a.u + a.w < b.u + b.w;
		});
		for (ll i = sz2 - sz1; i <= sz2 - 1; i++) {
			ll j = i - sz2 + sz1;
			ll c = tmp1[j].w > tmp2[i].w ? tmp1[j].w - tmp2[i].w : 0;
			ll p = tmp2[i].u - c;
			if (p < x)return false;
		}
		return true;
	};
	ll l = mv, r = 1e15, ans = 0;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1; ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}