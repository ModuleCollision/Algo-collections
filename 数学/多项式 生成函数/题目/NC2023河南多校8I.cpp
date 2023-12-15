/*300兆字节 1- 2 秒*/

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

i64 ksm(i64 a, i64 b, i64 m = mod) {
	i64 res = 1;
	while (b) {
		if (b & 1)res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
/*Mii64er-Rabin质数检验*/
bool mr(i64 n) {
	if (n < 3 or n % 2 == 0)return n == 2;
	i64 u = n - 1, t = 0;
	while (u % 2 == 0)u /= 2, t++;
	for (i64 i = 0; i <= 15; i++) {
		i64 a = rand() % (n - 2) + 2, v = ksm(a, u, n);
		if (v == 1)continue;
		i64 s;
		for (s = 0; s < t; s++) {
			if (v == n - 1)break;
			v = v * v % n;
		}
		if (s == t)return false;
	}
	return true;
}
i64 r[maxn];
/*NTT板子*/
void NTT(i64 *x, i64 lim, i64 opt) {
	i64 i, j, k, m, gn, g, tmp;
	for (i64 i = 0; i < lim; i++) {
		if (r[i] < i)swap(x[i], x[r[i]]);
	}
	for (m = 2; m <= lim; m <<= 1) {
		k = m >> 1;
		gn = ksm(3, (mod - 1) / m);
		for (i64 i = 0; i < lim; i += m) {
			g = 1;
			for (j = 0; j < k; j++, g = g % mod * gn % mod) {
				tmp = x[i + j + k] % mod * g % mod;
				x[i + j + k] = (x[i + j] - tmp + mod) % mod;
				x[i + j] = (x[i + j] + tmp) % mod;
			}
		}
	}
	if (opt == -1) {
		reverse(x + 1, x + lim);
		i64 inv = ksm(lim, mod - 2);
		for (i64 i = 0; i < lim; i++)x[i] = 1 * x[i] * inv % mod;
	}
}
i64 A[maxn], B[maxn], C[maxn];
void solve() {
	string a, b; cin >> a >> b;
	i64 na = a.size(), nb = b.size();
	i64 lim = 1;
	for (i64 i = 0; i < na; i++)A[i] = a[na - i - 1] - '0';
	while (lim < (na << 1))lim <<= 1;
	for (i64 i = 0; i < nb; i++)B[i] = b[nb - i - 1] - '0';
	while (lim < (nb << 1))lim <<= 1;
	for (i64 i = 0; i < lim; i++)r[i] = (i & 1) * (lim >> 1) + (r[i >> 1] >> 1);
	NTT(A, lim, 1);
	NTT(B, lim, 1);
	for (i64 i = 0; i < lim; i++)C[i] = A[i] * B[i] % mod;
	NTT(C, lim, -1); i64 len = 0;
	i64 cur = 0;
	for (i64 i = 0; i < lim; i++) {
		C[i] += cur;
		cur = C[i] / 10; C[i] %= 10;
		if (C[i])len = max(len, i);
	}
	while (C[len] >= 10) {
		C[len + 1] += C[len] / 10; C[len] %= 10, len++;
	}
	i64 q; std::cin >> q;
	while (q--) {
		i64 l, r; cin >> l >> r;
		i64 w = 0;
		for (i64 j = r - 1; j >= l - 1; j--)w = (w * 10 + C[j]);
		if (w == 0 or w == 1 or mr(w))puts("YES");
		else puts("NO");
	}
}
signed main() {
	solve();
}
