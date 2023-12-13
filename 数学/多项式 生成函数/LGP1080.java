import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        AReader sc = new AReader();
        int n = sc.nextInt();
        BigInteger[][] w = new BigInteger[n + 2][];
        for (int i = 1; i <= n + 1; i++) {
            BigInteger a = sc.nextBigInt();
            BigInteger b = sc.nextBigInt();
            w[i] = new BigInteger[] { a, b };
        }
        Arrays.sort(w, 2, 2 + n, (x, y) -> {
            return x[0].multiply(x[1]).intValue() - y[0].multiply(y[1]).intValue();
        });
        BigInteger ans = new BigInteger("" + 0);
        BigInteger pre = w[1][0];
        for (int i = 2; i <= n + 1; i++) {
            BigInteger cur = pre.divide(w[i][1]);
            if (cur.compareTo(ans) > 0) {
                ans = cur;
            }
            pre = pre.multiply(w[i][0]);
        }
        System.out.print(ans);
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