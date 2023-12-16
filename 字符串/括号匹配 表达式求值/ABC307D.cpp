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
	i64 N; std::string s;
	std::cin >> N >> s;
	s = " " + s;
	vector<char>ans; i64 cnt = 0;
	for (i64 i = 1; i <= N; i++) {
		if (s[i] == '(') {
			cnt++; ans.push_back(s[i]);
		} else if (s[i] == ')') {
			if (cnt) {
				cnt--;
				while (ans.back() != '(') {
					ans.pop_back();
				}
				ans.pop_back();
			} else {
				ans.push_back(s[i]);
			}
		} else {
			ans.push_back(s[i]);
		}
	}
	for (auto c : ans) {
		putchar(c);
	}
}
signed main() {
	solve();
}