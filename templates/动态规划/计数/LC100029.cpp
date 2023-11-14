class Solution {
public:
  typedef long long ll;
  const ll mod = 1e9 + 7;
  int countSubMultisets(vector<int>& nums, int l, int r) {
    int n = nums.size(); ll tot = accumulate(nums.begin(), nums.end(), 0ll);
    vector<ll>dp(tot + 5, 0);
    std::unordered_map<ll, ll>cnt;
    for (auto x : nums)cnt[x]++;
    dp[0] = cnt[0] + 1;/*多重背包问题求方案数*/
    cnt.erase(0);
    for (auto [x, y] : cnt) {
      for (ll j = tot; j >= 0; j--) {
        for (int k = 1; k <= y and k * x <= j; k++) {
          dp[j] = (dp[j] % mod + dp[j - k * x]) % mod;
        }
      }
    }
    ll ans = 0;
    for (int i = l; i <= r; i++) {
      ans = (ans % mod + dp[i]) % mod;
    }
    return ans % mod;
  }
};


/*多重背包O(1)优化*/
class Solution {
public:
  typedef long long ll;
  const ll mod = 1e9 + 7;
  int countSubMultisets(vector<int>& nums, int l, int r) {
    int n = nums.size(); ll tot = accumulate(nums.begin(), nums.end(), 0ll);
    vector<ll>dp(tot + 5, 0);
    std::unordered_map<ll, ll>cnt;
    for (auto x : nums)cnt[x]++;
    dp[0] = cnt[0] + 1;/*多重背包问题求方案数*/
    cnt.erase(0); r = min(r, (int)tot); ll sum = 0;
    for (auto [x, y] : cnt) {
      auto ndp = dp;
      sum = min(sum + x * y, (ll)r);
      for (ll j = x; j <= sum; j++) {
        ndp[j] = (ndp[j] + ndp[j - x]) % mod;
        if (j >= (y + 1)*x) {
          ndp[j] = ((ndp[j] - dp[j - (y + 1) * x]) % mod + mod) % mod;
        }
      }
      dp = ndp;
    }
    ll ans = 0;
    for (int i = l; i <= r; i++) {
      ans = (ans % mod + dp[i]) % mod;
    }
    return ans % mod;
  }
};