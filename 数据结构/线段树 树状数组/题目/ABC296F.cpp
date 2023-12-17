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

i64 N;
void solve() {
	std::cin >> N;
	vector<i64>A(N + 5), B(N + 5);
	for (i64 i = 1; i <= N; i++) {
		std::cin >> A[i];
	}
	for (i64 i = 1; i <= N; i++) {
		std::cin >> B[i];
	}
	vector<i64>C = A, D = B;
	std::sort(C.begin() + 1, C.begin() + 1 + N);
	std::sort(D.begin() + 1, D.begin() + 1 + N);
	if (C != D) {
		puts("No"); return;
	}
	for (i64 i = 2; i <= N; i++) {
		if (C[i] == C[i - 1]) {
			puts("Yes"); return;
		}
	}
	vector<i64>tr1(maxn), tr2(maxn);
	auto add1 = [&](i64 id, i64 v) {
		for (; id <= 1e6; id += (id & -id)) {
			tr1[id] += v;
		}
	};
	auto query1 = [&](i64 id, i64 v) {
		i64 ret = 0;
		for (; id >= 1; id -= (id & -id)) {
			ret += tr1[id];
		}
		return ret;
	};
	auto add2 = [&](i64 id, i64 v) {
		for (; id <= 1e6; id += (id & -id)) {
			tr2[id] += v;
		}
	};
	auto query2 = [&](i64 id, i64 v) {
		i64 ret = 0;
		for (; id >= 1; id -= (id & -id)) {
			ret += tr2[id];
		}
		return ret;
	};
	i64 ans = 0;
	for (i64 i = N; i >= 1; i--) {
		ans += query1(A[i] - 1, 1);
		add1(A[i], 1);
	}
	for (i64 i = N; i >= 1; i--) {
		ans += query2(B[i] - 1, 1);
		add2(B[i], 1);
	}
	puts(ans % 2 ? "No" : "Yes");
}
signed main() {
	solve();
}