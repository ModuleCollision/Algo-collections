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



i128 t[30];
void solve() {
	auto read = [&]()->i128{
		i128 x = 0, f = 1;
		char ch = getchar();
		while (not isdigit(ch)) {
			if (ch == '-')f = -1;
			ch = getchar();
		}
		while (isdigit(ch))x = x * 10 + ch - '0', ch = getchar();
		return x * f;
	};
	function<void(i128)> write = [&](i128 x) {
		if (x < 0)putchar('-'), x = -x;
		if (x > 9)write(x / 10);
		putchar(x % 10 + '0');
	};
	i128 n = read();
	t[1] = 5;
	for (int i = 2; i <= 26; i++) {
		t[i] = t[i - 1] * 5;
	}
	i128 ans = 0;
	auto ws = [&](i128 k)->i128{
		if (n < k)return 0;
		return (n - k) / 2 + 1;
	};
	for (int i = 1; i <= 26; i++) {
		i128 cur = t[i], curr = cur * 2;
		if (n >= cur) {
			i128 r = (n - cur) / 2 + 1;
			i128 c = (n - cur) / curr + 1;
			i128 l = r - (c - 1) * cur;
			ans += (l + r) * c / 2;
		}
		if (n >= curr) {
			i128 r = (n - curr) / 2 + 1;
			i128 c = (n - curr) / curr + 1;
			i128 l = r - (c - 1) * cur;
			ans += (l + r) * c / 2;
		}
	}
	write(ans);
}
signed main() {
	solve();
}