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
ll tr[4 * maxn][2]; ll tot = 0; ll  cnt[maxn];
void insert(ll x) {
	ll u = 0;
	for (ll i = 29; i >= 0; i--) {
		ll cur = (x >> i) & 1;
		cnt[u]++;
		if (not tr[u][cur])tr[u][cur] = ++tot;
		u = tr[u][cur];
	}
	cnt[u]++;
}
ll ans = 0;
void dfs2(ll x, ll k) {
	if (tr[x][0] and tr[x][1]) {
		ll i = k + 1;
		ll f1 = (i + 1) - (i % 2 == 1);
		ll f2 = i + (i % 2 == 1);
		ans = (ans % mod + (f1 + f2) % mod * cnt[tr[x][0]] % mod * cnt[tr[x][1]]) % mod;
	}
	if (not tr[x][0] and not tr[x][1]) {
		ll i = k + 1;
		ans = (ans % mod + i * cnt[x] % mod * cnt[x] % mod) % mod;
	}
	if (tr[x][0])dfs2(tr[x][0], k);
	if (tr[x][1])dfs2(tr[x][1], k + 1);
}
ll inv(ll x) {
	ll b = mod - 2; ll ret = 1;
	while (b) {
		if (b & 1)ret = ret * x % mod;
		x = x * x % mod;
		b >>= 1;
	}
	return ret;
}
void solve() {
	memset(tr, 0, sizeof(tr)); memset(cnt, 0, sizeof(cnt));
	tot = 0; ans = 0;
	ll n; std::cin >> n;
	for (ll i = 1; i <= n; i++) {
		ll x; std::cin >> x; insert(x);
	}
	dfs2(0, 0);
	cout << ans *inv(n) % mod*inv(n) % mod << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}