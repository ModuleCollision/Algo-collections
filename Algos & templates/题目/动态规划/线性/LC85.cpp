class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        int len = max(n, m); vector dp1(len, vector<int>(len, 0)), dp2(len, vector<int>(len, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    if (i >= 1) {
                        dp1[i][j] = dp1[i - 1][j] + 1;
                    } else {
                        dp1[i][j] = 1;
                    }
                    if (j >= 1) {
                        dp2[i][j] = dp2[i][j - 1] + 1;
                    } else {
                        dp2[i][j] = 1;
                    }
                    int mr = 0x3f3f3f3f;
                    for (int k = i; k > i - dp1[i][j]; k--) {
                        mr = min(mr, dp2[k][j]);
                        ans = max(ans, (i - k + 1) * mr);
                    }
                } else {
                    dp1[i][j] = dp2[i][j] = 0;
                }
            }
        }
        return ans;
    }
};