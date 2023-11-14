struct sq {
  int idx, r2l, l2r;
};
struct cmp {
  bool operator()(const sq&a, const sq&b)const {
    if (a.r2l + a.l2r != b.r2l + b.l2r) {
      return a.r2l + a.l2r < b.r2l + b.l2r;
    }
    return a.idx < b.idx;
  }
};
class Solution {
public:
  int findCrossingTime(int n, int k, vector<vector<int>>& time) {
    priority_queue<sq, vector<sq>, cmp>ql, qr; //等待过桥的
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>sl, sr;//还在工作的
    for (int i = 0; i < k; i++) {
      ql.push({i, time[i][0], time[i][2]});
    }
    int cur = 0;
    while (n) {
      while (sl.size() and sl.top().first <= cur) {
        auto [_, idx] = sl.top(); sl.pop();
        ql.push({idx, time[idx][0], time[idx][2]});
      }
      while (sr.size() and sr.top().first <= cur) {
        auto [_, idx] = sr.top(); sr.pop();
        qr.push({idx, time[idx][0], time[idx][2]});
      }
      if (qr.size()) {
        auto [idx, r2l, l2r] = qr.top();
        qr.pop();
        cur += r2l; sl.push({cur + time[idx][3], idx});
      } else if (ql.size()) {
        auto [idx, r2l, l2r] = ql.top(); ql.pop();
        cur += l2r; sr.push({cur + time[idx][1], idx});
        n--;
      } else {
        if (not sl.size())cur = sr.top().first;
        else if (not sr.size())cur = sl.top().first;
        else cur = min(sl.top().first, sr.top().first);
      }
    }
    while (sr.size()) {
      auto [t, idx] = sr.top(); sr.pop();
      cur = max(t, cur) + time[idx][2];
    }
    return cur;
  }
};