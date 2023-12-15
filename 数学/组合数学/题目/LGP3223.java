import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    static BigInteger[] fac = new BigInteger[2005];

    public static void init() {
        Arrays.setAll(fac, e -> new BigInteger("" + 0));
        fac[0] = new BigInteger("1");
        for (var i = 1; i <= 2004; i++) {
            fac[i] = fac[i - 1].multiply(new BigInteger("" + i));
        }
    }

    private static BigInteger Arra(int n, int m) {
        if (m > n)
            return new BigInteger("" + 0);
        return fac[n].divide(fac[n - m]);
    }

    private static BigInteger Comb(int n, int m) {
        if (m > n)
            return new BigInteger("" + 0);
        return fac[n].divide(fac[n - m].multiply(fac[m]));
    }

    public static void main(String[] args) {
        var sc = new AReader();
        var n = sc.nextInt();
        var m = sc.nextInt();
        init();
        var ans1 = Arra(n + 2, n + 2).multiply(Arra(n + 3, m));
        var ans2 = Arra(2, 2).multiply(Arra(n + 1, n + 1)).multiply(Arra(n + 2, m));
        System.out.print(ans1.subtract(ans2));
    }

    static class AReader {
        private BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        private StringTokenizer tokenizer = new StringTokenizer("");

        private String innerNextLine() {
            try {
                return reader.readLine();
            } catch (IOException ex) {
                return null;
            }
        }

        public boolean hasNext() {
            while (!tokenizer.hasMoreTokens()) {
                String nextLine = innerNextLine();
                if (nextLine == null) {
                    return false;
                }
                tokenizer = new StringTokenizer(nextLine);
            }
            return true;
        }

        public String nextLine() {
            tokenizer = new StringTokenizer("");
            return innerNextLine();
        }

        public String next() {
            hasNext();
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public BigInteger nextBigInt() {
            return new BigInteger(next());
        }
    }

}
