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
	i64 ans = -inf;
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	auto check = [&](i64 x) {
		i64 cnt = 0;
		for (i64 i = 1; i <= n; i++) {
			i64 s = (i64)sqrt(A[i] + x);
			if (s * s == A[i] + x) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
	};
	std::sort(A.begin() + 1, A.begin() + 1 + n);
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = i + 1; j <= n; j++) {
			i64 k = A[j] - A[i];
			for (i64 s = 1; s * s <= k; s++) {
				if (k % s == 0) {
					i64 t = k / s;
					i64 q = (t + s);
					if (not(q & 1)) {
						q /= 2; i64 p = max(s, t) - q;
						if (q * q >= A[j]) {
							check(q * q - A[j]);
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}