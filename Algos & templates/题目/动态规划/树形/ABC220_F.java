import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
    static int N;
    static ArrayList<Integer>[] tr;
    static int maxn = 200005;
    static int[] dp = new int[maxn];
    static int[] sz = new int[maxn];
    static int[] ans = new int[maxn];

    static void dfs(int u, int f) {
        sz[u] = 1;
        dp[u] = 0;
        for (int v : tr[u]) {
            if (v == f) continue;
            dfs(v, u);
            dp[u] += dp[v] + sz[v];
            sz[u] += sz[v];
        }
    }

    static void dfs2(int u, int f) {
        ans[u] = dp[u];
        for (int v : tr[u]) {
            if (v == f) continue;
            int szu = sz[u], szv = sz[v], dpu = dp[u], dpv = dp[v];
            dp[u] -= (dp[v] + sz[v]);
            sz[u] -= sz[v];
            sz[v] += sz[u];
            dp[v] += dp[u] + sz[u];
            dfs2(v, u);
            sz[u] = szu;
            sz[v] = szv;
            dp[u] = dpu;
            dp[v] = dpv;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        tr = new ArrayList[N + 5];
        Arrays.setAll(tr, e -> new ArrayList<>());
        for (int i = 0; i < N - 1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            tr[u].add(v);
            tr[v].add(u);
        }
        dfs(1, 0);
        dfs2(1, 0);
        for (int i = 1; i <= N; i++) {
            System.out.print(ans[i] + "\n");
        }
    }
};