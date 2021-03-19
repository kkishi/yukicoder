#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  vector dp(n + 1, vector(10, mint(0)));
  dp[0][0] = 1;
  rep(i, n) rep(j, 10) rep(k, j, 10) dp[i + 1][k] += dp[i][j];
  wt(accumulate(all(dp[n]), mint(0)));
}
