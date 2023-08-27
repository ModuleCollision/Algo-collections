# from pwn import *
from collections import Counter

def solve():
    sum = 0;
    n = int(input())
    s = list(map(int, input().split()))
    s = sorted(s)
    for x in s:
        sum += x
    if (sum % n == 0):
        ans = 0
        p = sum // n
        for i in range(len(s)):
            ans += abs(s[i] - p)
        print(ans // 2)
        return

    # 否则必然存在一种方案使得n - 1个元素为众数, 向剩余一个数构造
    def cal(l: int, r: int) -> int:
        sum = 0
        for i in range(l, r + 1, 1):
            sum += s[i]
        p = sum // (r - l + 1);
        pp = p + 1
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        for i in range(l, r + 1, 1):
            if (p >= s[i]):
                a += abs(p - s[i])
            else:
                b += abs(p - s[i])
            if (pp >= s[i]):
                c += abs(pp - s[i])
            else:
                d += abs(pp - s[i])
        return min(max(a, b), max(c, d))
    print(min(cal(0, n - 2), cal(1, n - 1)))


solve();
