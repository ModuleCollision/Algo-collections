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

i64 N, M, K;
struct sq {
	i64 a, b, c;
};
void solve() {
	std::cin >> N >> M >> K;
	vector<i64>dp(N + 5, inf);
	dp[1] = 0;
	vector<sq>q(M + 5);
	for (i64 i = 1; i <= M; i++) {
		std::cin >> q[i].a >> q[i].b >> q[i].c;
	}
	/*枚举边进行dp*/
	for (i64 i = 1; i <= K; i++) {
		i64 x; std::cin >> x;
		dp[q[x].b] = std::min(dp[q[x].b], dp[q[x].a] + q[x].c);
	}
	if (dp[N] == inf) {
		puts("-1");
	} else {
		cout << dp[N] << endl;
	}
}
signed main() {
	solve();
}