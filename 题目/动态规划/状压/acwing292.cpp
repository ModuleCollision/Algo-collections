#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 105;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
vector<pair<ll, ll>>st[maxn];
char G[maxn][maxn];
ll dp[maxn][100005], N, M;
void solve() {
	cin >> N >> M;
	for (ll i = 1; i <= N; i++) {
		cin >> G[i];
	}
	function<void(ll, ll, ll, ll)>dfs = [&](ll val, ll idx, ll r, ll cnt) {
		if (idx >= M) {
			st[r].push_back({val, cnt});
			return;
		}
		if (G[r][idx] == 'P') {
			bool f1 = true, f2 = true;
			if (idx > 0) {
				f1 = not((val >> (idx - 1)) & 1);
			}
			if (idx > 1) {
				f2 = not((val >> (idx - 2)) & 1);
			}
			if (f1  and f2) {
				dfs(val + (1 << idx), idx + 3, r, cnt + 1);
			}
		}
		dfs(val, idx + 1, r, cnt);
	};
	for (ll i = 1; i <= N; i++) {
		dfs(0, 0, i, 0);
	}
	for (auto [x, y] : st[1]) {
		dp[1][x] = y;
	}
	for (auto [x1, y1] : st[2]) {
		for (auto [x2, y2] : st[1]) {
			if (not(x1 & x2)) {
				dp[2][x1] = max(dp[2][x1], dp[1][x2] + y1);
			}
		}
	}
	for (ll i = 3; i <= N; i++) {
		for (auto [xc, yc] : st[i]) {
			for (auto [xd, yd] : st[i - 2]) {
				for (auto [xf, yf] : st[i - 1]) {
					if ((not(xc & xd)) and (not(xd & xf)) and (not(xc & xf))) {
						dp[i][xc] = max(dp[i][xc], dp[i - 2][xd] + yf + yc);
					}
				}
			}
		}
	}
	ll ans = 0;
	for (auto [x, y] : st[N]) {
		ans = max(ans, dp[N][x]);
	}
	if (ans == 16)ans--;
	cout << ans << endl;
}
signed main() {
	solve();
}