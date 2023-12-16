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

void solve() {
	i64 n, k; std::cin >> n >> k;
	vector<i64>A(n + 5, 0);
	vector<i64>cnt1(n + 5, 0), cnt2(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		cin >> A[i]; i64 cur = A[i];
		while (cur % 2 == 0) {
			cur /= 2; cnt1[i]++;
		}
		while (cur % 5 == 0) {
			cur /= 5; cnt2[i]++;
		}
	}
	for (i64 i = 1; i <= n; i++) {
		cnt1[i] += cnt1[i - 1]; cnt2[i] += cnt2[i - 1];
	}
	i64 ans = 0;
	auto f = [&](const i64 & x, const i64 & y)->bool const {
		return x < y;
	};/*lower_bound 和 upper_bound equal_range 重载 lambda:
		找到不满足函数(T, val)所代表的布尔条件的第一个迭代器*/
	for (i64 i = 1; i <= n; i++) {
		i64 cur1 = cnt1[i], cur2 = cnt2[i];
		if (cur1 < k or cur2 < k)continue;
		i64 idx1 = upper_bound(cnt1.begin(), cnt1.begin() + i, cur1 - k, f) - cnt1.begin();
		idx1--;
		i64 idx2 = upper_bound(cnt2.begin(), cnt2.begin() + i, cur2 - k, f) - cnt2.begin();
		idx2--;
		i64 s = min(idx1, idx2);
		idx1 = upper_bound(cnt1.begin(), cnt1.begin() + i, cur1 - k - 1, f) - cnt1.begin();
		idx2 = upper_bound(cnt2.begin(), cnt2.begin() + i, cur2 - k - 1, f) - cnt2.begin();
		i64 s2 = min(idx1, idx2);
		s++;
		s2++;
		//if (not (s >= 1 and s <= i and s2 >= 1 and s2 <= i))continue;
		ans += max(0ll, s - s2 + 1);
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}


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

void solve() {
	i64 n, k; std::cin >> n >> k;
	vector<i64>A(n + 5, 0);
	vector<i64>cnt1(n + 5, 0), cnt2(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		cin >> A[i]; i64 cur = A[i];
		while (cur % 2 == 0) {
			cur /= 2; cnt1[i]++;
		}
		while (cur % 5 == 0) {
			cur /= 5; cnt2[i]++;
		}
	}
	for (i64 i = 1; i <= n; i++) {
		cnt1[i] += cnt1[i - 1]; cnt2[i] += cnt2[i - 1];
	}
	i64 ans = 0;
	auto f = [&](const i64 & x, const i64 & y)->bool const {
		return x < y;
	};
	for (i64 i = 1; i <= n; i++) {
		i64 cur1 = cnt1[i], cur2 = cnt2[i];
		if (cur1 < k or cur2 < k)continue;
		i64 idx1 = upper_bound(cnt1.begin(), cnt1.begin() + i, cur1 - k, f) - cnt1.begin();
		idx1--;
		i64 idx2 = upper_bound(cnt2.begin(), cnt2.begin() + i, cur2 - k, f) - cnt2.begin();
		idx2--;
		i64 s = min(idx1, idx2);
		idx1 = lower_bound(cnt1.begin(), cnt1.begin() + i, cur1 - k, f) - cnt1.begin();
		idx2 = lower_bound(cnt2.begin(), cnt2.begin() + i, cur2 - k, f) - cnt2.begin();
		i64 s2 = min(idx1, idx2);
		s++;
		s2++;
		//if (not (s >= 1 and s <= i and s2 >= 1 and s2 <= i))continue;
		ans += max(0ll, s - s2 + 1);
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}