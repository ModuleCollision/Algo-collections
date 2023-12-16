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
	i64 n, m; cin >> n >> m;
	vector<i64>A(n + 5, 0); vector<i64>B(m + 5, 0);
	std::set<i64>v;
	std::map<i64, i64>cnt1, cnt2;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> A[i]; v.insert(A[i]);
	}
	for (i64 i = 1; i <= m; i++) {
		std::cin >> B[i]; v.insert(B[i]);
	}
	std::sort(A.begin() + 1, A.begin() + 1 + n);
	std::sort(B.begin() + 1, B.begin() + 1 + m);
	i64 l = 0, r = 1e9;
	auto check = [&](i64 v) {
		i64 idx1 = upper_bound(A.begin() + 1, A.begin() + 1 + n, v) - A.begin() - 1;
		i64 idx2 = m - (lower_bound(B.begin() + 1, B.begin() + 1 + m, v) - B.begin()) + 1;
		return idx1 >= idx2;
	};
	while (l < r) {
		i64 mid = (l + r) >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << r << endl;
}
signed main() {
	solve();
}