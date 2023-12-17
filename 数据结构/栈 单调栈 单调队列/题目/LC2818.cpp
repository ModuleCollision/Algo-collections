
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
	int maximumScore(vector<int>& nums, int k) {
		int n = nums.size(); vector<int>p(n + 5, 0); for (int i = 1; i <= n; i++)p[i] = nums[i - 1];
		vector<int>val(n + 5, 0);
		for (int i = 1; i <= n; i++) {
			int cur = p[i];
			for (int j = 2; j <= sqrt(cur); j++) {
				if (cur % j == 0) {
					while (cur % j == 0)cur /= j;
					val[i]++;
				}
			}
			if (cur > 1)val[i]++;
		}

		vector<int>q(4 * n + 5, 0);
		int hed = 1, tal = 0;
		vector<int>rt(n + 1, n + 1);
		vector<int>lt(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			while (hed <= tal and val[q[tal]] < val[i]) {
				rt[q[tal]] = i;
				tal--;
			}
			if (hed <= tal)lt[i] = q[tal];
			q[++tal] = i;
		}
		vector<i64>idx(n + 1);
		iota(idx.begin() + 1, idx.begin() + 1 + n, 1);
		std::sort(idx.begin() + 1, idx.begin() + 1 + n, [&](int x, int y)->bool{
			return p[x] > p[y];
		});
		i64 ans = 1;
		auto ksm = [&](i64 x, i64 y) {
			i64 ret = 1;
			while (y) {
				if (y & 1)ret = ret * x % mod;
				x = x * x % mod;
				y >>= 1;
			}
			return ret % mod;
		};
		for (int i = 1; i <= n; i++) {
			int id = idx[i];
			int tot = (i64)(id - lt[id]) * (rt[id] - id);
			ans = ans % mod * ksm((i64)p[id], (i64)min(k, tot)) % mod;
			k -= min(k, tot);
			if (not k)break;
		}
		return (int)ans % mod;
	}
};