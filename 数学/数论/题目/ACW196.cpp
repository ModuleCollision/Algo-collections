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


i64 prime[maxn]; i64 cnt = 0;
bool vis[maxn];
void solve() {
	for (i64 i = 2; i <= 1e7; i++) {
		if (not vis[i]) {
			prime[++cnt] = i;
		}
		for (i64 j = 1; j <= cnt and prime[j]*i <= 1e7; j++) {
			vis[prime[j]*i] = 1;
			if (i % prime[j] == 0)break;
		}
	}
	i64 l, r;
	vector<i64>k(1e6 + 5, 0); vector<bool>v(1e6 + 5, false);
	while (cin >> l >> r) {
		std::fill(k.begin(), k.end(), 0);
		std::fill(v.begin(), v.end(), false);
		for (i64 i = 1; i <= cnt; i++) {
			i64 p = prime[i];
			for (i64 j = max(p * 2, (l + p - 1) / p * p); j <= r; j += p) {
				v[j - l] = true;
			}
		}
		i64 c = 0;
		for (i64 i = 0; i <= r - l; i++) {
			if (not v[i] and i + l >= 2) {
				k[++c] = i + l;
			}
		}
		if (c < 2) {
			puts("There are no adjacent primes."); continue;
		}
		i64 midx = 0, madx = 0; i64 mind = inf, maxd = -inf;
		for (i64 i = 2; i <= c; i++) {
			i64 d = k[i] - k[i - 1];
			if (d < mind) {
				mind = d;
				midx = i;
			}
			if (d > maxd) {
				maxd = d;
				madx = i;
			}
		}
		printf("%i64d,%i64d are closest, %i64d,%i64d are most distant.\n", k[midx - 1], k[midx], k[madx - 1], k[madx]);
	}
}
signed main() {
	solve();
}