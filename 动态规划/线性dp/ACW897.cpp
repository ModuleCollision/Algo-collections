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

i64 N, M; string A, B;
i64 dp[maxn][maxn];
void solve() {
	std::cin >> N >> M;
	std::cin >> A >> B;//最长公共子序列
	A = ' ' + A, B = ' ' + B;
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = 1; j <= M; j++) {
			if (A[i] == B[j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			} else {
				dp[i][j] = max({dp[i][j], dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
			}
		}
	}
	cout << dp[N][M] << endl;
}
signed main() {
	solve();
}