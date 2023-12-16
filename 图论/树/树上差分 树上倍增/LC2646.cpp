#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


/*首先统计每个点会被访问多少次,我们用LCA + 回溯解决*/
class Solution {
public:
	int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
		int  k = trips.size();
		vector<int>lca(k + 5, 0); vector<int>ff(n + 5, 0), fa(n + 5, 0);
		vector<bool>vis(n + 5, false);
		vector<int>tr[n + 5];
		for (auto t : edges) {
			int x = t[0], y = t[1];
			tr[x].push_back(y);
			tr[y].push_back(x);
		}
		vector<pair<int, int>>q[n + 5];
		for (int i = 0; i < k; i++) {
			int a = trips[i][0], b = trips[i][1];
			q[a].push_back({b, i});
			q[b].push_back({a, i});
		}
		auto find = [&](int x) {
			while (x != fa[x]) {
				x = fa[x] = fa[fa[x]];
			}
			return x;
		};
		function<void(int, int)>tarjan = [&](int u, int f) {
			ff[u] = f; fa[u] = u; vis[u] = true;
			for (auto v : tr[u]) {
				if (v == f)continue;
				tarjan(v, u);
				fa[v] = u;
			}
			for (auto [v, idx] : q[u]) {
				if (vis[v]) {
					auto LCA = find(v);
					lca[idx] = LCA;
				}
			}
		};
		tarjan(1, 1);
		vector<int>cnt(n + 5, 0);
		for (int i = 0; i < k; i++) {
			int a = trips[i][0], b = trips[i][1];
			int p = lca[i];
			while (a != p) {
				cnt[a]++; a = ff[a];
			}
			while (b != p) {
				cnt[b]++; b = ff[b];
			}
			cnt[p]++;
		}
		int dp[n + 5][2];
		memset(dp, 0, sizeof(dp));
		function<void(int, int)>dfs = [&](int u, int f) {
			dp[u][0] = price[u] / 2 * cnt[u];
			dp[u][1] = price[u] * cnt[u];
			for (auto v : tr[u]) {
				if (v == f)continue;
				dfs(v, u);
				dp[u][0]  += dp[v][1];
				dp[u][1] += min(dp[v][0], dp[v][1]);
			}
		};
		dfs(1, 1);
		return min(dp[1][0], dp[1][1]);
	}
};
/*引入树上差分解决*/
class Solution {
public:
	int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
		int  k = trips.size();
		vector<int>lca(k + 5, 0); vector<int>ff(n + 5, 0), fa(n + 5, 0);
		vector<bool>vis(n + 5, false);
		vector<int>tr[n + 5];
		for (auto t : edges) {
			int x = t[0], y = t[1];
			tr[x].push_back(y);
			tr[y].push_back(x);
		}
		vector<pair<int, int>>q[n + 5];
		for (int i = 0; i < k; i++) {
			int a = trips[i][0], b = trips[i][1];
			q[a].push_back({b, i});
			q[b].push_back({a, i});
		}
		auto find = [&](int x) {
			while (x != fa[x]) {
				x = fa[x] = fa[fa[x]];
			}
			return x;
		};
		function<void(int, int)>tarjan = [&](int u, int f) {
			ff[u] = f; fa[u] = u; vis[u] = true;
			for (auto v : tr[u]) {
				if (v == f)continue;
				tarjan(v, u);
				fa[v] = u;
			}
			for (auto [v, idx] : q[u]) {
				if (vis[v]) {
					auto LCA = find(v);
					lca[idx] = LCA;
				}
			}
		};
		tarjan(1, 0);
		vector<int>d(n + 5, 0);
		for (int i = 0; i < k; i++) {
			int a = trips[i][0], b = trips[i][1];
			int p = lca[i];
			int f = ff[p];
			d[a]++; d[b]++;
			d[p]--; d[f]--;
		}
		function<void(int, int)>sr = [&](int u, int f) {
			for (auto v : tr[u]) {
				if (v == f)continue;
				sr(v, u);
				d[u] += d[v];
			}
		};
		sr(1, 1);
		int dp[n + 5][2];
		memset(dp, 0, sizeof(dp));
		function<void(int, int)>dfs = [&](int u, int f) {
			dp[u][0] = price[u] / 2 * d[u];
			dp[u][1] = price[u] * d[u];
			for (auto v : tr[u]) {
				if (v == f)continue;
				dfs(v, u);
				dp[u][0]  += dp[v][1];
				dp[u][1] += min(dp[v][0], dp[v][1]);
			}
		};
		dfs(1, 1);
		return min(dp[1][0], dp[1][1]);
	}
};