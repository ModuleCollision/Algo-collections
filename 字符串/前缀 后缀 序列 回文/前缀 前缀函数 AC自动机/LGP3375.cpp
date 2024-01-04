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
constexpr i64 maxn = 1e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

std::vector<i64> Prefix(string s) {
    i64 len = s.size();
    std::vector<i64>p(len, 0);
    for (i64 i = 1; i < len; i++) {
        i64 j = p[i - 1];
        while (j > 0 and s[i] != s[j])j = p[j - 1];
        if (s[i] == s[j])j++;
        p[i] = j;
    }
    return p;
}

int main() {

    string s1, s2;
    std::cin >> s1 >> s2;
    string s = s2 + "#" + s1;
    auto p = Prefix(s);
    for (i64 i = s2.size() + 1; i < s1.size() + s2.size() + 1; i++) {
        if (p[i] >= s2.size()) {
            std::cout << i - 2 * s2.size() + 1 << "\n";
        }
    }
    auto f = Prefix(s2);
    for (i64 i = 0; i < s2.size(); i++) {
        std::cout << f[i] << " \n"[i == s2.size() - 1];
    }
}