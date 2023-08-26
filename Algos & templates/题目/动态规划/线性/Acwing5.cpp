#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N, V;
ll v[maxn], w[maxn], s[maxn];
ll x[maxn], y[maxn];
ll dp[maxn], cnt = 0;
void solve() {
	std::cin >> N >> V;
	for (ll i = 1; i <= N; i++) {
		std::cin >> v[i] >> w[i] >> s[i];
	}
	for (ll i = 1; i <= N; i++) {
		for (ll j = 1;; j <<= 1) {
			if (s[i] < j)break;
			s[i] -= j; ++cnt;
			x[cnt] += j * v[i];
			y[cnt] += j * w[i];
		}
		if (s[i]) {
			++cnt; x[cnt] += s[i] * v[i];
			y[cnt] += s[i] * w[i];
		}
		s[i] = 0;
	}
	for (ll i = 1; i <= cnt; i++) {
		for (ll j = V; j >= x[i]; j--) {

			dp[j] = max(dp[j], dp[j - x[i]] + y[i]);
		}
	}
	cout << dp[V] << endl;
}
signed main() {
	solve();
}