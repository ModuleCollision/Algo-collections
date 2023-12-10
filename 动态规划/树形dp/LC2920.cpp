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
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int K) {
        i64 n = coins.size();
        vector<vector<int>>g(n + 1);
        for (auto e : edges) {
            g[e[0] + 1].push_back(e[1] + 1);
            g[e[1] + 1].push_back(e[0] + 1);
        }
        vector dp(n + 1, vector(25, array<i64, 2> { -inf , -inf}));
        function<void(i64, i64)>dfs = [&](i64 u, i64 fa) {
            i64 now = coins[u - 1];
            for (i64 j = 0; j < 20; j++) {
                dp[u][j][0] = now - K;
                if (j > 0)dp[u][j][1] = now;
                now >>= 1;
            }
            for (auto v : g[u]) {
                if (v == fa)continue;
                dfs(v, u);
                for (i64 j = 0; j < 19; j++) {
                    i64 f = max(dp[v][j][0], dp[v][min(19ll, j + 1)][1]);
                    dp[u][j][0] += f;
                    dp[u][j][1] += f;
                }
            }
        };
        dfs(1, 0);
        i64 ans = 0;
        for (i64 j = 0; j < 20; j++)ans = max({ans, dp[1][j][0], dp[1][j][1]});
        return ans;
    }
};

