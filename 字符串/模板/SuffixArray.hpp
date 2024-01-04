
// 维护sa rk height数组
i64 s[maxn], n; i64 ht[maxn];
i64 sa[maxn], rk[maxn], oldrk[maxn << 1], id[maxn], key1[maxn], cnt[maxn];
void init() {
	auto cmp = [&](i64 x, i64 y, i64 w) {
		return oldrk[x] == oldrk[y] and oldrk[x + w] == oldrk[y + w];
	};
	i64 m = 127; i64 p, w, i, j;
	for (i = 1; i <= n; i++)++cnt[rk[i] = s[i]];
	for (i = 1; i <= m; i++)cnt[i] += cnt[i - 1];
	for (i = n; i >= 1; i--)sa[cnt[rk[i]]--] = i;//计数排序
	for (w = 1;; w <<= 1, m = p) {
		for (p = 0, i = n; i > n - w; --i)id[++p] = i;
		for (i = 1; i <= n; i++) {
			if (sa[i] > w)id[++p] = sa[i] - w;
		}
		memset(cnt, 0, sizeof(cnt));
		for (i = 1; i <= n; i++) {
			++cnt[key1[i] = rk[id[i]]];
		}
		for (i = 1; i <= m; i++)cnt[i] += cnt[i - 1];
		for (i = n; i >= 1; i--)sa[cnt[key1[i]]--] = id[i];
		for (i = 1; i <= n; i++) {
			oldrk[i] = rk[i];
		}
		for (p = 0, i = 1; i <= n; i++) {
			rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
		}
		if (p == n) {
			for (i = 1; i <= n; i++)sa[rk[i]] = i;
			break;
		}
	}
	for (i = 1, j = 0; i <= n; i++) {
		if (j)--j;
		while (s[i + j] == s[sa[rk[i] - 1] + j])++j;
		ht[rk[i]] = j;
	}
}