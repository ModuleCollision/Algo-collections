/*结论,gcd(a, b) = gcd(a, b - a), a < b*/
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
	i64 a, b;
	function<i64(i64, i64)> gcd = [&](i64 x, i64 y) {
		return y == 0 ? x : gcd(y, x % y);
	};
	std::cin >> a >> b;
	if (a == b and a != 1) {
		puts("0"); return;
	} else if (gcd(a, b) > 1) {
		puts("0"); return;
	} else if (a == 1 and b == 1) {
		puts("1"); return;
	}
	if (a > b) {
		swap(a, b);
	}
	i64 d = b - a;
	vector<i64>p;
	for (i64 i = 1; i * i <= d; i++) {
		if (d % i == 0) {
			p.push_back(i);
			if (d / i != i) {
				p.push_back(d / i);
			}
		}
	}
	i64 ans = inf;
	for (auto c : p) {
		if (c != 1)
			ans = min(ans, (a + c - 1) / c * c - a);
	}
	if (ans == inf) {
		puts("-1"); return;
	}
	cout << ans << endl;
}


signed main() {
	solve();
}