#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n, m, q);
  vector g(n, vector(m, false));
  rep(q) {
    ints(a, b);
    g[a - 1][b - 1] = true;
  }
  vector dp(n + 1, vector(m + 1, int(0)));
  rep(i, n) rep(j, m) {
    chmax(dp[i + 1][j], dp[i][j]);
    chmax(dp[i][j + 1], dp[i][j]);
    if (g[i][j]) {
      chmax(dp[i + 1][j + 1], dp[i][j] + 1);
    }
  }
  int ans = 0;
  each(e, dp) each(f, e) chmax(ans, f);
  wt(ans);
}
