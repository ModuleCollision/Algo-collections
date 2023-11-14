class Solution {
    private ArrayList<Integer>[] g;
    private int[] v;
    private int kk, ans = 0;

    private long dfs(int u, int f) {
        long cur = v[u];
        for (var t : g[u]) {
            if (t == f) {
                continue;
            }
            cur += dfs(t, u);
        }
        ans += cur % kk == 0 ? 1 : 0;
        return cur;
    }

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        g = new ArrayList[n + 5];
        Arrays.setAll(g, e -> new ArrayList<Integer>());

        for (var e : edges) {
            int u = e[0] + 1, v = e[1] + 1;
            g[u].add(v);
            g[v].add(u);
        }
        kk = k;
        v = new int[n + 5];
        for (int i = 1; i <= n; i++)
            v[i] = values[i - 1];
        dfs(1, 0);
        System.out.println(ans);
        return ans;
    }
};