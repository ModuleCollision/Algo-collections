/*素数判定*/
bool isPrime(i64 n) {
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