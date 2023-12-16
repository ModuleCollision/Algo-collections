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

i64 A[maxn][maxn], sum[maxn][maxn][maxn];
i64 H, W, N, h, w;
std::map<i64, i64>cnt;
//二维前缀和
void solve() {
	set<i64>x;
	std::cin >> H >> W >> N >> h >> w;
	for (i64 i = 1; i <= H; i++) {
		for (i64 j = 1; j <= W; j++) {
			std::cin >> A[i][j];
			x.insert(A[i][j]);
			cnt[A[i][j]]++;
			sum[i][j][A[i][j]]++;
			for (i64 k = 1; k <= N; k++) {
				sum[i][j][k] += sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k];
			}//二维关于某数的前缀和
		}
	}
	for (i64 i = h; i <= H; i++) {
		for (i64 j = w; j <= W; j++) {
			i64 ans = x.size();
			for (i64 k = 1; k <= N; k++) {
				i64 res = sum[i][j][k] - sum[i - h][j][k] - sum[i][j - w][k] + sum[i - h][j - w][k];
				if (res == cnt[k]) {
					ans--;
				}
			}
			cout << ans << endl;
		}
	}
}
signed main() {
	solve();
}