#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll tr[maxn][3]; ll tot = 0;
void insert(ll s) {
	ll u = 0;
	for (ll i = 31; i >= 0; i--) {
		ll cur = ((s >> i) & 1);
		if (not tr[u][cur])tr[u][cur] = ++tot;
		u = tr[u][cur];
	}
}
ll ans = 0;
void dfs(ll s) {
	ll u = 0;
	ll res = 0;
	for (ll i = 31; i >= 0; i--) {
		ll cur = ((s >> i) & 1);
		if (i == 31) {
			if (tr[u][cur])u = tr[u][cur];
			else u = tr[u][cur ^ 1], res |= (1 << i);
		} else {
			if (tr[u][cur ^ 1])u = tr[u][cur ^ 1], res |= (1 << i);
			else u = tr[u][cur];
		}
	}
	ans = max(res, ans);
}
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0);
	insert(0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	dfs(0);
	for (ll i = 1; i <= n; i++) {
		A[i] ^= A[i - 1];
		dfs(A[i]);
		insert(A[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}