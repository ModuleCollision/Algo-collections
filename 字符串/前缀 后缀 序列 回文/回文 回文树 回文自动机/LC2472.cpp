class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        std::vector is(n + 5, std::vector<bool>(n + 5, false));
        s = " " + s;
        for (int i = 0; i <= n; i++) {
            is[i][i] = 1;
            is[i + 1][i] = 1;
        }
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                if (s[l] == s[r]) {
                    is[l][r] = is[l][r] | is[l + 1][r - 1];
                }
            }
        }
        std::vector<int>dp(n + 1, -0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i], dp[i - 1]);
            if (i >= k) {
                for (int j = i - k; j >= 0; j--) {
                    if (is[j + 1][i]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n];
    }
};