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