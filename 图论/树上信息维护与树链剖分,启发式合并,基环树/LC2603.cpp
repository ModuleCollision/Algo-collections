/*树上拓扑*/
class Solution {
public:
  int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
    int n = coins.size();
    vector<vector<int>>g(n + 1);
    vector<int>d(n + 1);
    for (auto e : edges) {
      int u = e[0], v = e[1]; u++; v++;
      g[u].push_back(v);
      g[v].push_back(u); d[u]++; d[v]++;
    }
    int ans = n - 1;
    vector<int>q;
    for (int i = 1; i <= n; i++) {
      if (d[i] == 1 and coins[i - 1] == 0)q.push_back(i);
    }
    while (q.size()) {
      ans--;
      int u = q.front(); q.erase(q.begin());
      for (auto v : g[u]) {
        --d[v];
        if (d[v] == 1 and coins[v - 1] == 0)q.push_back(v);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (d[i] == 1 and coins[i - 1])q.push_back(i);
    }
    ans -= q.size();
    for (int x : q) {
      for (auto v : g[x]) {
        if (--d[v] == 1) {
          ans--;
        }
      }
    }
    return  max(ans * 2, 0);
  }
};