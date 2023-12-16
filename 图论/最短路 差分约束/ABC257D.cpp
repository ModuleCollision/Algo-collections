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

i64 d[maxn][maxn], x[maxn], y[maxn], p[maxn];
i64 N;
void solve() {
	std::cin >> N;
	for (i64 i = 1; i <= N; i++) {
		std::cin >> x[i] >> y[i] >> p[i];
	}
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = 1; j <= N; j++) {
			i64 dis = abs(x[i] - x[j]) + abs(y[j] - y[i]);
			//i == j则初始化为0
			//否则初始化为边或者inf
			d[i][j] = (dis + p[i] - 1) / p[i];//Floyd初始化
		}
	}
	for (i64 k = 1; k <= N; k++) {
		for (i64 i = 1; i <= N; i++) {
			for (i64 j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], max(d[i][k] , d[k][j]));
			}
		}
	}//先枚举k,再枚举i,最后枚举j
	i64 ans = inf;
	for (i64 i = 1; i <= N; i++) {//枚举起点
		i64 cur = 0;
		for (i64 j = 1; j <= N; j++) {
			cur = max(cur, d[i][j]);
		}//保证起点联通的下限
		ans = min(ans, cur);
	}//更新答案
	cout << ans << endl;
}
signed main() {
	solve();
}