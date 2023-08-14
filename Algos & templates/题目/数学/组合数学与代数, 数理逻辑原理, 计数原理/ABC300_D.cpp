#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll p[maxn]; bool vis[maxn];
ll cnt = 0;
void solve() {
	auto init = [&]() {
		for (ll i = 2; i <= 1e6; i++) {
			if (not vis[i]) {
				p[++cnt] = i;
			}
			for (ll j = 1; j <= cnt and i * p[j] <= 1e6; j++) {
				vis[p[j]*i] = 1;
				if (i % p[j] == 0)break;
			}
		}
	};
	init();
	ll N, ans = 0; std::cin >> N;
	for (ll i = 1; i <= cnt; i++) {
		if (p[i]*p[i]*p[i + 1]*p[i + 2]*p[i + 2] > N)break;
		for (ll j = i + 1; j <= cnt; j++) {
			if (p[i]*p[i]*p[j]*p[j + 1]*p[j + 1] > N)break;
			for (ll k = j + 1; k <= cnt; k++) {
				if (p[i]*p[i]*p[j]*p[k]*p[k] > N)break;
				if (p[i]*p[i]*p[j]*p[k]*p[k] <= N) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}