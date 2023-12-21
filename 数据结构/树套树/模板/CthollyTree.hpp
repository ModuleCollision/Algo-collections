class CthollyTree {
public:
  struct Node {
    i64 l, r; mutable i64 val;
    bool operator<(const Node &t)const {
      return l < t.l;
    }
  };
  std::set<Node>st;
  CthollyTree() {}
  std::set<Node>::iterator split(i64 w) {
    auto it = st.lower_bound({w, 0, 0});
    if (it != st.end() and it->l == w)return it;
    it--;
    i64 l = it->l, r = it->r, v = it->val;
    st.erase(it);
    st.insert({l, w - 1, v});
    st.insert({w, r, v});
    return st.lower_bound({w, 0, 0});
  }
  void build(i64 n, std::vector<i64>a) {
    for (i64 i = 1; i <= n; i++) {
      st.insert({i, i, a[i]});
    }
  }
  void update1(i64 l, i64 r, i64 w) {
    auto y = split(r + 1), x = split(l);
    st.erase(x, y);
    st.insert({l, r, w});
  }
// 区间修改
  void update2(i64 l, i64 r, i64 w) {
    auto y = split(r + 1);
    for (auto it = split(l); it != y; it++) {
      (it->val) += w;
    }
  }
  i64 kth(i64 l, i64 r, i64 w) {
    auto y = split(r + 1);
    std::vector<std::pair<i64, i64>>p;
    for (auto it = split(l); it != y; it++) {
      p.push_back({it->val, it->r - it->l + 1});
    }
    std::sort(p.begin(), p.end());
    for (auto [s, t] : p) {
      w -= t;
      if (w <= 0) {
        return s;
      }

    }
    return 0;
  }
  i64 querySum(i64 l, i64 r, i64 w, i64 m) {
    auto y = split(r + 1);
    i64 ret = 0;
    for (auto it = split(l); it != y; it++) {
      i64 u1 = (it->r - it->l + 1);
      i64 u2 = qpow(it->val, w, m);
      ret += u1 % m * u2 % m;
      ret %= m;
    }
    return ret % m;
  }
};