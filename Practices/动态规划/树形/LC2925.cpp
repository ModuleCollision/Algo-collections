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
using namespace std;
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
class Solution {
public:
	long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
		i64 n = values.size();
		vector<vector<i64>>g(n + 1);
		for (auto w : edges) {
			g[w[0] + 1].push_back(w[1] + 1);
			g[w[1] + 1].push_back(w[0] + 1);
		}
		vector<i64>sz(n + 5);
		vector<i64>dp(n + 5, 0);
		auto dfs = [&](auto self, i64 u, i64 f)->void{
			sz[u] = values[u - 1];
			if (u != 1 and g[u].size() == 1) {//叶子节点
				dp[u] = 0; return;
			}
			i64 tmp = values[u - 1];
			for (auto v : g[u]) {
				if (v == f)continue;
				self(self, v, u);
				sz[u] += sz[v];
				tmp += dp[v];
			}
			dp[u] = max(tmp, sz[u] - values[u - 1]);
			return;
		};
		dfs(dfs, 1, 0);
		return dp[1];
	}
};