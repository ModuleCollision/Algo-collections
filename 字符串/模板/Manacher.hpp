std::vector<i64> Manacher(string s) {
  i64 len = s.size();
  std::string st(len * 2 + 5, ' ');
  for (i64 i = 0; i < len; i++) {
    st[i * 2] = '#'; st[i * 2 + 1] = s[i];
  }
  st[len * 2] = '#';
  std::vector<i64>d(2 * len + 5);
  for (i64 i = 0, l = 0, r = -1; i < len * 2 + 1; i++) {
    i64 k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
    while (i - k >= 0 and i + k < 2 * len + 1 and st[i - k] == st[i + k])k++;
    d[i] = k--;
    if (i + k > r) {
      l = i - k; r = i + k;
    }
  }//维护的是st串的最长回文半径
  return d;
}