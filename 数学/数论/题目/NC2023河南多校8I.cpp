#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e7 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll ksm(ll a, ll b, ll m = mod) {
	ll res = 1;
	while (b) {
		if (b & 1)res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
/*Miller-Rabin质数检验*/
bool mr(ll n) {
	if (n < 3 or n % 2 == 0)return n == 2;
	ll u = n - 1, t = 0;
	while (u % 2 == 0)u /= 2, t++;
	for (ll i = 0; i <= 15; i++) {
		ll a = rand() % (n - 2) + 2, v = ksm(a, u, n);
		if (v == 1)continue;
		ll s;
		for (s = 0; s < t; s++) {
			if (v == n - 1)break;
			v = v * v % n;
		}
		if (s == t)return false;
	}
	return true;
}
ll r[maxn];
/*NTT板子*/
void NTT(ll *x, ll lim, ll opt) {
	ll i, j, k, m, gn, g, tmp;
	for (ll i = 0; i < lim; i++) {
		if (r[i] < i)swap(x[i], x[r[i]]);
	}
	for (m = 2; m <= lim; m <<= 1) {
		k = m >> 1;
		gn = ksm(3, (mod - 1) / m);
		for (ll i = 0; i < lim; i += m) {
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
		ll inv = ksm(lim, mod - 2);
		for (ll i = 0; i < lim; i++)x[i] = 1 * x[i] * inv % mod;
	}
}
ll A[maxn], B[maxn], C[maxn];
void solve() {
	string a, b; cin >> a >> b;
	ll na = a.size(), nb = b.size();
	ll lim = 1;
	for (ll i = 0; i < na; i++)A[i] = a[na - i - 1] - '0';
	while (lim < (na << 1))lim <<= 1;
	for (ll i = 0; i < nb; i++)B[i] = b[nb - i - 1] - '0';
	while (lim < (nb << 1))lim <<= 1;
	for (ll i = 0; i < lim; i++)r[i] = (i & 1) * (lim >> 1) + (r[i >> 1] >> 1);
	NTT(A, lim, 1);
	NTT(B, lim, 1);
	for (ll i = 0; i < lim; i++)C[i] = A[i] * B[i] % mod;
	NTT(C, lim, -1); ll len = 0;
	ll cur = 0;
	for (ll i = 0; i < lim; i++) {
		C[i] += cur;
		cur = C[i] / 10; C[i] %= 10;
		if (C[i])len = max(len, i);
	}
	while (C[len] >= 10) {
		C[len + 1] += C[len] / 10; C[len] %= 10, len++;
	}
	ll q; std::cin >> q;
	while (q--) {
		ll l, r; cin >> l >> r;
		ll w = 0;
		for (ll j = r - 1; j >= l - 1; j--)w = (w * 10 + C[j]);
		if (w == 0 or w == 1 or mr(w))puts("YES");
		else puts("NO");
	}
}
signed main() {
	solve();
}
