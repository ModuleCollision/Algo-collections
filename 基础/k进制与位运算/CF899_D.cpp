#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e7 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 1, 0); vector<ll>pre(n + 1, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	for (ll i = 1; i <= n; i++) {
		pre[i] = A[i] ^ pre[i - 1];
	}
	ll ans = 0;
	for (ll i = 0; i <= 33; i++) {
		vector<ll>cnt(2, 0); vector<ll>p(2, 0);
		for (ll j = 0; j <= n; j++) {
			ll cur = ((pre[j] >> i) & 1);
			ll d = cnt[cur ^ 1] % mod * j % mod;
			d = ((d - p[cur ^ 1]) % mod + mod) % mod;
			ans = (ans % mod + d % mod * (1ll << i)) % mod;
			cnt[cur]++; p[cur] += j;
		}
	}
	cout << ans % mod << endl;
}
signed main() {
	solve();
}