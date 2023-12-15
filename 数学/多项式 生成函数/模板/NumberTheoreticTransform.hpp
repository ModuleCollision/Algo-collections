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