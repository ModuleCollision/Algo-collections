struct Trie {
public:
  struct Node {
    std::array<i64, 2>to{0, 0}; i64 cnt = 0;
  };
  std::vector<Node>tr;
  Trie() {tr.push_back(Node());}
  void insert(i64 x) {
    i64 u = 0;
    for (i64 i = 20; i >= 0; i--) {
      i64 cur = (x >> i) & 1;
      if (not tr[u].to[cur]) {
        tr[u].to[cur] = tr.size();
        tr.push_back(Node());
      }
      u = tr[u].to[cur]; tr[u].cnt ++;
    }
  }
  void del(i64 x) {
    i64  u = 0;
    for (i64 i = 20; i >= 0; i --) {
      i64 cur = ((x >> i) & 1);
      u = tr[u].to[cur]; tr[u].cnt --;
    }
  }
  i64 query(i64 x) {
    i64 ans = 0, u = 0;
    for (i64 i = 20; i >= 0; i--) {
      i64 cur = (x >> i) & 1;
      if (tr[u].to[cur ^ 1] and tr[tr[u].to[cur ^ 1]].cnt) {
        ans |= (1 << i); u = tr[u].to[cur ^ 1];
      } else {
        u = tr[u].to[cur];
      }
    }
    return ans;
  }
};