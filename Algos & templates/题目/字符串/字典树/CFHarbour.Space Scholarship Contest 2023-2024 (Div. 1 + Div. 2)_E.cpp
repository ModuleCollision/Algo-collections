#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll v[2]; ll cnt = 0;
};
vector<sq>tr;
void add(ll x) {
	ll u = 0;
	for (ll i = 29; i >= 0; i--) {
		ll b = (x >> i) & 1;
		if (not tr[u].v[b]) {
			tr[u].v[b] = tr.size();
			tr.push_back(sq());
		}
		u = tr[u].v[b];
	}
	++tr[u].cnt;
}
void dfs1(ll u) {
	for (ll i = 0; i < 2; i++) {
		if (tr[u].v[i]) {
			dfs1(tr[u].v[i]);
			ll v = tr[u].v[i];
			tr[u].cnt += tr[v].cnt;
		}
	}
}
ll ksm(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y & 1)ret = ret * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ret % mod;
}
ll ans = 0;
void dfs2(ll x, ll k) {
	if (tr[x].v[0] and tr[x].v[1]) {
		ll i = k + 1;
		ll f1 = (i + 1) - (i % 2 == 1);
		ll f2 = i + (i % 2 == 1);
		ans = (ans % mod + (f1 + f2) % mod * tr[tr[x].v[0]].cnt % mod * tr[tr[x].v[1]].cnt) % mod;
	}
	if (not tr[x].v[0] and not tr[x].v[1]) {
		ll i = k + 1;
		ans = (ans % mod + i * tr[x].cnt % mod * tr[x].cnt % mod) % mod;
	}
	if (tr[x].v[0])dfs2(tr[x].v[0], k);
	if (tr[x].v[1])dfs2(tr[x].v[1], k + 1);
}
void solve() {
	tr.clear(); tr.push_back(sq());
	ll n; std::cin >> n;
	for (ll i = 1; i <= n; i++) {
		ll x; cin >> x; add(x);
	}
	ans = 0;
	dfs1(0); dfs2(0, 0);
	cout << ans % mod*ksm(n, mod - 2) % mod*ksm(n, mod - 2) % mod << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}