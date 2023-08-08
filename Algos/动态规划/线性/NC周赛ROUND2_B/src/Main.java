import java.math.BigInteger;
import java.util.*;

class Int {
    static int v;
};

public class Main {
    static int mod = 1000000007;
    static int maxn = 100005;
    static int inf = 0x3f3f3f3f;
    static int[] a = new int[maxn];
    static int[][] dp = new int[maxn][2];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }
        String s = sc.next();
        s = " " + s;
        dp[0][0] = dp[0][1] = 0;
        if (n == 1) {
            System.out.println(0);
            return;
        }
        dp[1][0] = dp[1][1] = 0;

        for (int i = 2; i <= n; i++) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                dp[i][1] = Math.max(dp[i][1], dp[i - 2][0] + a[i] + a[i - 1]);
                dp[i][1] = Math.max(dp[i][1], dp[i - 2][1] + a[i] + a[i - 1]);
            }
            dp[i][0] = Math.max(dp[i][0], dp[i - 1][1]);
            dp[i][0] = Math.max(dp[i][0], dp[i - 1][0]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = Math.max(dp[i][0], ans);
            ans = Math.max(dp[i][1], ans);
        }
        System.out.println(ans);
    }
};