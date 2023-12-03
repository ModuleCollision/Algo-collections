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
int n, q, m;
int a[maxn];
struct Mex {
    int cnt[maxn]; set<int> st;
    multiset<int> mulst;
    Mex() {
        for (int i = 0; i < maxn; ++i) cnt[i] = 0;
        for (int i = 0; i < maxn; ++i) st.insert(i);
    }
    void add(int x) {
        //第一次添加
        if (cnt[x] == 0) {
            st.erase(x);
        }
        ++cnt[x];
        mulst.insert(x);
    }
    void del(int x) {
        //只剩一个了
        if (cnt[x] == 1) {
            st.insert(x);
        }
        --cnt[x];
        //不能写成mulst.erase(x) 这样是删除所有值为x的元素
        mulst.erase(mulst.find(x));
    }
    int mex() {
        return *st.begin();
    }
    void clear() {
        while (!mulst.empty()) {
            del(*mulst.begin());
        }
    }
};

void solve() {
    cin >> n >> q;
    Mex mex;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] <= n)
            mex.add(a[i]);
    }
    while (q--) {
        int x, v;
        cin >> x >> v;
        if (a[x] <= n)
            mex.del(a[x]);
        if (v <= n)
            mex.add(v);
        a[x] = v;
        cout << mex.mex() << "\n";
    }
}

int main() {
    solve();
}