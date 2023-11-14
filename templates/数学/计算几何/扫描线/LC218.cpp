/*扫描线 + 优先队列*/
class Solution {
public:
  struct cmp {
    bool operator()(const int&a, const int&b)const {
      return a > b;
    }
  }
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>>ret;
    vector<array<int, 2>>ps;
    for (auto w : buildings) {
      int l = w[0], r = w[1], h = w[2];
      ps.push_back({l, -h});
      ps.push_back({r, h});
    }
    sort(ps.begin(), ps.end(), [&](auto q, auto t)->bool{
      if (q[0] != t[0])return q[0] < t[0];
      return q[1] < t[1];
    });
    std::multiset<int, cmp>q;
    int pre = 0;
    q.insert(pre);
    for (auto [p, h] : ps) {
      if (h < 0) {
        q.insert(-h);
      } else {
        q.erase(q.find(h));
      }
      int cur = *q.begin();
      if (cur != pre) {
        vector<int>s;
        s.push_back(p); s.push_back(cur);
        ret.push_back(s);
        pre = cur;
      }
    }
    return ret;
  }
};