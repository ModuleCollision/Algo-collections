#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<pair<ll, ll>>w(n + 5);
	for (ll i = 1; i <= n; i++)cin >> w[i].first >> w[i].second;
	std::sort(w.begin() + 1, w.begin() + 1 + n, [&](pair<ll, ll> s, pair<ll, ll> t)->bool{
		if (s.first != t.first)return s.first < t.first;
		if (s.second != t.second)return s.second < t.second;
	});
	ll cnt = 1;
	ll Maxr = w[1].second;
	for (ll i = 2; i <= n; i++) {
		if (w[i].first <= Maxr) {
			Maxr = max(Maxr, w[i].second);
		} else {
			cnt++;
			Maxr = w[i].second;
		}
	}
	cout << cnt << endl;
}
signed main() {
	solve();
}