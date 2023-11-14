class Solution {
public:
  typedef long long ll;
  const ll mod = 1e9 + 7;
  int maxSumMinProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int>q(4 * n + 5); int hed = 1, tal = 0;
    nums.insert(nums.begin(), 0);
    cout << nums[0] << endl;
    vector<int>lt(n + 1, 0), rt(n + 1, 0);
    for (int i = 1; i <= n; i++)lt[i] = 0;
    for (int i = 1; i <= n; i++)rt[i] = n + 1;
    for (int i = 1; i <= n; i++) {
      while (hed <= tal and nums[q[tal]] > nums[i]) {
        rt[q[tal]] = i;
        tal--;
      }
      q[++tal] = i;
    }
    hed = 1, tal = 0;
    for (int i = n; i >= 1; i--) {
      while (hed <= tal and nums[q[tal]] > nums[i]) {
        lt[q[tal]] = i;
        tal--;
      }
      q[++tal] = i;
    }
    ll ans = 0;
    vector<ll>pre(n + 1, 0);
    for (int i = 1; i <= n; i++)pre[i] = pre[i - 1] + nums[i];
    for (int i = 1; i <= n; i++) {
      ll cur = nums[i];
      ll d = pre[rt[i] - 1] - pre[lt[i]];
      cur *= d;
      ans = max(ans, cur);
    }
    ans %= mod;
    return int(ans);
  }
};