/*状压dp:*/
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

i64 N, M;
void solve() {
	//std::cin >> N >> M;
	vector<vector<i64>>dp(M + 5, vector<i64>((1 << N), 0));
	vector<bool>st((1 << N), false);
	std::map<i64, vector<i64>>tr;
	for (i64 i = 0; i < (1 << N); i++) {
		i64 cnt = 0; bool is_valid = true;
		for (i64 j = 1; j <= N; j++) {
			if ((i >> (j - 1)) & 1) {
				if (cnt & 1) {
					is_valid = false;
					break;
				} else {
					cnt = 0;
				}
			} else {
				cnt++;
			}//统计状态中奇数个空白的个数
		}
		if (cnt & 1) {
			is_valid = false;
		}//不能出现奇数个连续的空白
		st[i] = is_valid;
	}
	for (i64 i = 0; i < (1 << N); i++) {
		for (i64 j = 0; (j < (1 << N)); j++) {
			if (st[i | j] and not(i & j)) {
				tr[i].push_back(j);
			}
		}
	}
	for (i64 i = 0; i < (1 << N); i++) {
		if (st[i]) {
			dp[1][i]++;
		}
	}
	for (i64 i = 2; i <= M; i++) {
		for (i64 j = 0; j < (1 << N); j++) {
			for (auto k : tr[j]) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	cout << dp[M][0] << endl;
}
signed main() {
	while (std::cin >> N >> M and N and M)
		solve();
}