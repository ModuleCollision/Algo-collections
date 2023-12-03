#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
const ll p = 13331;
void solve() {
	ll n, m, k; std::cin >> n >> m >> k;
	string s; std::cin >> s; s = " " + s;
	vector<ll>Hash(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		Hash[i] = Hash[i - 1] * p  + s[i];
	}
	auto ksm = [&](ll x, ll y) {
		ll ret = 1;
		while (y) {
			if (y & 1)ret = ret * x;
			x = x * x;
			y >>= 1;
		}
		return ret;
	};
	auto get = [&](ll l, ll r) {
		return (Hash[r] - Hash[l - 1] * ksm(p, r - l + 1));
	};
	std::map<ll, ll>cnt, pre;
	for (ll i = 1; i <= n - m + 1; i++) {
		ull cur = get(i, i + m - 1);
		if (not pre.count(cur) or pre[cur] < i - m + 1) {
			pre[cur] = i; cnt[cur]++;
		}
	}
	ll ret = 0;
	for (auto [x, y] : cnt) {
		if (y == k)ret++;
	}
	cout << ret << endl;
}
signed main() {
	solve();
}