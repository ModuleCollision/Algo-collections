/*无向图带权并查集*/
struct DisjoinSet {

public:
	std::vector<i64>f, v;

	DisjoinSet() {}

	DisjoinSet(int n) {init(n);}

	void init(int n) {
		f.assign(n + 1, 0);
		v.assign(n + 1, 1);
		std::iota(f.begin() + 1, f.begin() + 1 + n, 1);
	}
	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
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


/*有向图带权并查集*/
struct DisjoinSet {

public:
	std::vector<i64>f, v;

	DisjoinSet() {}

	DisjoinSet(int n) {init(n);}

	void init(int n) {
		f.assign(n + 1, 0);
		v.assign(n + 1, 0);
		std::iota(f.begin() + 1, f.begin() + 1 + n, 1);
	}
	int find(int x) {
		if (x != f[x]) {
			i64 tmp = find(f[x]);
			v[x] += v[f[x]];
			f[x] = tmp;
			return f[x];
		}
		return x;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	bool merge(int a, int b, int s) {
		i64 ta = find(a), tb = find(b);
		if (ta != tb) {
			f[ta] = tb;
			v[ta] = v[b] - v[a] + s; return true;
		} else if (v[a] - s == v[b]) {
			return true;
		} else {
			return false;
		}
	}
	int size(int x) {
		return v[find(x)];
	}
};