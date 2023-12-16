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
	string s; cin >> s;
	i64 fp = 0; std::map<i64, std::set<i64>>st;
	std::set<i64>ts;
	for (auto c : s) {
		if (c == '(') {
			fp++;
		} else if (isalpha(c)) {
			i64 cur = c - 'a';
			if (ts.count(cur)) {
				puts("No"); return;
			} else {
				st[fp].insert(cur);
				ts.insert(cur);
			}
		} else {
			for (auto c : st[fp]) {
				ts.erase(c);
			}
			fp--;
		}
	}
	puts("Yes");
}
signed main() {
	solve();
}