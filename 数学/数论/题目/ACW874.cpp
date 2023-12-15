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




i64 prime[maxn], e[maxn];
bool vis[maxn]; i64 cnt = 0;
void solve() {
	i64 n; std::cin >> n;
	e[1] = 1; i64 ans = 0; ans += e[1];
	for (i64 i = 2; i <= maxn; i++) {
		if (not vis[i]) {
			e[i] = i - 1; prime[++cnt] = i;
		}
		if (i <= n)
			ans += e[i];
		for (i64 j = 1; j <= cnt and i * prime[j] <= maxn; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j]) {
				e[i * prime[j]] = e[prime[j]] * e[i];
			} else {
				e[i * prime[j]] = e[i] * prime[j];
				break;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
