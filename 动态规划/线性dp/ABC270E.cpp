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

i64 dp[maxn], K, A[maxn], N;
void solve() {
	std::cin >> N >> K;
	for (i64 i = 0; i < K; i++) {
		std::cin >> A[i];
	}
	for (i64 i = 0; i <= N; i++) {
		for (i64 j = 0; j < K; j++) {
			if (i - A[j] >= 0)
				dp[i] = max(dp[i], i - dp[i - A[j]]);

		}
	}
	cout << dp[N] << endl;
}
signed main() {
	solve();
}