#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e8;
ll N, M, vis[15][15];
ll dp[15][(1 << 12) + 5];//第i行为j状态的合法种数
vector<ll>st[15];//维护每行的合法状态
void solve() {
	cin >> N >> M;
	for (ll i = 1; i <= N; i++) {
		for (ll j = 0; j < M; j++) {
			cin >> vis[i][j];
		}
	}
	function<void(ll, ll, ll)>dfs = [&](ll v, ll idx, ll l) {
		if (idx >= M) {
			st[l].push_back(v);
			return;
		}
		if (vis[l][idx]) {
			dfs(v + (1 << idx), idx + 2, l);
		}
		dfs(v, idx + 1, l);
	};
	for (ll i = 1; i <= N; i++) {
		dfs(0, 0, i);
	}
	for (auto c : st[1]) {
		dp[1][c] = 1;
	}
	ll ans = 0;
	for (ll i = 2; i <= N; i++) {
		for (auto st1 : st[i - 1]) {
			for (auto st2 : st[i]) {
				if (not(st1 & st2)) {
					dp[i][st2] += dp[i - 1][st1] % mod;
				}
			}
		}
	}
	for (auto s : st[N]) {
		ans = (ans % mod + dp[N][s]) % mod;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}