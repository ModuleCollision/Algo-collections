#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<pair<ll, ll>>p(n * m + 5);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			ll v; std::cin >> v;
			p[v] = {i, j};
		}
	}
	auto check = [&](ll mid)->bool{
		vector<pair<ll, ll>>tmp;
		for (ll i = 0; i < mid; i++) {
			tmp.push_back(p[i]);
		}
		std::sort(tmp.begin(), tmp.end(), [&](pair<ll, ll>x, pair<ll, ll>y)->bool{
			if (x.first != y.first)return x.first < y.first;
			if (x.second != y.second)return x.second < y.second;
		});
		for (ll i = 1; i < tmp.size(); i++) {
			if (tmp[i].second < tmp[i - 1].second)return false;
		};
		return true;
	};
	ll l = 0, r = n * m;
	while (l < r) {
		ll mid = (l + r + 1) >> 1;
		if (check(mid))l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
}
signed main() {
	ll T; cin >> T;
	while (T--) {
		solve();
	}
}
