/*要求实现单点修改的数据结构,每次查询前k大的和*/
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

struct cmp {
	bool operator()(const  i64&x, const  i64&y)const {
		return x < y;
	}
};
void solve() {
	std::multiset< i64, cmp>st1, st2;
	 i64 n, k, q; std::cin >> n >> k >> q;
	for ( i64 i = 1; i <= k; i++)st1.insert(0);
	for ( i64 i = 1; i <= n - k; i++)st2.insert(0);
	vector< i64>A(n + 5, 0);  i64 ans = 0;
	while (q--) {
		 i64 x, y;
		std::cin >> x >> y;
		if (st1.count(A[x])) {
			st1.erase(st1.find(A[x]));
			ans -= A[x];
		} else {
			st2.erase(st2.find(A[x]));
		}
		A[x] = y;
		if (st2.size() and (*st2.rbegin()) <= y) {
			st1.insert(y); ans += y;
		} else {
			st2.insert(y);
		}
		while (st1.size() < k) {
			 i64 tmp = *st2.rbegin();
			st2.erase(st2.find(tmp));
			st1.insert(tmp);
			ans += tmp;
		}
		while (st2.size() < n - k) {
			 i64 tmp = *st1.begin();
			st1.erase(st1.begin());
			st2.insert(tmp);
			ans -= tmp;
		}
		cout << ans << endl;
	}
}
signed main() {
	solve();
}