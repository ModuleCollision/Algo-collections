std::vector<i64> Prefix(string s) {
  i64 len = s.size();
  std::vector<i64>p(len + 5, 0);
  for (i64 i = 1; i < len; i++) {
    i64 j = p[i - 1];
    while (j > 0 and s[i] != s[j])j = p[j - 1];
    if (s[i] == s[j])j++;
    p[i] = j;
  }//KMP函数板题
  return p;
}