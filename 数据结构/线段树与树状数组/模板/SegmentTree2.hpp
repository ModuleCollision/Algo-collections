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