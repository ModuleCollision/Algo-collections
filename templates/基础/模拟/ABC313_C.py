n = int(input(' '))
s = list(map(int, input(' ').split(' ')))
sum = 0;
for x in s:
    sum += x
p = sum // n; r = sum % n;
ans = 0
s = sorted(s)
for i in range(n - 1, n - r - 1, -1):
    ans += abs(s[i] - p - 1)

for i in range(n - r):
    ans += abs(s[i] - p)

print(int(ans // 2))