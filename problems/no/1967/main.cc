#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<998244353>;

void Main() {
  ints(N, K);
  vector dp(N + 1, vector(K + 1, mint(0)));
  dp[0][0] = 1;
  rep(k, 1, K + 1) {
    mint s = 0;
    dp[0][k] = 1;
    rep(d, 1, N + 1) {
      s += dp[d - 1][k - 1];
      dp[d][k] = s / d;
    }
  }
  wt(dp[N][K]);
}
