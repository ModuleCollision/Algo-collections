/*二维树状数组: 第二种满足区间操作的轻量级数据结构*/
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
	i64 n, m;
	std::cin >> n >> m; vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	vector<i64>tr1(n + 5, 0);
	vector<i64>tr2(n + 5, 0);
	auto add1 = [&](i64 idx, i64 v) {
		for (; idx <= n; idx += (idx & -idx)) {
			tr1[idx] += v;
		}
	};
	auto add2 = [&](i64 idx, i64 v) {
		i64 s = idx * v;
		for (; idx <= n; idx += (idx & -idx)) {
			tr2[idx] += s;
		}
	};
	auto query1 = [&](i64 idx) {
		i64 ret = 0;
		for (; idx >= 1; idx -= (idx & -idx)) {
			ret += tr1[idx];
		}
		return ret;
	};
	auto query2 = [&](i64 idx) {
		i64 ret = 0;
		for (; idx >= 1; idx -= (idx & -idx)) {
			ret += tr2[idx];
		}
		return ret;
	};
	auto modify = [&](i64 l, i64 r, i64 v) {
		add1(l, v); add1(r + 1, -v);
		add2(l, v); add2(r + 1, -v);
	};
	auto query = [&](i64 l, i64 r) {
		l--;
		return (r + 1) * query1(r) - query2(r) - (l + 1) * query1(l) + query2(l);
	};
	for (i64 i = 1; i <= n; i++) {
		add1(i, A[i] - A[i - 1]);
		add2(i, A[i] - A[i - 1]);
	}
	while (m--) {
		string opt; std::cin >> opt;
		if (opt == "C") {
			i64 l, r, d; cin >> l >> r >> d;
			modify(l, r, d);
		} else {
			i64 l; cin >> l;
			cout << query(l, l) << endl;
		}
	}
}
signed main() {
	solve();
}