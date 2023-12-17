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

u64 p[maxn], A[maxn];
/*线性基求出向量组最小/最大异或和*/
void insert(u64 x) {
	for (i64 i = 51; i >= 0; i--) {
		if (((x >> i) & 1)) {
			if (not p[i]) {
				p[i] = x; break;
			} else {
				x ^= p[i];
			}
		}
	}
}
void solve() {
	i64 n; std::cin >> n; u64 ans = 0;
	for (i64 i = 1; i <= n; i++)
		cin >> A[i], insert(A[i]);
	for (i64 i = 51; i >= 0; i--) {
		ans = max(ans, ans ^ p[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}