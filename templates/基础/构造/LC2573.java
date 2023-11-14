class Solution {
    public String findTheString(int[][] lcp) {
        int i = 0, n = lcp.length;
        var s = new char[n];
        for (char c = 'a'; c <= 'z'; c++) {
            while (i < n && s[i] > 0) i++;
            if (i == n) break;
            for (int j = i; j < n; j++) if (lcp[i][j] > 0) s[j] = c;
        }
        while (i < n) if (s[i++] == 0) return "";
        var lc = new int[n + 1][n + 1];
        for (i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) lc[i][j] = lc[i + 1][j + 1] + 1;
                else lc[i][j] = 0;
                if (lc[i][j] != lcp[i][j]) return "";
            }
        }
        return new String(s);
    }
};