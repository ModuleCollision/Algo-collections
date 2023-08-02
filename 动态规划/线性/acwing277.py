n, m = list(map(int, input().split(' ')))
p = list(map(int, input().split(' ')))
s = [i for i in range(1, n + 1, 1)]
sk = [(i, j) for i, j in zip(p, s)]
sk.sort(key=lambda x: x[0], reverse=True)
#print(sk)
sk.insert(0, (0, 0))
#print(sk)
dp = [[0x3f3f3f3f] * (m + 5) for _ in range(n + 5)]
pre = [0] * (n + 5)
for i in range(1, n + 1, 1):
    pre[i] = pre[i - 1] + sk[i][0]
dp[0][0] = 0
for i in range(1, n + 1, 1):
    for j in range(1, m + 1, 1):
        if (j >= i):
            dp[i][j] = min(dp[i][j], dp[i][j - i])
        for k in range(1, min(i, j) + 1, 1):
            dp[i][j] = min(dp[i][j], dp[i - k][j - k] + (pre[i] - pre[i - k]) * (i - k));

print(dp[n][m])
ans = [0] * (n + 1)
i = n;
j = m;
h = 0
while (i > 0 and j > 0):
    if (j >= i and dp[i][j] == dp[i][j - i]):
        j -= i;
        h += 1;
    else:
        for k in range(1, min(i, j) + 1, 1):
            if (dp[i][j] == dp[i - k][j - k] + (pre[i] - pre[i - k]) * (i - k)):
                for u in range(i, i - k, -1):
                    ans[sk[u][1]] = 1 + h
                i -= k;
                j -= k;
                break;

for i in range(1, n + 1, 1):
    print(ans[i], end=" ")