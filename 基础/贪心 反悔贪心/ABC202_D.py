from collections import *
from math import factorial as fac

A, B, K = map(int, input().split(' '))


def dfs(A: int, B: int, K: int, s: str) -> str:
    if (A > 0):
        t = fac(A - 1 + B) // fac(A - 1) // fac(B)
        if (K > t):
            s += 'b'
            return dfs(A, B - 1, K - t, s)
        elif (K == t):
            s += 'a'
            for i in range(B):
                s += 'b'
            for i in range(A - 1):
                s += 'a'
            return s
        else:
            s += 'a'
            return dfs(A - 1, B, K, s)
    else:
        if (B):
            s += 'b'
            return dfs(A, B - 1, K, s)
    return


print(dfs(A, B, K, ""))
