#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct edge {
    int v; int ex; int rev;
};
vector<edge>G[maxn];
int deg[maxn];
int revtop[maxn];
vector<int>ans;
bool vis[maxn];
int pas = 0;
void hierholzer(int x) {
    vis[x] = 1;
    for (auto &e : G[x]) {
        if (e.ex) {
            e.ex = 0;
            G[e.v][e.rev].ex = 0;
            hierholzer(e.v);
        }
    }
}
int T, n, m;
void solve() {
    cin >> n >> m;
    pas = 0;
    ans.clear();
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        vis[i] = 0;
        deg[i] = 0;
        revtop[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        G[u].push_back(edge{v, 1, 0});
        G[v].push_back(edge{u, 1, 0});
    }
    for (int i = 1; i <= n; i++) {
        std::sort(G[i].begin(), G[i].end(), [](edge & a, edge & b)->bool{
            return a.v < b.v;
        });
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            G[i][j].rev = revtop[G[i][j].v]++;
        }
    }
    int ang = 0;
    for (int i = 1; i <= n; i++) {
        if (!deg[ang] and deg[i]) {
            ang = i;
        }
        if ((!(deg[ang] & 1)) and (deg[i] & 1)) {
            ang = i;
        }
    }
    hierholzer(ang);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            puts("Xun");
            return;
        }
    }
    int ji = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2) {
            ji++;
        }
    }
    if (ji == 2 or ji == 0) {
        puts("Zhen");
    } else {
        puts("Xun");
    }

}
int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}