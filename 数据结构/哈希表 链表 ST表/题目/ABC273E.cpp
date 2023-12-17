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

struct sq {
	i64 val; i64 fa;
} tr[maxn]; i64 tot = 0; i64 it = 0, x = 0;
std::map<i64, i64>sta; //The page to the state
void init() {
	tr[0].fa = -1;
}
void add(i64 x) {
	tr[++tot].fa = it;
	it = tot;
	tr[tot].val = x;
	return;
}
void del() {
	if (not it)return;
	it = tr[it].fa;
	return;
}
void save(i64 x) {
	sta[x] = it;
}
void load(i64 x) {
	it = sta[x];
}
i64 Q; string opt;
void solve() {
	std::cin >> Q; init();
	for (i64 i = 1; i <= Q; i++) {
		std::cin >> opt;
		if (opt == "ADD") {
			std::cin >> x; add(x);
		} else if (opt == "DELETE") {
			del();
		} else if (opt == "SAVE") {
			std::cin >> x; save(x);
		} else {
			std::cin >> x; load(x);
		}
		cout << (tr[it].val ? tr[it].val : -1) << " ";
	}
}
signed main() {
	solve();
}
