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