class Solution {
public:
    typedef long long ll;
    const ll inf = 1e15;
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector dp(n + 5, vector<ll>(15, inf));
        for (int j = 1; j < 8; j++) {
            dp[2][j] = 0;
            for (ll s = 0; s < 3; s++)if ((j >> s) & 1)dp[2][j] += max(0ll, (ll)k - nums[s]);
        }
        for (int i = 3; i < n; i++) {
            for (int j = 1; j < 8; j++) {
                for (int q = 1; q < 8; q++) {
                    ll tmp = dp[i - 1][q];
                    for (int s = 0; s < 3; s++) {
                        if ((((j >> s) & 1) == 1) and (((q >> (s + 1)) & 1) == 0)) {
                            tmp += max(0ll, k - (ll)nums[i - 2 + s]);
                        }
                    }
                    dp[i][j] = min(dp[i][j], tmp);
                }
            }
        }
        ll ans = inf;
        for (ll j = 1; j < 8; j++)ans = min(ans, dp[n - 1][j]);
        return ans;
    }
};