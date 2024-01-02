template<typename T>
struct FenwickTree {

public:
    std::vector<T>tr; int n;

    FenwickTree(int n): tr(n + 5), n(n) {}

    FenwickTree() {}

    void init(int n) {
        this -> n = n; tr.assign(n + 5, 0);
    }

    T query(int idx) {
        T ret = 0;
        for (; idx > 0; idx -= (idx & -idx)) {
            ret += tr[idx];
        }
        return ret;
    }

    void modify(int idx, T v) {
        for (; idx <= this -> n; idx += (idx & -idx)) {
            tr[idx] += v;
        }
    }

    T queryRange(int l, int r) {
        return query(r) - query(l - 1);
    }
};