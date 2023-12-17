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

struct sq {
	int add; int l; int r; int v;
} tr[400005]; int w[100005];
void pushup(int p) {
	tr[p].v = tr[p << 1].v + tr[p << 1 | 1].v;
}
void build(int p, int l, int r) {
	tr[p].l = l; tr[p].r = r; tr[p].add = 0;
	if (l == r) {
		tr[p].v = w[l]; tr[p].add = 0; return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
	pushup(p);
}
void pushdown(int p) {
	if (tr[p].add) {
		tr[p].add = 0;
		tr[p << 1].add ^= 1;
		tr[p << 1 | 1].add ^= 1;
		tr[p << 1].v = (tr[p << 1].r - tr[p << 1].l + 1 - tr[p << 1].v);
		tr[p << 1 | 1].v = (tr[p << 1 | 1].r - tr[p << 1 | 1].l + 1 - tr[p << 1 | 1].v);
	}
}
void modify(int p, int l, int r) {
	if (tr[p].l >= l and tr[p].r <= r) {
		tr[p].add ^= 1; tr[p].v = (tr[p].r - tr[p].l + 1 - tr[p].v);
		return;
	}
	pushdown(p);
	int mid = (tr[p].l + tr[p].r) >> 1;
	if (l <= mid)modify(p << 1, l, r);
	if (r > mid)modify(p << 1 | 1, l, r);
	pushup(p);
}
i64 query() {
	return (i64)tr[1].v;
}
class Solution {
public:
	vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
		i64 tot = 0;
		vector<i64>ans; for (auto c : nums2)tot += c;
		int n = nums1.size();
		for (int i = 0; i < n; i++)w[i + 1] = nums1[i];
		build(1, 1, n);
		for (auto w : queries) {
			int o = w[0], l = w[1], r = w[2];
			if (o == 1)modify(1, l + 1, r + 1);
			else if (o == 2)tot += query() * l;
			else ans.push_back(tot);
		}
		return ans;
	}
};