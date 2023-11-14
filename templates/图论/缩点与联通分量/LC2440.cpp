class Solution {
public:
  int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
    int n = nums.size();
    vector<vector<int>>tr(n + 1);
    for (auto c : edges) {
      int u = c[0], v = c[1]; u++; v++;
      tr[u].push_back(v); tr[v].push_back(u);
    }
    int target;
    function<int(int, int)>dfs = [&](int u, int f) {
      int cur = nums[u - 1];
      for (auto v : tr[u]) {
        if (v == f)continue;
        int res = dfs(v, u);
        if (res == -1)return -1;
        cur += res;
      }
      if (cur > target)return -1;
      else if (cur == target) return 0;
      else return cur;
    };
    int tot = accumulate(nums.begin(), nums.end(), 0);
    int mx = *max_element(nums.begin(), nums.end());
    for (int i = tot / mx; ; i--) { //枚举分割数
      if (tot % i == 0) {
        target = tot / i;
        if (dfs(1, 0) == 0)return i - 1;
      }
    }
  }
};