

/*采用记忆化搜索来写*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
ll N, M;
void solve() {
	std::cin >> N >> M;
	vector<ll>A(N + 5, 0);
	for (ll i = 1; i <= N; i++)std::cin >> A[i];
	std::map<array<ll, 3>, ll>dp;
	function<ll(ll, ll, ll)>dfs = [&](ll i, ll j, ll k) {
		if (i == 0) {
			if (j == 0 and k == 1) {
				return dp[ {i, j, k}] = 0;
			} else {
				return dp[ {i, j, k}] = inf;
			}
		}//将无法向下搜索的点全部初始化(i == 0 时)
		if (dp.count({i, j, k}))return dp[ {i, j, k}];
		dp[ {i, j, k}] = inf;
		if (k == 0) {
			ll v1 = dfs(i - 1, j, 1);
			ll v2 = dfs(i - 1, j, 0);
			dp[ {i, j, k}] = min(v1 + 1, v2);
		} else {

			if (j >= A[i]) {
				dp[ {i, j, k}] = min(dp[ {i, j, k}], dfs(i - 1, j - A[i], 1));
				dp[ {i, j, k}] = min(dp[ {i, j, k}], dfs(i - 1, j - A[i], 0));
			}
		}
		return dp[ {i, j, k}];
	};
	for (ll j = 1; j <= M; j++) {
		if (dfs(N, j, 0) == inf and dfs(N, j, 1) == inf) {
			puts("-1");
		} else {
			cout << min(dfs(N, j, 0), dfs(N, j, 1)) << endl;
		}
	}
}
signed main() {
	solve();
}