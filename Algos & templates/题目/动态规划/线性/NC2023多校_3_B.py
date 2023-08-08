#from sortedcontainers import *
#from collections import *
#import numpy as np
#from sympy import *

T = int(input())
for _ in range(T):
    n, m = map(int, input().split(' '))
    c = [[0 for i in range(n + 1)] for j in range(n + 1)]
    p = [0] * (2 * n + 1)
    for i in range(n + 1):
        for j in range(i + 1):
            if (j == 0):
                c[i][j] = 1
            else:
                c[i][j] = (c[i - 1][j] % m + c[i - 1][j - 1]) % m;
    p[0] = 1;
    for i in range(1, 2 * n + 1, 1):
        p[i] = p[i - 1] * i % m;
    dp = [[[0, 0] for i in range(n + 1)] for i in range(n + 1)]
    dp[0][0][0] = dp[0][0][1] = 1;
    ans = p[2 * n]  # 很显然, 在所有的合法序列中会有一个不合法的末尾, 提前计算贡献
    for i in range(n + 1):
        for j in range(n + 1):
            for k in range(1, i + 1, 1):
                dp[i][j][0] = (dp[i][j][0] % m + dp[i - k][j][1] % m * c[n - i + k][k] % m) % m;
            for k in range(1, j + 1, 1):
                dp[i][j][1] = (dp[i][j][1] % m + dp[i][j - k][0] % m * c[n - j + k][k] % m) % m;
            if (not i and not j):
                continue
            if (i == n and j == n):  # 进行到2 * n - 1轮时, 不论第 2 * n 个合法与否都将计入统计
                continue
            ans = (ans % m + (dp[i][j][0] + dp[i][j][1]) % m * p[2 * n - i - j]) % m;
    print(ans)
