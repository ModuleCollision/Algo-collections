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
	i64 n, q; cin >> n; vector< i64>A(n + 5, 0);
	std::map< i64,  i64>cnt;
	for ( i64 i = 1; i <= n; i++)cin >> A[i], cnt[A[i]]++;
	std::cin >> q; std::sort(A.begin() + 1, A.begin() + 1 + n);
	while (q--) {
		i64 x, y; std::cin >> x >> y;
		i64 d = x * x - 4 * y;
		if (d < 0) {
			cout << "0" << " "; continue;
		}
		i64 x1 = (x - ( i64)(sqrt(d))) / 2;
		i64 x2 = (x + ( i64)(sqrt(d))) / 2;
		if (x1 + x2 != x or x1 * x2 != y) {
			cout << "0" << " "; continue;
		}
		if (x1 == x2) {
			cout << cnt[x1]*(cnt[x1] - 1) / 2 << " ";
		} else {
			cout << cnt[x1]*cnt[x2] << " " ;
		}
	}
	cout << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}