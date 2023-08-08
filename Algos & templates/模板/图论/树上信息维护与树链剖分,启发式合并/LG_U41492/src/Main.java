/*树上启发式合并*/
import java.util.*;

public class Main {
    static int maxn = 200005, n;
    static int[] sz = new int[maxn], big = new int[maxn], col = new int[maxn], L = new int[maxn], R = new int[maxn];
    static int totdfn = 0, totcolor = 0;
    static int[] Node = new int[maxn], ans = new int[maxn], cnt = new int[maxn];
    static ArrayList<ArrayList<Integer>> tr;

    //全局变量用static,不可用var,指明变量类型
    static void add(int u) {
        if (cnt[col[u]] == 0) ++totcolor;
        cnt[col[u]]++;
    }

    static void del(int u) {
        cnt[col[u]]--;
        if (cnt[col[u]] == 0) totcolor--;
    }

    static void dfs1(int u, int p) {
        L[u] = ++totdfn;
        Node[totdfn] = u;
        sz[u] = 1;
        for (var v : tr.get(u)) {
            if (v != p) {
                dfs1(v, u);
                sz[u] += sz[v];
                if (big[u] == 0 || sz[big[u]] < sz[v]) {
                    big[u] = v;
                }
            }
        }
        R[u] = totdfn;
    }

    static void dfs2(int u, int p, boolean keep) {
        for (var v : tr.get(u)) {
            if (v != p && v != big[u]) {
                dfs2(v, u, false);
            }
        }
        if (big[u] != 0) {
            dfs2(big[u], u, true);
        }
        for (var v : tr.get(u)) {
            if (v != p && v != big[u]) {
                for (int i = L[v]; i <= R[v]; i++) {
                    add(Node[i]);
                }
            }
        }
        add(u);
        ans[u] = totcolor;
        if (!keep) {
            for (int i = L[u]; i <= R[u]; i++) {
                del(Node[i]);
            }
        }
    }

    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        n = sc.nextInt();
        tr = new ArrayList<>();//指明tr类型后,template可以缺省
        for (int i = 1; i <= n + 1; i++) {
            tr.add(new ArrayList<>());
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            u = sc.nextInt();
            v = sc.nextInt();
            tr.get(u).add(v);
            tr.get(v).add(u);
        }
        for (int i = 1; i <= n; i++) col[i] = sc.nextInt();
        var m = sc.nextInt();

        dfs1(1, 0);
        dfs2(1, 0, false);
        for (int i = 1; i <= m; i++) {
            var q = sc.nextInt();
            System.out.println(ans[q]);
        }
    }
};