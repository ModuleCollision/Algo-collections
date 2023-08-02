/*二维差分模板*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	deque<ll>q;
	vector<pair<ll, ll>>s(n + 5);
	vector<ll>w(n + 5);
	for (ll i = 1; i <= n; i++) {
		ll v; std::cin >> v; //q.push_back(v);
		w[i] = v;
		s[i].second = v; s[i].first = i;
	}
	std::sort(s.begin() + 1, s.begin() + 1 + n, [&](pair<ll, ll>x, pair<ll, ll>y)->bool{
		return x.second < y.second;
	});
	//std::sort(q.begin(), q.end());
	std::sort(w.begin() + 1, w.begin() + 1 + n);
	ll l = 1, r = n;
	for (ll i = 1; i <= n - 1; i++) {
		ll d = w[r] - w[l];
		if (d == 0) {
			r--; continue;
		}
		//cout << "#" << d << s[l].first << " " << s[r].first << endl;
		if (d & 1) {
			d /= 2;
			ll k = upper_bound(w.begin() + l, w.begin() + r + 1, w[l] + d) - w.begin() - l;
			ll les = n - i + 1 - k;
			if (k >= les) {
				r--;
			} else {
				l++;;
			}
		} else {
			d /= 2;
			ll k = upper_bound(w.begin(), w.begin() + r + 1, w[l] + d) - w.begin() - l;
			ll les = n - i + 1 - k;
			if (k >= les) {
				r--; //q.pop_back();
			} else {
				l++; //q.pop_front();
			}
		}
	}
	cout << s[l].first << endl;
}
signed main() {
	solve();
}