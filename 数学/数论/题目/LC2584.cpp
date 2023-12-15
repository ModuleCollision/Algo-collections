#include<bits/extc++.h>

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
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


class Solution {
public:
    int findValidSplit(vector<int> &nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int lim = mx + 3;
        vector<int>son(lim + 5, 0); int n = nums.size();
        vector<int>st[n + 5];
        for (int i = 2; i <= lim; i++) {
            if (not son[i]) {
                son[i] = i;
                for (int j = i + i; j <= lim; j += i) {
                    if (not son[j])son[j] = i;
                }
            }
        }
        unordered_map<i64 , i64>cnt, tot;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (x == 1) {
                st[i].push_back(1); tot[1]++ ; continue;
            }
            while (x != 1) {
                int las = son[x];
                while (x % las == 0) {
                    x /= las;
                }
                st[i].push_back(las); tot[las]++;
            }
        }
        i64 cur = tot.size();
        for (i64 i = 0; i < n - 1; i++) {
            for (auto s : st[i]) {
                cnt[s] ++;
                if (cnt[s] == 1) {
                    cur--;
                }
                if (cnt[s] == tot[s])cur++;//出现的质数全部出现在分割点左半部
            }
            if (cur == tot.size())return i;

        }
        return -1;
    }
};