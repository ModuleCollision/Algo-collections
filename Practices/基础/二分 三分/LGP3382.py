# from sortedcontainers import SortedSet
# from collections import Counter
# from bisect import bisect_right
from math import *

eps = 0.0000001
n, l, r = map(float, input().split(' '))
n = int(n)
c = list(map(int, input(' ').split(' ')))


def f(x: float) -> float:
    ret = 0.0
    for i, p in enumerate(c):
        ret += (x ** (i)) * p
    return ret


while (r - l > eps):
    mid = (l + r) / 2
    lmid = mid - eps
    rmid = mid + eps
    if (f(lmid) > f(rmid)):
        r = mid
    else:
        l = mid
print(l)
