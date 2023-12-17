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
	i64 N; std::cin >> N;
	vector<i64>A(N + 5), p(N + 5);
	for (i64 i = 1; i <= N; i++) {
		std::cin >> A[i]; p[i] = A[i];
	}
	std::sort(p.begin() + 1, p.begin() + 1 + N);
	i64 cnt = unique(p.begin() + 1, p.begin() + 1 + N) - p.begin() - 1;
	std::map<i64, i64>sk, ks;
	for (i64 i = 1; i <= cnt; i++) {
		sk[i] = p[i]; ks[p[i]] = i;
	}
	vector<i64>dp(N + 5);
	dp[1] = 1;
	vector<i64>tr(cnt + 5);
	auto add = [&](i64 idx, i64 v) {
		for (; idx <= cnt; idx += (idx & -idx)) {
			tr[idx] = max(tr[idx], v);
		}
	};
	auto query = [&](i64 idx) {
		i64 ret = 0;
		for (; idx >= 1; idx -= (idx & -idx)) {
			ret = max(ret, tr[idx]);
		}
		return ret;
	};
	add(ks[A[1]], dp[1]);
	for (i64 i = 2; i <= N; i++) {
		dp[i] = max(dp[i], query(ks[A[i]] - 1) + 1);
		add(ks[A[i]], dp[i]);
	}
	i64 ans = 0; for (i64 i = 1; i <= N; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
/*树状数组维护前缀最大最小值*/