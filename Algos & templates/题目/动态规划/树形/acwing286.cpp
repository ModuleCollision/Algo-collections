#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
vector<ll>tr[maxn];
ll N, M;
ll dp[maxn][maxn], w[maxn]; //以u为根的子树选择j个的总个数
/*树形dp可以转化为背包或者组合数问题求解*/
/*往这两方面考虑*/
void solve() {
	std::cin >> N >> M;
	for (ll i = 1; i <= N; i++) {
		ll p; std::cin >> p >> w[i];
		tr[p].push_back(i);
	}
	vector<ll>sz(N + 5, 0);
	function<void(ll)>dfs = [&](ll u) {
		vector<ll>tmp(M + 5, 0);
		for (auto v : tr[u]) {
			dfs(v);//u必选,所以将其拿掉做树形背包
			for (ll i = 0; i <= min(sz[u], M + 1); i++) {
				for (ll j = 0; j <= min(sz[v], M + 1 - i); j++) {
					tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j]);
				}
			}
			for (ll i = 0; i <= M + 1; i++) {
				dp[u][i] = tmp[i];
			}
			sz[u] += sz[v];
		}
		sz[u] += 1;
		for (ll i = M + 1; i >= 1; i--) {
			dp[u][i] = dp[u][i - 1] + w[u];
		}
	};
	dfs(0);
	cout << dp[0][M + 1] << endl;
}
signed main() {
	solve();
}