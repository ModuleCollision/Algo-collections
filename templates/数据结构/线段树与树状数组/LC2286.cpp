//单点修改 + 二分
class BookMyShow {
    int n; int m;
    vector<int>mn;
    vector<long>sum;
    void pushup(int p) {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
        mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
    }
    void add(int p, int l, int r, int idx, int val) {
        if (l == r) {
            sum[p] += val;
            mn[p] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) {
            add(p << 1, l, mid, idx, val);
        } else if (idx > mid) {
            add(p << 1 | 1, mid + 1, r, idx, val);
        }
        pushup(p);
    }
    long query(int p, int l, int r, int L, int R) {
        if (l >= L and r <= R)return sum[p];
        long sum = 0;
        int mid = (l + r) >> 1;
        if (L <= mid) {
            sum += query(p << 1, l, mid, L, R);
        }
        if (R > mid)sum += query(p << 1 | 1, mid + 1, r, L, R);
        return sum;
    }
    /*返回某范围内 <= val元素的最靠左的位置*/
    int ind(int p, int l, int r, int L, int R, int val) {
        if (l == r) {
            if (mn[p] > val) return 0;
            return l;
        }
        int mid = (l + r) >> 1;
        int k1 = 0, k2 = 0;
        if (L <= mid and mn[p << 1] <= val) {
            k1 = ind(p << 1, l, mid, L, R, val);
        }
        if (k1)return k1;
        if (R > mid and mn[p << 1 | 1] <= val) {
            k2 = ind(p << 1 | 1, mid + 1, r, L, R, val);
        }
        if (k2)return k2;
        return 0;
    }
public:

    BookMyShow(int n, int m) : n(n), m(m), mn(n * 4, 0), sum(n * 4, 0) {
    }
    vector<int> gather(int k, int maxRow) {
        int i = ind(1, 1, n, 1, maxRow + 1, m - k);
        if (i == 0) {
            return {};
        }
        int seats = (query(1, 1, n, i, i));
        add(1, 1, n, i, k);
        return{i - 1, seats};
    }
    bool scatter(int k, int maxRow) {
        if ((long)(maxRow + 1) * m - query(1, 1, n, 1, maxRow + 1) < k) {
            return false;
        }
        for (int i = ind(1, 1, n, 1, maxRow + 1, m - 1);; i++) {
            int left_seats = m - query(1, 1, n, i, i);
            if (k <= left_seats) {
                add(1, 1, n, i, k);
                return true;
            }
            k -= left_seats;
            add(1, 1, n, i, left_seats);
        }
    }
};