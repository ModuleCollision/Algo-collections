def solve():
    n, m1, m2 = map(int, input().split())
    p1 = [];
    p2 = []
    for i in range(m1):
        u, v = map(int, input().split())
        p1.append((u, v))
    for i in range(m2):
        u, v = map(int, input().split())
        p2.append((u, v))

    x1 = 0;
    x2 = 0;
    l1 = -1; l2 = -1;
    y1 = 0;
    y2 = 0;
    ans = 0;
    while (x1 < m1):
        h = min(p1[x1][1] - y1, p2[x2][1] - y2)
        u1 = p1[x1][0];
        u2 = p2[x2][0];
        w = set();
        w.add(l1);
        w.add(l2);
        w.add(u1);
        w.add(u2);
        if (l1 != -1 and len(w) == 2):
            ans += 1
        if (u1 != u2):
            ans += h - 1
        l1 = u1;
        l2 = u2;
        y1 += h;
        if (y1 == p1[x1][1]):
            x1 += 1;
            y1 = 0;
        y2 += h;
        if (y2 == p2[x2][1]):
            x2 += 1;
            y2 = 0;
    print(ans)


solve();
