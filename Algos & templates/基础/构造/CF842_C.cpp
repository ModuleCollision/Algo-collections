#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
//dp i , j表示在前i个数中使用状态为j的最大获得数
void solve() {
	ll n; std::cin >> n;
	vector<pair<ll, ll>>p(n + 5);
	vector<ll>ans1(n + 5), ans2(n + 5);
	vector<bool>vis1(n + 5, 0), vis2(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		cin >> p[i].second; p[i].first = i;
	}
	std::sort(p.begin() + 1, p.begin() + 1 + n, [&](pair<ll, ll>x, pair<ll, ll>y)->bool{
		return x.second > y.second;
	});
	for (ll i = 1; i <= n; i++) {
		if (not vis1[p[i].second]) {
			vis1[p[i].second] = 1;
			ans1[p[i].first] = p[i].second;
		} else if (not vis2[p[i].second]) {
			vis2[p[i].second] = 1;
			ans2[p[i].first] = p[i].second;
		}
	}
	ll r1 = n; ll r2 = n;
	for (ll i = 1; i <= n; i++) {
		if (not ans1[p[i].first]) {
			while (vis1[r1])r1--;
			vis1[r1] = 1;
			if (r1 > ans2[p[i].first]) {
				puts("NO"); return;
			}
			ans1[p[i].first] = r1; r1--;
		} else if (not ans2[p[i].first]) {
			while (vis2[r2])r2--;
			vis2[r2] = 1;
			if (r2 > ans1[p[i].first]) {
				puts("NO"); return;
			}
			ans2[p[i].first] = r2; r2--;
		}
	}
	puts("YES");
	for (ll i = 1; i <= n; i++) {
		cout << ans1[i] << " ";
	}
	cout << endl;
	for (ll i = 1; i <= n; i++) {
		cout << ans2[i] << " ";
	}
	cout << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--) {
		solve();
	}
}