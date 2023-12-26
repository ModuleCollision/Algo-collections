/*小技巧*/
/*我们在处理需要时刻记录全图状态的图论问题时,
不妨利用状态压缩,并进行bfs/dfs过程中的转移*/




/*方法一 在bfs的过程中参与dp*/
struct sq {
	int u; int msk; int dis;
};
class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		queue<sq>q;
		bool vis[100][100005];
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			q.push({i, (1 << i), 0});
			vis[i][1 << i] = true;//访问过只有点i被访问的图的状态
		}
		//vis记录两个状态,在图中某个状态访问至某点的状态
		int ans = 0;
		while (not q.empty()) {
			auto [u, msk, dis] = q.front();
			q.pop();
			if (msk == (1 << n) - 1) {//当全图中的点都被访问过时
				ans = dis; break;
			}
			for (auto v : graph[u]) {
				int cur = msk | (1 << v);
				if (not vis[v][cur]) {
					q.push({v, cur, dis + 1});
					vis[v][cur] = 1;
				}
			}
		}
		return ans;
	}
};


/*方法二 设计状态进行朴素的dp*/
#include<bits/stdc++.h>

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

constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 1e5 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		i64 n = graph.size();
		std::vector dp((1 << n) + 1, std::vector<i64>(n + 1, inf));
		for (i64 i = 0; i < n; i++) {
			dp[(1 << i)][i] = 0;
		}
		std::vector dis(n + 1, std::vector<i64>(n + 1, inf));
		std::vector<i64>d(n + 1, inf);
		auto bfs = [&](i64 x) {
			queue<i64>q; q.push(x);
			std::fill(d.begin(), d.end(), inf); d[x] = 0;
			while (q.size()) {
				auto cur = q.front(); q.pop();
				for (auto v : graph[cur]) {
					if (d[v] != inf)continue;
					d[v] = d[cur] + 1;
					q.push(v);
				}
			}
		};
		for (i64 i = 0; i < n; i++) {
			bfs(i);
			for (i64 j = 0; j < n; j++) {
				dis[i][j] = d[j];
			}
		}
		for (i64 j = 1; j < (1 << n); j++) {
			for (i64 i = 0; i < n; i++) {
				if ((j >> i) & 1) {
					for (i64 k = 0; k < n; k++) {
						if (not((j >> k) & 1)) {
							dp[j | (1 << k)][k] = std::min(dp[j | (1 << k)][k], dp[j][i] + dis[i][k]);
						}
					}
				}
			}
		}
		i64 ans = inf;
		for (i64 i = 0; i < n; i++) {
			ans = std::min(ans, dp[(1 << n) - 1][i]);
		}
		return ans;
	}
};