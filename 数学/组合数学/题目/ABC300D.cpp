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

i64 p[maxn]; bool vis[maxn];
i64 cnt = 0;
void solve() {
	auto init = [&]() {
		for (i64 i = 2; i <= 1e6; i++) {
			if (not vis[i]) {
				p[++cnt] = i;
			}
			for (i64 j = 1; j <= cnt and i * p[j] <= 1e6; j++) {
				vis[p[j]*i] = 1;
				if (i % p[j] == 0)break;
			}
		}
	};
	init();
	i64 N, ans = 0; std::cin >> N;
	for (i64 i = 1; i <= cnt; i++) {
		if (p[i]*p[i]*p[i + 1]*p[i + 2]*p[i + 2] > N)break;
		for (i64 j = i + 1; j <= cnt; j++) {
			if (p[i]*p[i]*p[j]*p[j + 1]*p[j + 1] > N)break;
			for (i64 k = j + 1; k <= cnt; k++) {
				if (p[i]*p[i]*p[j]*p[k]*p[k] > N)break;
				if (p[i]*p[i]*p[j]*p[k]*p[k] <= N) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}