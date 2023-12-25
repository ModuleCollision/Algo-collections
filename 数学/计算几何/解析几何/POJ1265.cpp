/*多组Test下使用封装数据结构, 在函数中开对象,避免暴力清空数组造成时间浪费*/

/*STL: 数据结构 cin cout function类 lowerbound builtin max min accumulate iota stoi atoi等函数需要加上std,避免命名空间污染*/

/*数学先打表, 后对拍, 图论只会暴力就bitset搞*/

/*300兆字节 1- 2 秒*/

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



/*Pick定理 */
/* 求任意多边形面积*/
/* 两端点在整点的边经过的点数为gcd(dx, dy) */
int cur = 1;
void solve() {
	i64 n; std::cin >> n;
	i64 sum = 0;
	i64 e = 0;// 边上的点

	std::vector<std::pair<i64, i64>>p(n + 1);
	auto cal = [&](i64 i, i64 j) {
		return abs(p[i].second * p[j].first - p[i].first * p[j].second);
	};
	for (i64 i = 1; i <= n; i++) {
		std::cin >> p[i].first >> p[i].second;
		p[i].first += p[i - 1].first;
		p[i].second += p[i - 1].second;
		i64 dx = std::abs(p[i].first);
		i64 dy = std::abs(p[i].second);
		e += std::__gcd(dx, dy);
		sum += cal(i - 1, i);
	}
	printf("Scenario #%d:\n", cur++);
	printf("%d %d %.1f\n\n", (sum - e + 2) >> 1, e, sum * 0.5);
}
int main() {
	int T; std::cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
