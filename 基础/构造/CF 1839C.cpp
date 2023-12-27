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
	i64 n; std::cin >> n; i64 tot = 0;
	vector<i64>A(n + 5, 0), B(n + 5, 0);
	for (i64 i = 1; i <= n; i++)std::cin >> A[i];
	for (i64 l = 0, r = 1; r <= n; r++) {
		if (not A[r]) {
			B[++tot] = r - l - 1;
			for (i64 k = l + 1; k < r; k++) {
				B[++tot] = 0;
			}
			r = l;
		}
	}
	if (A[n] == 1) {
		puts("NO");
	} else {
		puts("YES");
		for (i64 i = 1; i <= tot; i++) {
			cout << B[i] << " ";
		}
		cout << endl;
	}
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}