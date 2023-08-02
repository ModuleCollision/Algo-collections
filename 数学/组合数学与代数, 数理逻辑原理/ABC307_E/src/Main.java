import java.util.*;

public class Main {
    static long dp[][] = new long[1000005][2];
    static long mod = 998244353;

    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        dp[1][1] = (long) m;
        dp[1][0] = (long) 0;
        for (int i = 2; i <= n; i++) {
            dp[i][1] = (dp[i - 1][0]) % mod;
            dp[i][0] = (dp[i - 1][0] % mod * (m - 2) % mod + dp[i - 1][1] % mod * (m - 1) % mod) % mod;
        }
        System.out.print((dp[n][0]) % mod);
    }
};