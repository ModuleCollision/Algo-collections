/*线段树优化dp*/
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
	struct sq {
		int mx; int l; int r;
	} tr[maxn];
	void pushup(int p) {
		tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
	}
	void update(int p, int idx, int v) {
		if (tr[p].l == tr[p].r) {
			tr[p].mx = max(tr[p].mx, v);
			return;
		}
		int mid = (tr[p].l + tr[p].r) >> 1;
		if (idx > mid)update(p << 1 | 1, idx, v);
		if (idx <= mid)update(p << 1, idx, v);
		pushup(p);
	}
	void build(int p, int l, int r) {
		tr[p].l = l; tr[p].r = r;
		if (l == r) {
			tr[p].mx = 0; return;
		}
		int mid = (l + r) >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
		pushup(p);
	}
	int query(int p, int l, int r) {
		if (tr[p].l >= l and tr[p].r <= r) {
			return tr[p].mx;
		}
		int ret = 0; int mid = (tr[p].l + tr[p].r) >> 1;
		if (r > mid)
			ret = max(ret, query(p << 1 | 1, l, r));
		if (l <= mid)ret = max(ret, query(p << 1, l, r));
		return ret;
	}
	int lengthOfLIS(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int>dp(n + 5, 0);
		std::fill(dp.begin() + 1, dp.begin() + 1 + n, 1);
		build(1, 1, 1e5);
		for (int i = 1; i <= n; i++) {
			if (nums[i - 1] == 1) {
				update(1, nums[i - 1], dp[i]); continue;
			}
			int q = query(1, max(1, nums[i - 1] - k), nums[i - 1] - 1);
			dp[i] = max(dp[i], q + 1);
			update(1, nums[i - 1], dp[i]);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)ans = max(ans, dp[i]);
		return ans;
	}
};