class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int m = s.size();
        int dp[m + 1][1 << 10];
        memset(dp, -1, sizeof(dp));
        //是否收到 n 的限制, 前一位是否填了数
        function<int(int, int, bool, bool)>dfs = [&](int i, int sta, bool islimit, bool isnum) {
            if (i == m) {
                return (int)isnum;
            }
            if (dp[i][sta] != -1 and not islimit and isnum)return dp[i][sta];
            int res = 0;
            if (not isnum)res += dfs(i + 1, sta, false, false);
            int low = isnum ? 0 : 1;
            int up = islimit ? s[i] - '0' : 9;
            for (int d = low; d <= up; d++) {
                if (((sta >> d) & 1) == 0) {
                    int ret = dfs(i + 1, sta | (1 << d), islimit and d == up, true);
                    res += ret;
                }
            }
            if (not islimit and isnum)
                dp[i][sta] = res;
            return res;
        };
        return n - dfs(0, 0, true, false);
    }
};