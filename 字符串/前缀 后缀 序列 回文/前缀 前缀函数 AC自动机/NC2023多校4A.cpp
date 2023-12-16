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
	bool f1 = 1, f2 = 1;
	i64 n; string t; std::cin >> n >> t;
	i64 m = t.size();
	vector<i64>p1(2 * m + n + 5); auto p2 = p1;
	std::string tmp1, tmp2;
	for (i64 i = 0; i < n; i++)tmp1 += '1';
	for (i64 i = 0; i < n; i++)tmp2 += '0';
	tmp1 = t + tmp1 + t;
	tmp2 = t + tmp2 + t;
	i64 len = 2 * m + n;
	for (i64 i = 1; i < len; i++) {
		i64 j = p1[i - 1];
		while (j > 0 and tmp1[i] != tmp1[j]) j = p1[j - 1];
		if (tmp1[i] == tmp1[j])j++;
		p1[i] = j;
	}
	for (i64 i = 1; i < len; i++) {
		i64 j = p2[i - 1];
		while (j > 0 and tmp2[i] != tmp2[j]) j = p2[j - 1];
		if (tmp2[i] == tmp2[j])j++;
		p2[i] = j;
	}
	for (i64 i = 0; i < len; i++) {
		if (p1[i] == m and i != len - 1) {
			f1 = 0; break;
		}
	}
	for (i64 i = 0; i < len; i++) {
		if (p2[i] == m and i != len - 1) {
			f2 = 0; break;
		}
	}
	if (f1) {for (i64 i = 0; i < n; i++) putchar('1'); cout << endl;}
	else if (f2) {for (i64 i = 0; i < n; i++)putchar('0'); cout << endl;}
	else puts("-1");
	return;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}