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
	i64 N, X; cin >> N >> X;
	vector<pair<i64, i64>>A;
	A.push_back({0, -(N + 1)});
	A.push_back({X, N + 1});//必须是从 0 --> X的, 可以理解成 0 为 X 的钥匙
	for (i64 i = 1; i <= N; i++) {
		i64 X; std::cin >> X;
		A.push_back({X, i});//记录坐标和编号
	}
	for (i64 i = 1; i <= N; i++) {
		i64 Y; std::cin >> Y;
		A.push_back({Y, -i});
	}
	std::sort(A.begin(), A.end());
	vector<i64>key(N + 2);//记录钥匙在坐标系中的先后次序
	i64 M = A.size();//离散化操作
	vector dp(M + 1, vector (M + 1, std::array<i64, 2> {inf, inf}));
	i64 pos = 0;
	for (i64 i = 0; i < M; i++) {
		if (A[i].second < 0) {
			key[-A[i].second] = i;
		}
		if (A[i].second == N + 1) {
			key[0] = i;
		}
	}
	i64 ans = inf;
	dp[key[N + 1]][key[N + 1]][0] = dp[key[N + 1]][key[N + 1]][1] = 0;
	//区间dp可以只初始化一个点
	for (i64 len = 1; len <= M; len++) {
		for (i64 i = 0; i + len - 1 <= M - 1; i++) {
			i64 j = i + len - 1;
			vector<i64>coor = {A[i].first, A[j].first};
			for (i64 k = 0; k < 2; k++) {
				if (dp[i][j][k] == inf)continue;
				if (key[0] >= i and key[0] <= j) {
					ans = min(ans, dp[i][j][k]);
				}
				if (i > 0) {
					i64 pos = A[i - 1].first, idx = A[i - 1].second;
					if (idx < 0 or (key[idx] >= i and key[idx] <= j)) {
						//待转移的这一层是钥匙或者是门而且钥匙坐标已经包含于离散化的坐标之中
						dp[i - 1][j][0] = min(dp[i - 1][j][0], dp[i][j][k] + coor[k] - pos);
					}
				}
				if (j + 1 < M) {
					i64 pos = A[j + 1].first, idx = A[j + 1].second;
					if (idx < 0 or (key[idx] >= i and key[idx] <= j)) {
						dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + pos - coor[k]);
					}
				}
			}
		}
	}
	if (ans == inf) {
		puts("-1"); return;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}