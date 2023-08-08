/*双指针,动态维护区间各个值数量的利器*/
/*一般只需要动态维护一个一维的桶*/
for (int r = 0, l = 0; r < n; r++) {
	cnt[(int)(s[r] - 'a')]++;
	while (cnt[(int)(s[r] - 'a')] > tot[s[r] - 'a'] - k) {
		cnt[(int)(s[l] - 'a')]--;
		l++;
	}//动态维护左指针直到找到满足条件的区间
	int cur = n - (r - l + 1);
	res = min(res, cur);
}