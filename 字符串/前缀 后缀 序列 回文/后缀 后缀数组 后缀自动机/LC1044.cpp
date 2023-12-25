#include<bits/stdc++.h>
using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;


const i64 mod = 1e9 + 7;
const i64 maxn = 3e4 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;


class Solution {
public:
    i64 ht[maxn];
    i64 sa[maxn], rk[maxn], oldrk[maxn << 1], id[maxn], key1[maxn], cnt[maxn];
    string longestDupSubstring(string s) {
        i64 n = s.size();
        s = " " + s;

        auto cmp = [&](i64 x, i64 y, i64 w) {
            return oldrk[x] == oldrk[y] and oldrk[x + w] == oldrk[y + w];
        };
        i64 m = 127;
        for (i64 i = 1; i <= n; i++)++cnt[rk[i] = s[i]];
        for (i64 i = 1; i <= m; i++)cnt[i] += cnt[i - 1];
        for (i64 i = n; i >= 1; i--)sa[cnt[rk[i]]--] = i;//计数排序

        for (i64 w = 1, p;; w <<= 1, m = p) {
            p = 0;
            for (i64 i = n; i > n - w; --i)id[++p] = i;
            for (i64 i = 1; i <= n; i++) {
                if (sa[i] > w)id[++p] = sa[i] - w;
            }
            memset(cnt, 0, sizeof(cnt));
            for (i64 i = 1; i <= n; i++) {
                ++cnt[key1[i] = rk[id[i]]];
            }
            for (i64 i = 1; i <= m; i++)cnt[i] += cnt[i - 1];
            for (i64 i = n; i >= 1; i--)sa[cnt[key1[i]]--] = id[i];
            for (i64 i = 1; i <= n; i++) {
                oldrk[i] = rk[i];
            }
            p = 0;
            for (i64 i = 1; i <= n; i++) {
                rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
            }
            if (p == n) {
                for (i64 i = 1; i <= n; i++)sa[rk[i]] = i;
                break;
            }
        }
        for (i64 i = 1, j = 0; i <= n; i++) {
            if (j)--j;
            while (s[i + j] == s[sa[rk[i] - 1] + j])++j;
            ht[rk[i]] = j;
        }

        i64 mx = 0; i64 idx = -1;
        for (i64 i = 1; i <= n; i ++) {
            std::cout << ht[i] << " \n"[i == n];
        }
        for (i64 i = 1; i <= n; i++) {
            if (ht[i] > mx) {
                mx = ht[i];
                idx = sa[i];
            }
        }
        return mx == 0 ? "" : s.substr(idx, mx);
    }
};