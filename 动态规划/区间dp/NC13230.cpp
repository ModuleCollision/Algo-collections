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

char s1[maxn], s2[maxn];
i64 dp[55][55][55][55];
void solve() {
	std::cin >> (s1 + 1) >> (s2 + 1);
	i64 len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
	i64 res = -inf;
	for (i64 l1 = 0; l1 <= len1; l1++) {
		for (i64 l2 = 0; l2 <= len2; l2++) {
			for (i64 i = 1; i + l1 - 1 <= len1; i++) {
				i64 j = i + l1 - 1;
				for (i64 k = 1; k + l2 - 1 <= len2; k++) {
					i64 l = k + l2 - 1;
					if (l1 + l2 <= 1)dp[i][j][k][l] = 1;
					else {
						dp[i][j][k][l] = 0;
						if (j and s1[i] == s1[j]) {
							dp[i][j][k][l] |= dp[i + 1][j - 1][k][l];
						}
						if (l and s2[k] == s2[l]) {
							dp[i][j][k][l] |= dp[i][j][k + 1][l - 1];
						}
						if (s1[i] == s2[l] and l) {
							dp[i][j][k][l] |= dp[i + 1][j][k][l - 1];
						}
						if (s2[k] == s1[j] and j) {
							dp[i][j][k][l] |= dp[i][j - 1][k + 1][l];
						}
					}
					if (dp[i][j][k][l])res = max(res, l1 + l2);
				}
			}
		}
	}
	cout << res << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}