/*多组Test下使用封装数据结构, 在函数中开对象,避免暴力清空数组造成时间浪费*/

/*STL: 数据结构 cin cout function类 lowerbound builtin max min accumulate iota stoi atoi等函数需要加上std,避免命名空间污染*/

/*数学先打表, 后对拍, 图论只会暴力就bitset搞*/

/*300兆字节 1- 2 秒*/

#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
constexpr i64 mod = 998244353;
constexpr i64 maxn = 1e7 + 500;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


struct Matrix {
public:
	i64 n; std::vector<std::vector<i64>>a;
	Matrix(i64 len = 4): n(len), a(len) {
		for (i64 i = 0; i < len; i++) {
			a[i].assign(len, 0);
		}
	}
	void init() {
		for (i64 i = 0; i < n; i++) {
			for (i64 j = 0; j < n; j++) {
				if (i == j)a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
	}
	friend Matrix operator*(Matrix x, Matrix y) {
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
	friend Matrix operator+(Matrix x, Matrix y) {
		Matrix ret(x.n);
		for (i64 i = 0; i < x.n; i++) {
			for (i64 j = 0; j < y.n; j++) {
				ret.a[i][j] = (x.a[i][j] % mod + y.a[i][j]) % mod;
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


template<typename T>
struct SegmentTree {
	/*动态开点线段树*/
public:

	struct Node {
		i64 l, r; // 所维护的区间范围
		i64 ls, rs;// 左右孩子
		T mul, sum;
	};

	std::vector<Node>tr; i64 n; i64 tot = 1;

	SegmentTree(int n): tr(2 * n + 1), n(n) {tr[1].l = 1; tr[1].r = n; tr[1].mul.init();}

	void pushUp(i64 p) {
		tr[p].sum = tr[tr[p].ls].sum + tr[tr[p].rs].sum;
		return;
	}
	void pushDown(i64 p) {
		i64 mid = (tr[p].l + tr[p].r) >> 1;
		if (not tr[p].ls) {
			tr[p].ls = ++tot;
			tr[tot].l = tr[p].l;
			tr[tot].r = mid;
			tr[tr[p].ls].mul.init();
		}
		if (not tr[p].rs) {
			tr[p].rs = ++tot;
			tr[tot].l = mid + 1;
			tr[tot].r = tr[p].r;
			tr[tr[p].rs].mul.init();
		}
		T mu = tr[p].mul;
		tr[p].mul.init();
		tr[tr[p].ls].mul = mu * tr[tr[p].ls].mul;
		tr[tr[p].rs].mul = mu * tr[tr[p].rs].mul;
		tr[tr[p].ls].sum = mu * tr[tr[p].ls].sum ;
		tr[tr[p].rs].sum = mu * tr[tr[p].rs].sum;
	}
	void modify1(i64 p, i64 l, i64 r, T v) {
		if (tr[p].l >= l and tr[p].r <= r) {
			tr[p].mul = v * tr[p].mul;
			tr[p].sum = (v * tr[p].sum);
			return;
		}
		pushDown(p);
		i64 mid = (tr[p].l + tr[p].r) >> 1;
		if (l <= mid)modify1(tr[p].ls, l, r, v);
		if (r > mid)modify1(tr[p].rs, l, r, v);
		pushUp(p);
	}


	void modify2(int p, int idx, T val) { // 修改为 x
		if (tr[p].l == tr[p].r) {
			tr[p].sum = val + tr[p].sum;
			return;
		}
		pushDown(p);
		int mid = (tr[p].l + tr[p].r) >> 1;
		if (idx > mid) {
			modify2(tr[p].rs, idx, val);
		}
		else if (idx <= mid) {
			modify2(tr[p].ls, idx, val);
		}
		pushUp(p);
	}

	T query(i64 u, i64 l, i64 r) {
		if (tr[u].l >= l and tr[u].r <= r) {
			return tr[u].sum;
		}
		pushDown(u);
		T ret;
		i64 mid = (tr[u].l + tr[u].r) >> 1;
		if (l <= mid)ret = (ret + query(tr[u].ls, l, r));
		if (r > mid)ret = (ret + query(tr[u].rs, l, r));
		return ret;
	}
};

int main() {
	i64 n; std::cin >> n;
	SegmentTree<Matrix>tr(n);
	//std::cout << tr.tr[0].mul.a.size() << "\n";
	for (i64 i = 1; i <= n; i++) {
		Matrix w; for (i64 i = 0; i < 3; i++)std::cin >> w.a[i][0];
		w.a[3][0] = 1;
		tr.modify2(1, i, w);
	}
	i64 m; std::cin >> m;
	while (m--) {
		i64 opt; std::cin >> opt;
		if (opt == 1) {
			Matrix s;
			i64 l, r; std::cin >> l >> r;
			s.a = {{1, 1, 0, 0},
				{0, 1, 0, 0},
				{0, 0, 1, 0},
				{0, 0, 0, 1}
			};
			tr.modify1(1, l, r, s);
		} else if (opt == 2) {
			Matrix s;
			i64 l, r; std::cin >> l >> r;
			s.a = {{1, 0, 0, 0},
				{0, 1, 1, 0},
				{0, 0, 1, 0},
				{0, 0, 0, 1}
			};
			tr.modify1(1, l, r, s);
		} else if (opt == 3) {
			Matrix s;
			i64 l, r; std::cin >> l >> r;
			s.a = {{1, 0, 0, 0},
				{0, 1, 0, 0},
				{1, 0, 1, 0},
				{0, 0, 0, 1}
			};
			tr.modify1(1, l, r, s);
		} else if (opt == 4) {
			Matrix s; i64 l, r, v; std::cin >> l >> r >> v;
			s.a = {{1, 0, 0, v},
				{0, 1, 0, 0},
				{0, 0, 1, 0},
				{0, 0, 0, 1}
			};
			tr.modify1(1, l, r, s);
		} else if (opt == 5) {
			Matrix s; i64 l, r, v; std::cin >> l >> r >> v;
			s.a = {{1, 0, 0, 0},
				{0, v, 0, 0},
				{0, 0, 1, 0},
				{0, 0, 0, 1}
			};
			tr.modify1(1, l, r, s);
		} else if (opt == 6) {
			Matrix s; i64 l, r, v; std::cin >> l >> r >> v;
			s.a = {{1, 0, 0, 0},
				{0, 1, 0, 0},
				{0, 0, 0, v},
				{0, 0, 0, 1}
			};
			tr.modify1(1, l, r, s);
		} else {
			i64 l, r; std::cin >> l >> r;
			auto q = tr.query(1, l, r);
			for (i64 i = 0; i <= 2; i++) {
				std::cout << q.a[i][0] << " \n"[i == 2];
			}
		}
	}
}