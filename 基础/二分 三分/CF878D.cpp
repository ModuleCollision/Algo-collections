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
	i64 n; std::cin >> n;
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	/*if (n == 1) {
		cout << 0 << endl; return;
	}
	if (n == 6 and A[2] == 10) {
		cout << 1 << endl; return;
	}*/
	std::sort(A.begin() + 1, A.begin() + 1 + n, [&](i64 x, i64 y)->bool{
		return x < y;
	});
	i64 l = 0, r = A[n] + 5;
	auto check = [&](i64 mid) {
		vector<pair<i64, i64>>f;
		i64 l1 = upper_bound(A.begin() + 1, A.begin() + 1 + n, A[1] + 2 * mid - 2) - A.begin() - 1;
		l1++;
		i64 l2 = upper_bound(A.begin() + l1, A.begin() + 1 + n, A[l1] + 2 * mid - 2) - A.begin() - 1;
		l2++;
		i64 l3 = upper_bound(A.begin() + l2, A.begin() + 1 + n, A[l2] + 2 * mid - 2) - A.begin() - 1;
		if (l3 < n) {
			return false;
		}
		return true;
	};
	i64 ans = -1;
	while (l < r) {
		i64 mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << r - 1 << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}