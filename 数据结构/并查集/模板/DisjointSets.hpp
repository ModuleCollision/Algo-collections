struct DisjoinSets {

	std::vector<i64>f, v;

	DisjoinSets() {}

	DisjoinSets(int n)f(n + 1), v(n + 1) {}

	void init(int n) {
		f.assign(n + 1, 0);
		v.assign(n + 1, 0);
		std::iota(f.begin() + 1, f.begin() + 1 + n, 1);
		v.assign(n, 1);
	}
	int find(int x) {
		while (x != fa[x]) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return false;
		v[x] += v[y];
		f[y] = x;
		return true;
	}
	int size(int x) {
		return v[find(x)];
	}
};