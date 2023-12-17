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

class Solution {
public:
	int minimizeConcatenatedLength(vector<string>& words) {
		int n = words.size();
		vector dp(n + 1, vector (26, vector<int>(26, inf)));
		int s = words[0].front(), t = words[0].back();
		dp[0][s - 'a'][t - 'a'] = words[0].size();
		for (int i = 1; i < n; i++) {
			int s = words[i].front() - 'a';
			int t = words[i].back() - 'a';
			for (int j = 0; j <= 25; j++) {
				for (int k = 0; k <= 25; k++) {
					dp[i][s][k] = min(dp[i][s][k], dp[i - 1][j][k] + (int)words[i].size() - (t == j));
					dp[i][j][t] = min(dp[i][j][t], dp[i - 1][j][k] + (int)words[i].size() - (k == s));
				}
			}
		}
		int ans = inf;
		for (int i = 0; i <= 25; i++) {
			for (int j = 0; j <= 25; j++)ans = min(ans, dp[n - 1][i][j]);
		}
		return ans;
	}
};