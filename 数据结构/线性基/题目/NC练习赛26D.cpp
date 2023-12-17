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

i64 p[maxn], A[maxn];
/*线性基判断01向量组是否能线性表出某个数*/
void solve() {
	auto insert = [&](i64 u) {
		for (i64 i = 33; i >= 0; i--) {
			if ((u >> i) & 1) {
				if (not p[i]) {
					p[i] = u;
					break;
				} else {
					u ^= p[i];
				}
			}
		}
	};
	i64 N, M; std::cin >> N;
	for (i64 i = 1; i <= N; i++) {
		std::cin >> A[i];
		insert(A[i]);
	}
	std::cin >> M;
	while (M--) {
		bool f = 1;
		i64 x, y; std::cin >> x >> y; i64 tmp = x ^ y;
		for (i64 i = 33; i >= 0; i--) {
			if ((tmp >> i) & 1) {
				if (not p[i]) {
					f = 0; break;
				} else tmp ^= p[i];
			}
		}
		if (not f)puts("NO");
		else puts("YES");
	}
}
signed main() {
	solve();
}