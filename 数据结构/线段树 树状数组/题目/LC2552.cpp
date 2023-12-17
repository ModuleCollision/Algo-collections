/*以后碰到类似统计数对的题目优先考虑树状数组,其次是预处理*/
#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed i64;
using u64 = unsigned i64;
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

	struct fenwicktree {
		int tr[40010];
		int lowbit(int x) {
			return x & -x;
		}
		void add(int i, int val) {
			for (; i <= 40005; i += lowbit(i)) {
				tr[i] += val;
			}
		}
		int query(int i) {
			int ret = 0;
			for (; i > 0; i -= lowbit(i)) {
				ret += tr[i];
			}
			return ret;
		}
		void clear() {
			memset(tr, 0, sizeof(tr));
		}
	} tr1, tr2;
	i64 countQuadruplets(vector<int>& nums) {
		int n = (int)nums.size(); ll ans = 0;
		for (int j = 0; j < n; j++) {
			tr2.clear();
			for (int k = n - 1; k > j; k--) {
				if (nums[k] < nums[j]) {
					int q1 = tr1.query(nums[k] - 1);
					int q2 = tr2.query(40005) - tr2.query(nums[j]);
					ans += (ll)q1 * (ll)q2;
				}
				tr2.add(nums[k], 1);
			}
			tr1.add(nums[j], 1);
		}
		return (i64)ans;
	}
};