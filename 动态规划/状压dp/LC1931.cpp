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
	int colorTheGrid(int m, int n) {
		int tot = 0;
		vector<vector<int>>f(66);
		vector<int>t(m + 5);
		function<void(int)>dfs = [&](int idx) {
			if (idx == m + 1) {
				f[++tot] = t;
				return;
			}
			for (int i = 1; i <= 3; i++) {
				if (i != t[idx - 1]) {
					t[idx] = i;
					dfs(idx + 1);
				}
			}
		};
		dfs(1);
		vector dp(n + 5, vector<i64>(tot + 5, 0));
		for (int i = 1; i <= tot; i++)dp[1][i] = 1;
		auto check = [&](int i, int j) {
			for (int k = 1; k <= m; k++) {
				if (f[i][k] == f[j][k])return false;
			}
			return true;
		};
		for (int i = 2; i <= n; i++) {
			for (int k = 1; k <= tot; k++) {
				for (int s = 1; s <= tot; s++) {
					if (check(s, k))dp[i][k] = (dp[i][k] % mod + dp[i - 1][s]) % mod;
				}
			}
		}
		i64 ans = 0;
		for (i64 i = 1; i <= tot; i++)ans = (ans % mod + dp[n][i]) % mod;
		return ans;
	}
};