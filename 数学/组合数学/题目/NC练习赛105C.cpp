/*抽象成前缀匹配问题,容易得知乙方赢的方案总数满足卡特兰数*/
/*抽象成出入栈序列,可知前缀中入栈总数大于等于出栈总数*/
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

/*
void chart() {
	i64 s = 0;
	vector<i64>d1, d2;
	function<void(i64, i64)>dfs = [&](i64 d, i64 cur) {
		if (d == s) {
			for (i64 i = 1; i <= (s << 1); i++) {
				if (vis[i]) {
					d1.push_back(i);
				} else {
					d2.push_back(i);
				}
			}
			bool f = 1;
			for (i64 i = 0; i < s; i++) {
				if (d1[i] < d2[i]) {
					f = 0; break;
				}
			}
			if (f)cnt++; d1.clear(); d2.clear();
			return;
		}
		for (i64 i = cur + 1; i <= (s << 1); i++) {
			if (not vis[i]) {
				vis[i] = 1;
				dfs(d + 1, i); vis[i] = 0;
			}
		}
	};
	s = 5; dfs(0, 0);
	cout << cnt << endl;
}*/
//暴力打表来确定规律
i64 catl[maxn], infac[maxn], fac[maxn];
void init() {
	auto inv = [&](i64 x) {
		i64 ret = 1; i64 b = mod - 2;
		while (b) {
			if (b & 1)ret = ret * x % mod;
			x = x * x % mod;
			b >>= 1;
		}
		return ret % mod;
	};
	//卡特兰数的通项 ： Cata[n] = C(2 * n , n) / (n + 1)
	fac[0] = infac[0] = 1; catl[0] = 1;
	for (i64 i = 1; i <= 1e6; i++) {
		catl[i] = catl[i - 1] % mod * ((4 * i % mod - 2) % mod + mod) % mod * inv(i + 1) % mod;
		//卡特兰数
	}
	for (i64 i = 1; i <= 2e6; i++) {
		fac[i] = fac[i - 1] % mod * i % mod;
	}
	for (i64 i = 1; i <= 1e6; i++) {
		infac[i] = (infac[i - 1] % mod * inv(i)) % mod;
	}
}
signed main() {
	init();
	i64 T; std::cin >> T;
	while (T--) {
		i64 n; std::cin >> n;
		i64 res = fac[2 * n] % mod * infac[n] % mod * infac[n] % mod;
		res = ((res - catl[n]) % mod + mod) % mod;
		cout << res % mod << " " << catl[n] % mod << endl;
	}
	return 0;
}