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
	i64 n, b, p, k;
	std::cin >> n >> b >> p >> k;
	i64 Hash = 0;
	string s; cin >> s; s = " " + s;
	for (i64 i = 1; i <= n; i++) {
		Hash = (Hash * b + s[i] - 'a' + 1) % p;
	}
	vector dp(n + 5, vector (k + 5, vector<i64>(1005, 0)));
	auto now = dp, pre = dp;
	dp[0][0][0] = 1;
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 0; j <= k; j++) {
			for (i64 l = 0; l < p; l++) {
				for (char q = 'a'; q <= 'z'; q++) {
					if (s[i] == q) {
						if (j and dp[i - 1][j - 1][l]) {
							dp[i][j][(l * b + q - 'a' + 1) % p] = 1;
							now[i][j][(l * b + q - 'a' + 1) % p] = q;
							pre[i][j][(l * b + q - 'a' + 1) % p] = l;
						}
					} else {
						if (dp[i - 1][j][l]) {
							dp[i][j][(l * b + q - 'a' + 1) % p] = 1;
							now[i][j][(l * b + q - 'a' + 1) % p] = q;//到达这个状态的当前字母
							pre[i][j][(l * b + q - 'a' + 1) % p] = l;//到达这个状态的上一个哈希值
						}
					}
				}
			}
		}
	}
	if (not dp[n][k][Hash]) {
		puts("-1"); return;
	}
	i64 ps = Hash; string ans = "";
	for (i64 i = n, ned = k; i >= 1; i--) {
		ans += now[i][ned][ps];
		i64 tmp = ps;
		ps = pre[i][ned][ps];
		if (now[i][ned][tmp] == s[i])ned--;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}