class Solution {
    class Node {
        int l, r;
        int mx;
    }

    Node[] tr;

    private void pushup(int p) {
        tr[p].mx = Math.max(tr[p << 1].mx, tr[p << 1 | 1].mx);
    }

    private void build(int p, int l, int r) {
        tr[p].l = l;
        tr[p].r = r;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }

    private void modify(int p, int idx, int val) {
        if (tr[p].l == tr[p].r) {
            tr[p].mx = val;
            return;
        }
        int m = (tr[p].l + tr[p].r) >> 1;
        if (idx <= m)
            modify(p << 1, idx, val);
        if (idx > m)
            modify(p << 1 | 1, idx, val);
        pushup(p);
    }

    private int query(int p, int l, int r) {
        if (tr[p].l >= l && tr[p].r <= r) {
            return tr[p].mx;
        }
        int res = 0, mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid)
            res = query(p << 1, l, r);
        if (r > mid)
            res = Math.max(res, query(p << 1 | 1, l, r));
        return res;
    }

    public int lengthOfLIS(int[] nums, int k) {
        var u = 0;
        for (var x : nums)
            u = Math.max(u, x);
        tr = new Node[u * 4];

        Arrays.setAll(tr, e -> new Node()); build(1, 1, u);
        for (var x : nums) {
            if (x == 1)
                modify(1, 1, 1);
            else {
                var res = 1 + query(1, Math.max(x - k, 1), x - 1);
                modify(1, x, res);
            }
        }
        return tr[1].mx;
    }

};