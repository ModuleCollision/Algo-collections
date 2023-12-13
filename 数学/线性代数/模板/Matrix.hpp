struct Matrix {
public:
	i64 n; std::vector<std::vector<i64>>a;
	Matrix(i64 len = 4): n(len), a(len) {
		for (i64 i = 0; i < len; i++) {
			a[i].assign(len, 0);
		}
	}
	friend Matrix operator*(const Matrix x, const Matrix y) {
		i64 n = x.n;
		Matrix ret(n);
		for (i64 i = 0; i < n; i++) {
			for (i64 j = 0; j < n; j++) {
				for (i64 k = 0; k < n; k++) {
					ret.a[i][j] = (ret.a[i][j] % mod + x.a[i][k] % mod * y.a[k][j] % mod) % mod;
				}
			}
		}
		return ret;
	}
	friend Matrix quickPower(Matrix x, i64 y) {
		Matrix ret(x.n);
		for (i64 i = 0; i < x.n; i++)ret.a[i][i] = 1;
		while (y) {
			if (y & 1)ret = ret * x;
			x = x * x;
			y >>= 1;
		}
		return ret;
	};
};