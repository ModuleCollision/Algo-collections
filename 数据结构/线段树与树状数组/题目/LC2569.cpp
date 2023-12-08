typedef long long ll;
struct sq {
	int add; int l; int r; int v;
} tr[400005]; int w[100005];
void pushup(int p) {
	tr[p].v = tr[p << 1].v + tr[p << 1 | 1].v;
}
void build(int p, int l, int r) {
	tr[p].l = l; tr[p].r = r; tr[p].add = 0;
	if (l == r) {
		tr[p].v = w[l]; tr[p].add = 0; return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
	pushup(p);
}
void pushdown(int p) {
	if (tr[p].add) {
		tr[p].add = 0;
		tr[p << 1].add ^= 1;
		tr[p << 1 | 1].add ^= 1;
		tr[p << 1].v = (tr[p << 1].r - tr[p << 1].l + 1 - tr[p << 1].v);
		tr[p << 1 | 1].v = (tr[p << 1 | 1].r - tr[p << 1 | 1].l + 1 - tr[p << 1 | 1].v);
	}
}
void modify(int p, int l, int r) {
	if (tr[p].l >= l and tr[p].r <= r) {
		tr[p].add ^= 1; tr[p].v = (tr[p].r - tr[p].l + 1 - tr[p].v);
		return;
	}
	pushdown(p);
	int mid = (tr[p].l + tr[p].r) >> 1;
	if (l <= mid)modify(p << 1, l, r);
	if (r > mid)modify(p << 1 | 1, l, r);
	pushup(p);
}
ll query() {
	return (ll)tr[1].v;
}
class Solution {
public:
	vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
		ll tot = 0;
		vector<ll>ans; for (auto c : nums2)tot += c;
		int n = nums1.size();
		for (int i = 0; i < n; i++)w[i + 1] = nums1[i];
		build(1, 1, n);
		for (auto w : queries) {
			int o = w[0], l = w[1], r = w[2];
			if (o == 1)modify(1, l + 1, r + 1);
			else if (o == 2)tot += query() * l;
			else ans.push_back(tot);
		}
		return ans;
	}
};