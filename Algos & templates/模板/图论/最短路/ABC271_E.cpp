#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N, M, K;
struct sq {
	ll a, b, c;
};
void solve() {
	std::cin >> N >> M >> K;
	vector<ll>dp(N + 5, inf);
	dp[1] = 0;
	vector<sq>q(M + 5);
	for (ll i = 1; i <= M; i++) {
		std::cin >> q[i].a >> q[i].b >> q[i].c;
	}
	for (ll i = 1; i <= K; i++) {
		ll x; std::cin >> x;
		if (dp[q[x].b] > dp[q[x].a] + q[x].c) {
			dp[q[x].b] = dp[q[x].a] + q[x].c;
		}
	}
	if (dp[N] == inf) {
		puts("-1");
	} else {
		cout << dp[N] << endl;
	}
}
signed main() {
	solve();
}