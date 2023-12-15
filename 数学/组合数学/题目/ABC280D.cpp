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



i64 p[maxn], cnt[maxn], tt = 0;
i64 n;
void pre() {
	for (i64 i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			p[++tt]	= i;
			i64 tmp = 0;
			while (n % i == 0) {
				n /= i; tmp++;
			}
			cnt[tt] = tmp;
		}
	}
	if (n > 1) {
		p[++tt] = n;
		cnt[tt] = 1;
	}
}
void solve() {
	std::cin >> n; pre();
	auto lg = [&](i64 a, i64 b) {
		i64 ret = 0, r = 1;
		while (r <= b) {
			r *= a; ret++;
		}
		if (r > b) {
			r /= a; ret--;
		}
		return ret;
	};
	//cout << lg(2, 8) << endl;
	auto check = [&](i64 mid) {
		for (i64 i = 1; i <= tt; i++) {
			i64 pp = p[i], tmp = mid, tot = 0;
			i64 k = lg(pp, mid);
			i64 ans = 0; i64 cur = 1;
			for (i64 i = 1; i <= k; i++) {
				cur *= pp;
				ans += mid / cur;
			}
			if (ans < cnt[i]) {
				return false;
			}
		}//其阶乘最多能为该素数因子提供的幂次
		//勒让德公式
		return true;
	};
	i64 l = 1, r = inf;
	while (l < r) {
		i64 mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << r << endl;
}
signed main() {
	solve();
}