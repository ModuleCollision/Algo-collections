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
	
	int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
		int n = nums1.size();
		vector dp(n + 5, vector<i64>(n + 5, 0));
		vector<pair<int, int>>w;
		for (int i = 0; i < n; i++)w.push_back({nums1[i], nums2[i]});
		std::sort(w.begin(), w.end(), [&](pair<int, int>f, pair<int, int>t)->bool{
			return f.second < t.second;
		});
		for (int i = 0; i < n; i++) {
			nums1[i] = w[i].first;
			nums2[i] = w[i].second;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				if (j >= 1)dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums1[i - 1] + nums2[i - 1] * j);
			}
		}
		int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
		int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
		for (int j = 0; j <= n; j++) {
			if (sum1 + sum2 * j - dp[n][j] <= x)return j;
		}
		return -1;
	}
};