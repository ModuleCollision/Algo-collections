/*双指针维护一个定值*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll v; ll col; ll lr; ll idx;
};
struct cmp {
	bool operator()(const pair<ll, ll>&x, const pair<ll, ll>&y)const {
		return x.first < y.first;
	}
};
void solve() {
	ll n; std::cin >> n; vector<ll>a(n + 5), b(n + 5);
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp>q1, q2;
	for (ll i = 1; i <= n; i++)cin >> a[i];
	for (ll i = 1; i <= n; i++)cin >> b[i];
	ll ans = 0;
	vector<bool>exp(n + 5, false);
	vector<ll>col(n + 1); vector<sq>p;
	for (ll i = 1; i <= n; i++) {
		ans += abs(a[i] - b[i]);
		if (a[i] > b[i]) {
			col[i] = 1;
			p.push_back({b[i], col[i], 1, i});
			p.push_back({a[i], col[i], 2, i});
		} else {
			col[i] = 2;
			p.push_back({a[i], col[i], 1, i});
			p.push_back({b[i], col[i], 2, i});
		}
	}
	std::sort(p.begin(), p.end(), [&](sq x, sq y) {
		return x.v < y.v;
	});
	ll mx = 0;
	for (auto it : p) {
		if (it.col == 2 and it.lr == 1) {
			q1.push({b[it.idx], it.idx});
			while (q2.size() and exp[q2.top().second])q2.pop();
			if (q2.size()) {
				mx = max(mx, min(b[it.idx], q2.top().first) - a[it.idx]);
			}
		}
		else if (it.col == 2 and it.lr == 2) {
			exp[it.idx] = 1;
		}
		else if (it.col == 1) {
			if (it.lr == 1) {
				q2.push({a[it.idx], it.idx});
				while (q1.size() and exp[q1.top().second])q1.pop();
				if (q1.size()) {
					mx = max(mx, min(a[it.idx], q1.top().first) - b[it.idx]);
				}
			} else {
				exp[it.idx] = 1;
			}
		}
	}
	cout << ans - mx * 2 << endl;
}
signed main() {
	solve();
}
