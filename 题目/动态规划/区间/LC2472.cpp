class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int kk[n + 5][n + 5];
        memset(kk, 0 , sizeof(kk));
        s = " " + s;
        for (int i = 0; i <= n; i++) {
            kk[i][i] = 1;
            kk[i + 1][i] = 1;
        }
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                if (s[l] == s[r]) {
                    kk[l][r] |= kk[l + 1][r - 1];
                }
            }
        }
        int dp[n + 5];
        memset(dp, -0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i], dp[i - 1]);
            if (i >= k) {
                for (int j = i - k; j >= 0; j--) {
                    if (kk[j + 1][i]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n];
    }
};