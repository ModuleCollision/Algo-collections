

class Solution {
    char s[];
    int dp[][];

    public int numDupDigitsAtMostN(int n) {
        s = Integer.toString(n).toCharArray();
        int m = s.length;
        dp = new int[m][1 << 10];
        for (int i = 0; i < m; i++) {
            Arrays.fill(dp[i], -1);
        }
        return n - dfs(0, 0, true, false);
    }

    int dfs(int i, int msk, boolean isLimit, boolean isNum) {
        if (i == s.length)
            return isNum ? 1 : 0;
        if (!isLimit && isNum && dp[i][msk] != -1) {
            return dp[i][msk];
        }
        int res = 0;
        if (!isNum)
            res = dfs(i + 1, msk, false, false);
        int up = isLimit ? s[i] - '0' : 9;
        for (var d = isNum ? 0 : 1; d <= up; d++) {
            if ((msk >> d & 1) == 0) {
                res += dfs(i + 1, msk | (1 << d), isLimit && d == up, true);
            }
        }
        if (!isLimit && isNum) {
            dp[i][msk] = res;
        }
        return res;
    }
}