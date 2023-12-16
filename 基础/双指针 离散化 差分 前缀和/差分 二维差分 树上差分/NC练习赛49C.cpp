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

struct sq {
	i64 opt; i64 l; i64 r;
};
void solve() {
	i64 n, m; cin >> n >> m;
	vector<sq>q(m + 5);
	vector<i64>d1(m + 5, 0), d2(n + 5, 0);
	vector<i64>l(m + 5, 0), r(m + 5, 0);
	for (i64 i = 1; i <= m; i++) {
		cin >> q[i].opt >> q[i].l >> q[i].r;
		l[i] = q[i].l;
		r[i] = q[i].r;
	}
	for (i64 i = m; i >= 1; i--) {
		d1[i] = (d1[i] % mod + d1[i + 1]) % mod;
		if (q[i].opt == 1) {
			d2[l[i]] = (d2[l[i]] % mod + d1[i] + 1) % mod;
			d2[r[i] + 1] = ((d2[r[i] + 1] % mod - (d1[i] + 1)) % mod + mod) % mod;
		} else {
			d1[r[i]] = (d1[r[i]] % mod + d1[i] + 1) % mod;
			d1[l[i] - 1] = ((d1[l[i] - 1] - d1[i] - 1) % mod + mod) % mod;
		}
	}
	for (i64 i = 1; i <= n; i++) {
		d2[i] += d2[i - 1];
		d2[i] %= mod;
		cout << d2[i] % mod << " ";
	}
	cout << endl;
}
signed  main() {
	solve();
}




