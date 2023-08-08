class Solution {
    static List<Integer>g;
    static int []dis;
    public static int bfs(int s) {
        int ans = Integer.MAX_VALUE;
        Arraays.fill(dis, -1);
        dis[s] = 0;
        var q = new ArrayDeque<int[]>();//java中没有pair类,强制转换为数组
        q.add(new int[] {s, -1});
        while (! q.isEmpty()) {
            var p = q.poll();
            int x = p[0], fa = p[1];
            for (var y : g[x]) {
                if (dis[y] < 0) {
                    dis[y] = dis[x] + 1;
                    q.add(new int[] {y, x});
                } else if (y != fa) {
                    ans = Math.min(ans, dis[x] + dis[y] + 1);
                }
            }
        }
    }

    public int findShortestCycle(int n, int[][] edges) {
        g = new ArrayList[n + 5];
        //Arrays.setAll(g, e->new ArrayList<>());
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<Integer>();
        }
        for (var e : edges) {
            int x = e[0], y = e[1];
            g[x].add(y);
            g[y].add(x);
        }
        dis = new int[n];
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            ans = Math.min(ans, bfs(i));
        }
        return ans < Integer.MAX_VALUE ? ans : -1;
    }
}