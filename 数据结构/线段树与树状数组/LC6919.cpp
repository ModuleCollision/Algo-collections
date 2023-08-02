class Solution {
public:
  bool checkArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int>tr(n + 5, 0);
    vector<int>A(n + 5);
    for (int i = 1; i <= n; i++)A[i] = nums[i - 1];
    auto add = [&](int idx, int v) {
      for (; idx <= n; idx += (idx & -idx)) {
        tr[idx] += v;
      }
    };
    auto query = [&](int idx) {
      int ret = 0;
      for (; idx >= 1; idx -= (idx & -idx)) {
        ret += tr[idx];
      }
      return ret;
    };
    for (int i = 1; i <= n; i++) {
      add(i, A[i] - A[i - 1]);
    }
    int i = 1;
    while (i <= n) {
      int l = i;
      int r = i + k - 1; if (r > n)return false;
      int d = query(i);
      add(l, -d); add(r + 1, d);
      while (query(i) <= 0 and i <= n) {
        if (query(i) < 0)return false;
        i++;
      }
    }
    return true;
  }
};