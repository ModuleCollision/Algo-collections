class Solution {
    static long mod = 1000000007;

    public int peopleAwareOfSecret(int n, int delay, int forget) {
        var dp1 = new long[n + 2];
        var dp2 = new long[n + 2];
        var dp3 = new long[n + 2];
        dp1[1] = 1l;//生利息的钱数
        dp2[1 + forget] = 1l;//将拿掉忘记的钱数
        dp3[1 + delay] = 1l;//将要增添的钱数
        for (var i = 2; i <= n; i++) {
            dp1[i] = ((dp1[i - 1] - dp2[i]) % mod + dp3[i] + mod) % mod;
            if (i + forget <= n) dp2[i + forget] += dp3[i] % mod;
            if (i + delay <= n) {
                dp3[i + delay] = ((dp3[i + delay - 1] - dp2[i + delay]) % mod + dp3[i] + mod) % mod;
            }
        }
        int ret = (int)dp1[n] % (int)mod; return ret;
    }
};