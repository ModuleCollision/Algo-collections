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
	std::map<i64, i64>cnt;
	i64 n; std::cin >> n;
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		i64 v; std::cin >> v; cnt[v]++;
	}
	i64 tot = 0;
	for (auto [x, y] : cnt)A[++tot] = x;
	for (i64 i = 1; i <= n; i++) {
		while (cnt[A[i]] > 0) {
			i64 j = A[i];
			while (cnt[j + 1] >= cnt[j] and j <= n and cnt[j + 1] > 0) {
				cnt[j]--; j++;
			}
			cnt[j]--;
			if (j - A[i] + 1 < 5) {
				puts("NO"); return;
			}
		}
	}
	puts("YES"); return;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}