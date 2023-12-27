/*对于任何区间操作 + 单点删除 + 单点查询的题目*/
/*都可以使用set 套链表解决*/
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

i64 n;
struct sq {
	i64 pre; i64 nxt; i64 v;
} tr[maxn];
void solve() {
	i64 q;
	std::cin >> n >> q; vector<i64>A(n + 5, 0);
	std::set<i64>st;
	auto cal = [&](i64 x) {
		i64 ret = 0;
		while (x) {
			ret += x % 10;
			x /= 10;
		}
		return ret;
	};
	for (i64 i = 1; i <= n; i++) {
		std::cin >> A[i]; st.insert(i);
		tr[i].pre = i - 1;
		tr[i].nxt = i + 1;
	}
	auto del = [&](i64 i) {
		st.erase(i);
		tr[tr[i].nxt].pre = tr[i].pre;
		tr[tr[i].pre].nxt = tr[i].nxt;
	};
	while (q--) {
		i64 o; std::cin >> o;
		if (o == 1) {
			i64 l, r; std::cin >> l >> r;
			i64 e = *st.lower_bound(l);
			for (i64 j = e; j <= r and j; j = tr[j].nxt) {
				A[j] = cal(A[j]);
				if (cal(A[j]) == A[j]) {
					del(j);
				}
			}
		} else {
			i64 udx; std::cin >> udx; cout << A[udx] << endl;
		}
	}
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}