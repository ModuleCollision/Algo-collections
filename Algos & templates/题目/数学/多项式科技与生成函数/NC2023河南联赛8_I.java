import java.util.*;
import java.io.*;
import java.math.*;

public class Main {


    public static void main(String[] args) {
        AReader sc = new AReader();
        // 素性测试
        BigInteger a = sc.nextBigInt();
        BigInteger b = sc.nextBigInt();
        char[] str = new StringBuilder(a.multiply(b).toString()).reverse().toString().toCharArray();
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int l = sc.nextInt() - 1, r = sc.nextInt() - 1;
            long acc = 0;
            for (int j = r; j >= l; j--) {
                acc = acc * 10l + (str[j] - '0');
            }
            if (acc == 0 || acc == 1 || BigInteger.valueOf(acc).isProbablePrime(20)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
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
