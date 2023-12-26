/*子数组和的异或和*/
#include<bits/stdc++.h>

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

i64 tr1[20000005]; i64 tr2[20000005];
void solve() {
	i64 n; std::cin >> n;
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	for (i64 i = 1; i <= n; i++)A[i] += A[i - 1];
	auto add1 = [&](i64 idx, i64 v) {
		for (; idx <= 2e7; idx += (idx & -idx))tr1[idx] += v;
	};
	auto query1 = [&](i64 idx) {
		i64 ret = 0;
		for (; idx >= 1; idx -= (idx & -idx))ret += tr1[idx];
		return ret;
	};
	auto add2 = [&](i64 idx, i64 v) {
		for (; idx <= 2e7; idx += (idx & -idx))tr2[idx] += v;
	};
	//统计高位 1 的个数
	auto query2 = [&](i64 idx) {
		i64 ret = 0;
		for (; idx >= 1; idx -= (idx & -idx))ret += tr2[idx];
		return ret;
	}; i64 ans = 0;//统计高位 0 的个数
	for (i64 j = 0; j <= 25; j++) {
		i64 msk = (1 << j); i64 cnt = 0;
		memset(tr1, 0, sizeof(tr1));
		memset(tr2, 0, sizeof(tr2));
		for (i64 i = 0; i <= n; i++) {
			i64 md = (A[i]) % msk; md += 1;
			if (A[i] & (1 << j)) {
				//递增： 同为 1 可以借位补 1
				cnt += query1(2e7) - query1(md);
				//递增 该位不是 1
				cnt += query2(md);
				add1(md, 1);
			} else {
				cnt += query2(2e7) - query2(md);
				cnt += query1(md);
				add2(md, 1);
			}
		}
		if (cnt & 1)ans += (1 << j);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}