
template<typename T>
struct SegmentTree {
    /*单懒标记线段树*/
public:

    struct Node {
        int l; int r; T sum; T add;
    };

    std::vector<Node>tr; int n;

    SegmentTree(int n): tr(4 * n + 4), n(n) {}

    void pushUp(int p) {
        tr[p].sum = (tr[p << 1].sum + tr[p << 1 | 1].sum);
    }

    void build(int p, int l, int r, std::vector<T>&a) {
        tr[p].l = l; tr[p].r = r;
        if (l == r) {
            tr[p].sum = a[l]; tr[p].add = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, a);
        build(p << 1 | 1, mid + 1, r, a);
        pushUp(p);
    }

    void pushDown(int p) {
        int l = tr[p].l, r = tr[p].r;
        int mid = (l + r) >> 1;
        T add = tr[p].add;
        tr[p << 1].sum += add * (mid - l + 1);
        tr[p << 1 | 1].sum += add * (r - mid);
        tr[p << 1].add += add;
        tr[p << 1 | 1].add += add;
        tr[p].add = 0;
    }

    void modify(int p, int l, int r, T val) {
        if (tr[p].l >= l and tr[p].r <= r) {
            tr[p].sum += (tr[p].r - tr[p].l + 1) * val;
            tr[p].add = (tr[p].add + val);
            return;
        }
        pushDown(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (r > mid) {
            modify(p << 1 | 1, l, r, val);
        }
        if (l <= mid) {
            modify(p << 1, l, r, val);
        }
        pushUp(p);
    }

    T query(int p, int l, int r) {
        if (tr[p].l >= l and tr[p].r <= r) {
            return tr[p].sum;
        }
        pushDown(p);
        T ret = 0; int mid = (tr[p].l + tr[p].r) >> 1;
        if (r > mid) {
            ret = (ret + query(p << 1 | 1, l, r));
        }
        if (l <= mid) {
            ret = (ret + query(p << 1, l, r));
        }
        return ret;
    }

};






template<typename T>
struct SegmentTree {
    /*双懒标记线段树*/
public:

    struct Node {
        int l; int r; T mx; T add;
        T c;
    };

    std::vector<Node>tr; int n;

    SegmentTree(int n): tr(4 * n + 10), n(n) {}

    void pushUp(int p) {
        tr[p].mx = std::max(tr[p << 1].mx, tr[p << 1 | 1].mx);
    }

    void build(int p, int l, int r, std::vector<T>&a) {
        tr[p].l = l; tr[p].r = r; tr[p].c = -inf;
        if (l == r) {
            tr[p].mx = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, a);
        build(p << 1 | 1, mid + 1, r, a);
        pushUp(p);
    }

    void pushDown(int p) {
        if (tr[p].c != -inf) {
            T c = tr[p].c; tr[p].c = -inf;
            tr[p << 1].mx = c; tr[p << 1 | 1].mx = c;
            tr[p << 1].add = 0; tr[p << 1 | 1].add = 0;
            tr[p << 1].c = c; tr[p << 1 | 1].c = c;
        }
        if (tr[p].add) {
            T add = tr[p].add; tr[p].add = 0;
            tr[p << 1].add += add; tr[p << 1 | 1].add += add;
            tr[p << 1].mx += add; tr[p << 1 | 1].mx += add;
        }
    }

    void modify1(int p, int l, int r, T val) { // 修改为 x
        if (tr[p].l >= l and tr[p].r <= r) {
            tr[p].mx = val; tr[p].add = 0;
            tr[p].c = val;
            return;
        }
        pushDown(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (r > mid) {
            modify1(p << 1 | 1, l, r, val);
        }
        if (l <= mid) {
            modify1(p << 1, l, r, val);
        }
        pushUp(p);
    }

    void modify2(int p, int l, int r, T val) { // 修改为 x
        if (tr[p].l >= l and tr[p].r <= r) {
            tr[p].mx += val; tr[p].add += val;
            return;
        }
        pushDown(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (r > mid) {
            modify2(p << 1 | 1, l, r, val);
        }
        if (l <= mid) {
            modify2(p << 1, l, r, val);
        }
        pushUp(p);
    }


    T query(int p, int l, int r) {
        if (tr[p].l >= l and tr[p].r <= r) {
            return tr[p].mx;
        }
        pushDown(p);
        T ret = 0; int mid = (tr[p].l + tr[p].r) >> 1;
        if (r > mid) {
            ret = std::max(ret, query(p << 1 | 1, l, r));
        }
        if (l <= mid) {
            ret = std::max(ret, query(p << 1, l, r));
        }
        return ret;
    }

};




template<typename T>
struct SegmentTree {
    /*动态开点线段树*/
public:

    struct Node {
        i64 l, r; // 所维护的区间范围
        i64 ls, rs;// 左右孩子
        T mul, add, sum;
    };

    std::vector<Node>tr; i64 n; i64 tot = 1;

    SegmentTree(int n): tr(2 * n + 1), n(n) {tr[1].l = 1; tr[1].r = n; tr[1].mul = 1;}

    void pushUp(i64 p) {
        tr[p].sum = (tr[tr[p].ls].sum % m + tr[tr[p].rs].sum) % m;
        return;
    }
    void pushDown(i64 p) {
        i64 mid = (tr[p].l + tr[p].r) >> 1;
        if (not tr[p].ls) {
            tr[p].ls = ++tot;
            tr[tot].l = tr[p].l;
            tr[tot].r = mid;
            tr[tr[p].ls].mul = 1;
        }
        if (not tr[p].rs) {
            tr[p].rs = ++tot;
            tr[tot].l = mid + 1;
            tr[tot].r = tr[p].r;
            tr[tr[p].rs].mul = 1;
        }
        if (tr[p].mul != 1) {
            T mu = tr[p].mul;
            tr[p].mul = 1;
            tr[tr[p].ls].mul = tr[tr[p].ls].mul * mu % m;
            tr[tr[p].rs].mul = (tr[tr[p].rs].mul * mu % m);
            tr[tr[p].ls].sum = (tr[tr[p].ls].sum % m * mu) % m;
            tr[tr[p].rs].sum = (tr[tr[p].rs].sum % m * mu) % m;
            tr[tr[p].ls].add = (tr[tr[p].ls].add % m * mu) % m;
            tr[tr[p].rs].add = (tr[tr[p].rs].add % m * mu) % m;
        }
        if (tr[p].add) {
            T ad = tr[p].add;
            tr[p].add = 0;
            tr[tr[p].ls].add = (tr[tr[p].ls].add + ad) % m;
            tr[tr[p].rs].add = (tr[tr[p].rs].add + ad) % m;
            i64 mid = (tr[p].l + tr[p].r) >> 1;
            i64 len1 = mid - tr[p].l + 1; i64 len2 = tr[p].r - mid;
            tr[tr[p].ls].sum = (tr[tr[p].ls].sum % m + len1 % m * ad) % m;
            tr[tr[p].rs].sum = (tr[tr[p].rs].sum % m + len2 % m * ad) % m;
        }
    }
    void modify1(i64 p, i64 l, i64 r, T v) {
        if (tr[p].l >= l and tr[p].r <= r) {
            tr[p].mul = (tr[p].mul % m * v) % m;
            tr[p].add = (tr[p].add % m * v) % m;
            tr[p].sum = (tr[p].sum % m * v) % m;
            return;
        }
        pushDown(p);
        i64 mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid)modify1(tr[p].ls, l, r, v);
        if (r > mid)modify1(tr[p].rs, l, r, v);
        pushUp(p);
    }

    void modify2(i64 p, i64 l, i64 r, T v) {
        if (tr[p].l >= l and tr[p].r <= r) {
            tr[p].add = (tr[p].add % m + v) % m;
            tr[p].sum = (tr[p].sum + (tr[p].r - tr[p].l + 1) % m * v) % m;
            return;
        }
        pushDown(p);
        i64 mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid)modify2(tr[p].ls, l, r, v);
        if (r > mid)modify2(tr[p].rs, l, r, v);
        pushUp(p);
    }

    T query(i64 u, i64 l, i64 r) {
        if (tr[u].l >= l and tr[u].r <= r) {
            return tr[u].sum % m;
        }
        pushDown(u);
        T ret = 0;
        i64 mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid)ret = (ret % m + query(tr[u].ls, l, r)) % m;
        if (r > mid)ret = (ret % m + query(tr[u].rs, l, r)) % m;
        return ret % m;
    }

};