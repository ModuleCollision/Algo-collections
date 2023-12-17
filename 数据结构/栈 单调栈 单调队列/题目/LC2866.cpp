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
	long long maximumSumOfHeights(vector<int>& maxHeights) {
		i64 n = maxHeights.size();
		vector<i64>st1(n + 5, 0); i64 hed = 1, tal = 0;
		vector<i64>st2(n + 5, 0);//双向单调栈
		i64 w = 0;
		vector<i64>pre(n + 1, 0), suf(n + 1, 0);
		for (i64 i = 0; i < n; i++) {
			while (hed <= tal and maxHeights[st1[tal]] >= maxHeights[i]) {
				i64 cur = st1[tal];
				tal--;
				i64 f = hed <= tal ? st1[tal] : -1;
				i64 d = cur - f;
				w -= d * maxHeights[cur];
			}
			i64 f = hed <= tal ? st1[tal] : -1;
			i64 d = i - f; w += d * maxHeights[i]; st1[++tal] = i;
			pre[i] = w;
		}
		w = 0; hed = 1, tal = 0;
		for (i64 i = n - 1; i >= 0; i--) {
			while (hed <= tal and maxHeights[st2[tal]] >= maxHeights[i]) {
				i64 cur = st2[tal];
				tal--;
				i64 f = hed <= tal ? st2[tal] : n;
				i64 d = f - cur;
				w -= d * maxHeights[cur];
			}
			i64 f = hed <= tal ? st2[tal] : n;
			i64 d = f - i; w += d * maxHeights[i]; st2[++tal] = i;
			suf[i] = w;
		}
		long long ans = 0;
		for (i64 i = 0; i <= n - 1; i++) {
			ans = max(ans, (long long)((long long)pre[i] + (long long)suf[i] - maxHeights[i]));
		}
		return ans;
	}
};