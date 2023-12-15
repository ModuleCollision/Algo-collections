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

constexpr i64 mod = 1145141;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
bool vis[maxn];  i64 cnt = 0;
void solve() {
	i64 x; std::cin >> x;
	cout << "f(" << x << ")=";
	for (i64 i = 2; i <= x; i++) {
		if (not vis[i]) {
			i64 sum = 0;
			sum += (1) * (x - i + 1);
			for (i64 j = i + i; j <= x; j += i) {
				vis[j] = 1;
				i64 tmp = j; i64 c = 0; while (tmp % i == 0) {
					tmp /= i, c++;
				}
				c *= (x - j + 1); sum += c;
			}
			if (i != 2)cout << "*" << "";
			cout << i << "";
			if (sum != 1)cout << "^" << sum << "";
		}
	}
}
signed main() {
	solve();
}


/*Legendre定理求解 n! 对于素数 p 的 因子阶乘数*/
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

constexpr i64 mod = 1145141;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


int prime[maxn]; int cnt = 0; bool vis[maxn];
void solve() {
	i64 x; std::cin >> x;
	cout << "f(" << x << ")=";
	for (int i = 2; i <= x; i++) {
		if (not vis[i]) {
			prime[++cnt] = i;
		}
		for (i64 j = 1; prime[j]*i <= x and j <= cnt; j++) {
			vis[prime[j]*i] = 1;
			if (i % prime[j] == 0)break;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		i64 sum = 0;
		for (i64 d = prime[i]; d <= x; d *= prime[i]) {
			i64 st = x + 1 - x / d * d, ed = x + 1 - d;
			sum += 1i64 * ((ed - st + d) / d ) * (ed + st) / 2;
		}
		if (i != 1)cout << "*" << "";
		cout << prime[i];
		if (sum != 1)cout << "^" << sum << "";
	}
}
signed main() {
	solve();
}