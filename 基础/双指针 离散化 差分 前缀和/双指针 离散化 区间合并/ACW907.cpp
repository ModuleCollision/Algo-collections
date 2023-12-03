#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
void solve() {
	ll s, t; std::cin >> s >> t;
	ll n; std::cin >> n;
	vector<pair<ll, ll>>k(n + 5);
	for (ll i = 1; i <= n; i++)cin >> k[i].first >> k[i].second;
	std::sort(k.begin() + 1, k.begin() + 1 + n, [&](pair<ll, ll>x, pair<ll, ll>y)->bool{
		if (x.first != y.first)return x.first < y.first;
		return x.second < y.second;
	});
	bool f = 0;
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll j = i; ll r = -inf;
		while (j <= n and k[j].first <= s)r = max(r, k[j].second), j++;
		j--;
		if (r < s) {
			f = 0; break;
		}
		ans++;
		if (r >= t) {
			f = 1;
			break;
		}
		i = j; s = r;
	}
	if (not f) {
		puts("-1");
	} else {
		cout << ans << endl;
	}
}
signed main() {
	solve();
}