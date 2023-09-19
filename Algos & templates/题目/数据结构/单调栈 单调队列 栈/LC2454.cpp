class Solution {
public:
  vector<int> secondGreaterElement(vector<int>& nums) {
    int n = nums.size(); vector<int>ans(n, -1), s, t;
    for (int i = 0; i < n; i++) {
      int x = nums[i];
      while (t.size() and nums[t.back()] < x) {
        ans[t.back()] = x;
        t.pop_back();
      }
      int j = (int)s.size() - 1;
      while (j >= 0 and nums[s[j]] < x)j--;
      t.insert(t.end(), s.begin() + (j + 1), s.end());//将第一单调栈出栈, 并插入第二单调栈
      s.resize(j + 1);
      s.push_back(i);
    }
    return ans;
  }
};