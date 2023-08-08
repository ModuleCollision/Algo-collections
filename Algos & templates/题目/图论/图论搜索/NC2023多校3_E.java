import java.util.*;

public class Main {
    static ArrayList<ArrayList<Long>> g = new ArrayList<>();
    static boolean vis[] = new boolean[500005];
    static long dis[] = new long[500005];
    static long d[] = new long[500005];

    static void dfs(long u, long dep) {
        if (dis[(int) u] > dep) return;
        vis[(int) u] = true;
        dis[(int) u] = Math.max(dis[(int) u], dep);
        for (long v : g.get((int) u)) {
            if (vis[(int) v] == false) dfs(v, dep + 1);
        }
        vis[(int) u] = false;
    }
    public static void main(String []args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int w = 1; w <= t; w++) {
            g.clear();
            long n = sc.nextLong();
            long m = sc.nextLong();
            g.add(new ArrayList<>());
            for (long i = 1; i <= n; i++) {
                g.add(new ArrayList<>());
            }
            for (long i = 1; i <= m; i++) {
                long u = sc.nextLong();
                long v = sc.nextLong();
                g.get((int) (u)).add(v);
            }
            Arrays.fill(vis, 0, (int) n + (int) 2l, false);
            Arrays.fill(dis, 0, (int) n + 2, 0);
            vis[1] = true;
            d[1] = 0l;
            Queue<Long> q = new LinkedList();
            q.offer(1l);
            while (q.isEmpty() == false) {
                long u = q.poll();
                for (long v : g.get((int) u)) {
                    if (vis[(int) v] == false) {
                        vis[(int) v] = true;
                        d[(int) v] = d[(int) u] + 1l;
                        q.offer(v);
                    }
                }
            }
            Arrays.fill(vis, 0, (int) n + (int) 1l, false);
            dfs(1, 0);
            boolean f = true;
            for (long i = 2; i <= n; i++) {
                if (dis[(int) i] != d[(int) i]) {
                    f = false;
                    break;
                }
            }
            if (f == false) System.out.println("No");
            else System.out.println("Yes");
        }
    }
};
