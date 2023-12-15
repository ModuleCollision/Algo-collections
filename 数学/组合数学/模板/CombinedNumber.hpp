struct Comb {
public:
	i64 mo; //模数
	std::vector<i64>fac;
	std::vector<i64>invfac;
	std::vector<i64>inv; i64 len; // 维护范围
	Comb() {}

	Comb(i64 mo, i64 len = 1e6): mo(mo), len(len) {
		init();
	}
	void init() {
		fac.assign(len + 5, 0);
		invfac.assign(len + 5, 0);
		inv.assign(len + 5, 0);
		fac[0] = fac[1] = 1;
		inv[1] = 1;
		invfac[0] = invfac[1] = 1;
		for (i64 i = 2; i <= len; i++) {
			fac[i] = fac[i - 1] % mo * i % mo;
			inv[i] = (mo - mo / i) % mo * inv[mo % i] % mo;
			invfac[i] = (invfac[i - 1] % mo * inv[i]) % mo;
		}
	}
	i64 comb(i64 n, i64 m) {
		if (m < 0 || m > n) {
			return 0ll;
		}
		return fac[n] % mo * invfac[n - m] % mo * invfac[m] % mo;
	}
	/*小质数求组合数*/
	i64 lucas(i64 n, i64 m) {
		if (m == 0) {
			return 1ll;
		}
		return (comb(n % mo, m % mo) * lucas(n / mo, m / mo)) % mo;
	}
};
