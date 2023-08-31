#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll d1[maxn], d2[maxn];
void solve() {
	ll x, y; std::cin >> x >> y;
	ll tx = 0, ty = 0;
	ll n; std::cin >> n;
	string s; std::cin >> s; ll k = s.size(); s = " " + s;
	if (not x and not y) {
		puts("Yes"); return;
	}
	for (ll i = 1; i <= k; i++) {
		if (s[i] == 'U')ty++;
		else if (s[i] == 'D')ty--;
		else if (s[i] == 'R')tx++;
		else tx--;
		if (tx == x and ty == y) {
			puts("Yes"); return;
		}
	}
	if (not tx and not ty) {
		puts("No"); return;
	}
	ll xx = 0, yy = 0;
	for (ll i = 1; i <= k; i++) {
		if (s[i] == 'U')yy++;
		else if (s[i] == 'D')yy--;
		else if (s[i] == 'R')xx++;
		else xx--;
		ll dx = x - xx; ll dy = y - yy;
		if (dx and (not tx or dx % tx)) {
			continue;
		}
		if (dy and (not ty or dy % ty))continue;
		ll wx = tx ? dx / tx : 0;
		ll wy = ty ? dy / ty : 0;
		if (not wx or not wy or (wx == wy) and wx >= 0 and wx < n and wy >= 0 and wy < n) {
			puts("Yes"); return;
		}
	}
	puts("No");
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}