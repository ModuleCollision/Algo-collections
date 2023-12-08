
template<typename T>
struct SegmentTree {

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
