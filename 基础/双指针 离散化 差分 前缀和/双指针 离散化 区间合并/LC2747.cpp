class Solution {
public:
  vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
    int m = queries.size();
    vector<int>ret(m);
    vector<pair<int, int>>q;
    for (int i = 0; i < m; i++) {
      q.push_back({i, queries[i]});
    }
    sort(q.begin(), q.end(), [&](auto s, auto t)->bool{
      return s.second < t.second;
    });
    sort(logs.begin(), logs.end(), [&](auto s, auto t)->bool{
      return s[1] < t[1];
    });
    int l = 0, r = 0;
    int cur = n; std::unordered_map<int, int>cnt;
    for (int i = 0; i < m; i++) {
      while (r < logs.size() and logs[r][1] <= q[i].second) {
        cnt[logs[r][0]]++;
        if (cnt[logs[r][0]] == 1)cur--;
        r++;
      }
      while (l < logs.size() and logs[l][1] < q[i].second - x) {
        --cnt[logs[l][0]];
        if (cnt[logs[l][0]] == 0)cur++;
        l++;
      }
      ret[q[i].first] = cur;
    }
    return ret;
  }
};