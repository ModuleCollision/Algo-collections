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
	i64 x, y, k, b; std::cin >> x >> y >> k >> b;
	vector<i64>p(35, 0); p[0] = 1;
	for (i64 i = 1; i <= 10; i++) {
		p[i] = p[i - 1] * i;
	}
	vector c(35, vector<i64>(35, 0));
	for (i64 i = 0; i <= 32; i++) {
		for (i64 j = 0; j <= i; j++) {
			if (not j)c[i][j] = 1;
			else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	/*递推组合数(防止 爆 long long int)*/
	auto dp = [&](i64 n) {
		if (not n)return 0ll;
		i64 ret = 0 ;
		vector<i64>s;
		while (n) {
			s.push_back(n % b); n /= b;
		}
		i64 w = s.size();
		for (i64 i = w - 1, las = 0; i >= 0; i--) {
			i64 cur = s[i];
			if (cur) {
				ret += c[i][k - las];
				if (cur > 1) {
					if (k - las - 1 >= 0)ret += c[i][k - las - 1];
					break;
				} else {
					las++;
					if (las > k)break;
				}
			}
			if (i == 0 and las == k)ret++;
		}
		return ret;
	};
	cout << dp(y) - dp(x - 1) << endl;
}
signed main() {
	solve();
}