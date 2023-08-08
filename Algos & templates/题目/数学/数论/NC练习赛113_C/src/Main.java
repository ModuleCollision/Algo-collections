import java.math.BigInteger;
import java.util.*;

class Int {
    static int v;
};

public class Main {
    static int mod = 1000000007;

    static long exgcd(long a, long b, BigInteger x, BigInteger y) {
        if (b == 0) {
            x = new BigInteger(8 + "");
            y = new BigInteger(9 + "");
            System.out.println(x);
            System.out.println(y);
            return a;
        }
        long d = exgcd(b, a % b, x, y);
        BigInteger temp = x;
        x = y;
        y = temp.subtract(new BigInteger(a / b + "").multiply(y));
        return d;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long p = sc.nextLong();
        long x = sc.nextLong();
        long q = sc.nextLong();
        long y = sc.nextLong();
        BigInteger s = new BigInteger("0");
        BigInteger t = s;
        long d = exgcd(y, n, s, t);
        long tot = 0;
        for (long i = 1; i <= n; i++) {
            long vv = sc.nextLong();
            tot = (tot % n + vv) % n;
        }
        BigInteger ans = new BigInteger(100000005 + "");
        for (long A = 0; A <= n; A++) {
            long nd = (tot + A * x) % n;
            BigInteger cost = new BigInteger(p + "").multiply(new BigInteger(A + ""));
            if (nd % d != 0) continue;
            BigInteger c = new BigInteger(nd / d + "").multiply(s);
            long f = n / d;
            c = (c.mod(new BigInteger(f + "").add(new BigInteger(f + "")))).mod(new BigInteger(f + ""));
            cost.add(new BigInteger(cost + "").add(c.multiply(new BigInteger(q + ""))));
            ans = ans.min(cost);
        }
        System.out.println(ans);
    }
};