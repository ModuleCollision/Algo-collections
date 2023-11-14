class Solution {
public:
    typedef long long ll;
    const ll inf = 0x3f3f3f3f3f3f3f3f;
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll>dp(n + 1, inf);
        for (int  i = 1; i <= n; i++) {
            if (i <= 3)dp[i] = max(0ll, k - (ll)nums[i - 1]);
            else {
                dp[i] = min({dp[i - 3], dp[i - 2], dp[i - 1]}) + max(0ll, k - (ll)nums[i - 1]);
            }
        }
        return min({dp[n - 1], dp[n], dp[n - 2]});
    }
};