typedef long long ll;
class Solution {
public:
  
  long long countPalindromePaths(vector<int>& parent, string s) {
    std::map<ll, int>cnt;
    std::vector<vector<pair<int, char>>>tr(parent.size() + 5);
    for (int i = 1; i < parent.size(); i++) {
      tr[i].push_back({parent[i], s[i]});
      tr[parent[i]].push_back({i, s[i]});
    }
    ll res = 0;
    function<void(int, int, ll)>dfs = [&](int u, int f, ll cur) {
      res += cnt[cur];
      for (int i = 0; i < 26; i++) {
        res += cnt[cur ^ (1 << i)];
      }
      cnt[cur]++;
      for (auto [v, c] : tr[u]) {
        if (v == f)continue;
        ll fs = cur ^ (1ll << (c - 'a'));
        dfs(v, u, fs);
      }
    };
    dfs(0, -1, 0ll);
    return res;
  }
};