i64 exgcd(i64 a, i64 b, i64 & x, i64 & y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	i64 d = exgcd(b, a % b, x, y);
	i64 temp = x; x = y;
	y = temp - a / b * y;
	return d;
}