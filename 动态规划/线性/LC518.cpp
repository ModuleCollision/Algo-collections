class Solution {
public:
    /*完全背包模板*/
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        /*注意！背包问题求得是组合数方案，若枚举次序相反则为排列数*/
        for (int& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};