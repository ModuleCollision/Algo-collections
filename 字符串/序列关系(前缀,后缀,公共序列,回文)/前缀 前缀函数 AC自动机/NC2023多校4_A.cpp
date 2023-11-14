#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	bool f1 = 1, f2 = 1;
	ll n; string t; std::cin >> n >> t;
	ll m = t.size();
	vector<ll>p1(2 * m + n + 5); auto p2 = p1;
	std::string tmp1, tmp2;
	for (ll i = 0; i < n; i++)tmp1 += '1';
	for (ll i = 0; i < n; i++)tmp2 += '0';
	tmp1 = t + tmp1 + t;
	tmp2 = t + tmp2 + t;
	ll len = 2 * m + n;
	for (ll i = 1; i < len; i++) {
		ll j = p1[i - 1];
		while (j > 0 and tmp1[i] != tmp1[j]) j = p1[j - 1];
		if (tmp1[i] == tmp1[j])j++;
		p1[i] = j;
	}
	for (ll i = 1; i < len; i++) {
		ll j = p2[i - 1];
		while (j > 0 and tmp2[i] != tmp2[j]) j = p2[j - 1];
		if (tmp2[i] == tmp2[j])j++;
		p2[i] = j;
	}
	for (ll i = 0; i < len; i++) {
		if (p1[i] == m and i != len - 1) {
			f1 = 0; break;
		}
	}
	for (ll i = 0; i < len; i++) {
		if (p2[i] == m and i != len - 1) {
			f2 = 0; break;
		}
	}
	if (f1) {for (ll i = 0; i < n; i++) putchar('1'); cout << endl;}
	else if (f2) {for (ll i = 0; i < n; i++)putchar('0'); cout << endl;}
	else puts("-1");
	return;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}