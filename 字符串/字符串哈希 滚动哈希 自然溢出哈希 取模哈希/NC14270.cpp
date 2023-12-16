
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
	string s; std::cin >> s;
	i64 len = s.size();
	s = " " + s;
	i64 p = 23; i64 n = s.size();
	vector<i64>Hash(n + 5, 0);
	auto ksm = [&](i64 a, i64 b) {
		i64 ret = 1;
		while (b) {
			if (b & 1)ret = ret * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
		return ret;
	};
	for (i64 i = 1; i <= n; i++) {
		Hash[i] = (Hash[i - 1] % mod * p % mod + s[i] - '0') % mod;
	}
	auto get = [&](i64 l, i64 r) {
		return ((Hash[r] - Hash[l - 1] % mod * ksm(p, r - l + 1)) % mod + mod) % mod;
	};
	/*代表取一个字串的哈希值*/
	/*不同字串取到相同哈希值(碰撞)的概率很小*/
	auto check = [&](i64 x) ->bool {
		if (x >= 20) return true ;
		i64 tot = 1 << x ;
		if (tot > len - x + 1) return true ;
		std::set<i64>st;
		for (i64 i = 1; i + x - 1 <= len; i++) {
			st.insert(get(i, i + x - 1));
		}
		return st.size() < tot;//说明未曾出现过
	};
	i64 l = 1, r = len;
	while (l < r) {
		i64 mid = (l + r) >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << r << endl;
}
signed main() {
	solve();
}