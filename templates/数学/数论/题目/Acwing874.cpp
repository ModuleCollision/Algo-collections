#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll prime[maxn], e[maxn];
bool vis[maxn]; ll cnt = 0;
void solve() {
	ll n; std::cin >> n;
	e[1] = 1; ll ans = 0; ans += e[1];
	for (ll i = 2; i <= maxn; i++) {
		if (not vis[i]) {
			e[i] = i - 1; prime[++cnt] = i;
		}
		if (i <= n)
			ans += e[i];
		for (ll j = 1; j <= cnt and i * prime[j] <= maxn; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j]) {
				e[i * prime[j]] = e[prime[j]] * e[i];
			} else {
				e[i * prime[j]] = e[i] * prime[j];
				break;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
