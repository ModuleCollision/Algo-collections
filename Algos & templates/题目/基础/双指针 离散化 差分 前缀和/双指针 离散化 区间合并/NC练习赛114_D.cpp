#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	std::map<ll, ll>cnt;
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		ll v; std::cin >> v; cnt[v]++;
	}
	for (auto [x, y] : cnt) {
		A[x] = y;
	}
	vector<ll>tr(n + 5, 0);
	auto add = [&](ll idx, ll v) {
		for (; idx <= n; idx += (idx & -idx))tr[idx] += v;
	};
	auto query = [&](ll idx) {
		ll ret = 0;
		for (; idx >= 1; idx -= (idx & -idx))ret += tr[idx];
		return ret;
	};
	for (ll i = 1; i <= n; i++) {
		add(i, A[i] - A[i - 1]);
	}
	ll i = 1;
	while (i <= n) {
		ll l = i;
		ll r = i + 5 - 1; if (r > n) {
			puts("NO"); return;
		}
		while (r + 1 <= n and query(r + 1) >= query(r))r++;
		ll d = query(i);
		add(l, -d); add(r + 1, d);
		while (query(i) <= 0 and i <= n) {
			if (query(i) < 0) {
				puts("NO"); return;
			}
			i++;
		}
	}
	puts("YES"); return;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}