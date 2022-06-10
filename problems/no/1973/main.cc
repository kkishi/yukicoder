#include <bits/stdc++.h>

#include "factors.h"
#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  ints(n, m);
  mint ans = 1;
  each(_, e, Factors(m)) {
    vector dp(n + 1, vector(e + 1, mint(0)));
    dp[0][0] = 1;
    rep(i, n) rep(j, e + 1) rep(k, e - j + 1) dp[i + 1][j] += dp[i][k];
    ans *= accumulate(dp[n]);
  }
  wt(ans);
}
