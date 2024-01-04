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
using namespace std;


const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
/*无向图带权并查集*/
struct DisjoinSet {

public:
    std::vector<i64>f, v;

    DisjoinSet() {}

    DisjoinSet(int n) {init(n);}

    void init(int n) {
        f.assign(n + 1, 0);
        v.assign(n + 1, 1);
        std::iota(f.begin() + 1, f.begin() + 1 + n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)return false;
        v[x] += v[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return v[find(x)];
    }
};
void solve() {
    i64 n, k; std::cin >> n >> k;
    std::string s, t; std::cin >> s >> t;
    string ss = s, tt = t;
    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());
    if (ss != tt) {
        puts("NO"); return;
    }
    s = " " + s, t = " " + t;
    DisjoinSet st(n);
    for (i64 i = 1; i <= n; i++) {
        if (i >= k + 1) {
            st.merge(i, i - k);
        }
        if (i >= k + 2) {
            st.merge(i, i - (k + 1));
        }
    }
    for (i64 i = n; i >= 1; i--) {
        if (i + k <= n) {
            st.merge(i, i + k);
        }
        if (i + k + 1 <= n) {
            st.merge(i, i + k + 1);
        }
    }
    std::map<i64, i64>cnt[30];
    for (i64 i = 1; i <= n; i++) {
        cnt[s[i] - 'a'][st.find(i)]++;
    }
    for (i64 i = 1; i <= n; i++) {
        i64 cur = t[i] - 'a';
        if (not cnt[cur][st.find(i)]) {
            puts("NO"); return;
        } else {
            cnt[cur][st.find(i)]--;
        }
    }
    puts("YES");
}
int main() {
    int T; std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}