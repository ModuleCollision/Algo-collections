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

/*相向双指针*/
void solve() {
	i64 n, k; std::cin >> n >> k;
	vector<i64>A(n + 5, 0); for (i64 i = 1; i <= n; i++)cin >> A[i];
	std::sort(A.begin() + 1, A.begin() + 1 + n);
	vector<i64>w(1), p(1); i64 zero = 0;//w 负数 p正数
	for (i64 i = 1; i <= n; i++) {
		if (A[i] < 0)w.push_back(A[i]);
		else p.push_back(A[i]);
	}
	i64 sz1 = w.size() - 1, sz2 = p.size() - 1;
	auto check = [&](i64 mid) {
		i64 cnt = 0;//相向双指针，
		if (mid >= 0) {
			cnt += sz1 * sz2;
			for (i64 i = 1, j = sz2; i <= sz2; i++) {
				while (j >= 1 and p[i]*p[j] > mid)j--;
				cnt += max(j - i, 0ll);
			}
			for (i64 i = sz1, j = 1; i >= 1; i--) {
				while (j <= sz1 and w[i]*w[j] > mid)j++;
				cnt += max(0ll, i - j);
			}
		} else {
			for (i64 i = 1, j = 1; i <= sz2; i++) {
				while (j <= sz1 and p[i]*w[j] <= mid)j++;
				cnt += j - 1;
			}
		}
		return cnt >= k;
	};
	i64 l = -1e18, r = 1e18; i64 ans = -inf;
	while (l < r) {
		i64 mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		}
		else l = mid + 1;
	}
	cout << l << endl;
}
signed main() {
	solve();
}