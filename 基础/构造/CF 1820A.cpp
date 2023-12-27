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
	map<i64, i64>R, L;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> A[i];
		R[A[i]] = i; if (not L.count(A[i]))L[A[i]] = i;
	}
	auto cal = [&]() {
		vector<i64>s(A);
		std::sort(s.begin() + 1, s.begin() + 1 + n);
		i64 len = unique(s.begin() + 1, s.begin() + 1 + n) - s.begin() - 1;
		for (i64 i = 1; i <= len; i++) {
			if (s[i] != i - 1)return i - 1;
		}
		return len;
	};
	i64 mex = cal();
	if (L.count(mex + 1)) {
		i64 l = L[mex + 1], r = R[mex + 1];
		for (i64 i = l; i <= r; i++) {
			A[i] = mex;
		}
		i64 mx = cal();
		if (mx == mex + 1) {
			puts("YES"); return;
		}
		puts("NO");
	} else {
		for (i64 i = 1; i <= n; i++) {
			if (A[i] > mex or L[A[i]] != R[A[i]]) {
				puts("YES"); return;
			}
		}
		puts("NO");
	}
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}