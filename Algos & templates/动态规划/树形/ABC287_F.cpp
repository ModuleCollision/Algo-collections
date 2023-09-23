#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N, a, b;
ll sz[maxn];
ll dp[maxn][maxn][2];//i子树j个联通分量,i节点选不选的方案数
vector<ll>tr[maxn];
void solve() {
	std::cin >> N;
	for (ll i = 1; i <= N - 1; i++) {
		std::cin >> a >> b;
		tr[a].push_back(b);
		tr[b].push_back(a);
	}
	function<void(ll, ll)>dfs = [&](ll u, ll f) {
		dp[u][1][1] = dp[u][0][0] = 1;
		sz[u] = 1;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			vector<ll>tmp1(sz[u] + sz[v] + 5, 0), tmp2(sz[u] + sz[v] + 5, 0);
			for (ll j = 0; j <= sz[u]; j++) {
				for (ll k = 0; k <= sz[v]; k++) {
					tmp1[j + k] = (tmp1[j + k] % mod + dp[u][j][1] % mod * dp[v][k][0] % mod);
					if (j + k) {
						tmp1[j + k - 1] = (tmp1[j + k - 1] % mod + dp[u][j][1] % mod * dp[v][k][1]) % mod;
					}
					tmp2[j + k] = (tmp2[j + k] % mod + dp[u][j][0] % mod * dp[v][k][1]) % mod;
					tmp2[j + k] = (tmp2[j + k] % mod + dp[u][j][0] % mod * dp[v][k][0]) % mod;
				}
			}
			for (ll i = 0; i <= sz[u] + sz[v]; i++) {
				dp[u][i][1] = tmp1[i];
				dp[u][i][0] = tmp2[i];
			}
			sz[u] += sz[v];
		}
	};
	dfs(1, 1);
	for (ll i = 1; i <= N; i++) {
		cout << (dp[1][i][0] % mod + dp[1][i][1]) % mod << endl;
	}
}
signed main() {
	solve();
}