void Subsets(std::vector<i64>d) {
  i64 n = d.size();
  std::vector<i64>dp(1 << n, 0);

  for (i64 i = 0; i < (1 << n); i++) {
    for (i64 j = 0; j < n; j++) {
      if ((i >> j) & 1)dp[i] += d[j];
    }
  }
  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < (1 << n); j++) {
      if ((j >> i) & 1)dp[j] += dp[j ^ (1 << i)];
    }
  }
  /*按序枚举*/
}

/*SOS dp 高维前缀和, 求一个集合的所有子集对应的权值和*/