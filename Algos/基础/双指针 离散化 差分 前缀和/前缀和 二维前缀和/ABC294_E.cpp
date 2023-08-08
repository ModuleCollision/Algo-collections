/*前缀和*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll L, N1, N2;
	std::cin >> L >> N1 >> N2;
	vector<ll>v1(N1 + 5, 0), v2(N2 + 5, 0);
	ll l;
	vector<pair<ll, ll>>p1(N1 + 5), p2(N2 + 5);
	ll pre = 0;
	for (ll i = 1; i <= N1; i++) {
		std::cin >> v1[i] >> l;
		p1[i] = {pre + 1, pre + l};
		pre += l;
	}
	pre = 0;
	for (ll i = 1; i <= N2; i++) {
		std::cin >> v2[i] >> l;
		p2[i] = {pre + 1, pre + l};
		pre += l;
	}
	ll sp = 1, fp = 1, ans = 0;
	while (sp <= N1 and fp <= N2) {
		if (p1[sp].second < p2[fp].second) {
			if (v1[sp] == v2[fp]) {
				ans += min(p1[sp].second, p2[fp].second) - max(p1[sp].first, p2[fp].first) + 1;
			}
			sp++;
		} else if (p1[sp].second > p2[fp].second) {
			if (v1[sp] == v2[fp]) {
				ans += min(p1[sp].second, p2[fp].second) - max(p1[sp].first, p2[fp].first) + 1;
			}
			fp++;
		} else {
			if (v1[sp] == v2[fp]) {
				ans += min(p1[sp].second, p2[fp].second) - max(p1[sp].first, p2[fp].first) + 1;
			}
			sp++; fp++;
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}