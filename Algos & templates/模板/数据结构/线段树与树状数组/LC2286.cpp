struct sq {
    int l; int r; int sum; int mn;
};
//单点修改 + 二分
class BookMyShow {

    vector<sq>tr; int n; int m;
    void pushup(int p) {
        tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
        tr[p].mn = min(tr[p << 1].mn, tr[p << 1 | 1].mn);
    }
    void build(int p, int l, int r) {
        tr[p].l = l; tr[p].r = r;
        if (l == r) {
            tr[p].sum = tr[p].mn = 0;
            return;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }
    void add(int p, int idx, int val) {
        if (tr[p].l == tr[p].r) {
            tr[p].sum += val;
            tr[p].mn += val;
            return;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (idx <= mid) {
            add(p << 1, idx, val);
        } else if (idx > mid) {
            add(p << 1 | 1, idx, val);
        }
        pushup(p);
    }
    int query(int p, int l, int r) {
        if (tr[p].l >= l and tr[p].r <= r) {
            return tr[p].sum;
        }
        int ret = 0;
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) {
            ret += query(p << 1, l, r);
        }
        if (r > mid)ret += query(p << 1 | 1, l, r);
        return ret;
    }
    int ind(int p, int r, int val) {
        if (tr[p].mn > val)return 0;
        if (tr[p].l == tr[p].r) {
            return tr[p].l;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (tr[p << 1].mn <= val) {
            return ind(p << 1, r, val);
        }
        if (mid < r) {
            return ind(p << 1 | 1, r, val);
        }
        return 0;
    }
public:
    BookMyShow(int n, int m) {
        this->n = n; this->m = m;
        tr.resize(n * 4 + 5);
        build(1, 1, n);
    }

    vector<int> gather(int k, int maxRow) {
        int i = ind(1, maxRow + 1, m - k);
        if (not i) {
            return vector<int>();
        }
        int seats(query(1, i, i));
        add(1, i, k);
        return{i - 1, seats};
    }
    bool scatter(int k, int maxRow) {
        if ((maxRow + 1)*m - query(1, 1, maxRow + 1) < k) {
            return false;
        }
        for (int i = ind(1, maxRow + 1, m - 1);; i++) {
            int left_seats = m - query(1, i, i);
            if (k <= left_seats) {
                add(1, i, k);
                return true;
            }
            k -= left_seats;
            add(1, i, left_seats);
        }
    }
};