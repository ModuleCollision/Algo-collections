n, c = map(int, input().split(' '))
op = []
for i in range(n):
    u, v = map(int, input().split(' '))
    op.append((u, v))

ans = [0] * n
for k in range(30):
    cur = ((c >> k) & 1)
    func = [0, 1]
    for i in range(n):
        t = op[i][0];
        a = op[i][1]
        curr = ((a >> k) & 1)
        f = [0, 1]
        if (t == 1):
            f = [0 & curr, 1 & curr]
        elif (t == 2):
            f = [0 | curr, 1 | curr]
        else:
            f = [0 ^ curr, 1 | curr]
        func = [f[func[0]], f[func[1]]]
        cur = func[cur]
        ans[i] |= (cur << k)

for i in range(n):
        print(ans[i])
