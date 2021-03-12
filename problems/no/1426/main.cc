#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

// NOTE: This is not a valid solution.
void Main() {
  ints(n);
  V<int> b(n);
  cin >> b;
  mint ans = 1;
  rep(bit, 30) {
    vector dp(n + 1, vector(2, mint(0)));
    dp[0][0] = 1;
    rep(i, n) {
      if (b[i] == -1) {
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][1] = dp[i][0] + dp[i][1] * 2;
      } else {
        if (hasbit(b[i], bit)) {
          dp[i + 1][0] = 0;
          dp[i + 1][1] = dp[i][0] + dp[i][1] * 2;
        } else {
          dp[i + 1][0] = dp[i][0];
        }
      }
    }
    dbg(dp);
    dbg(bit, dp[n][0] + dp[n][1]);
    ans *= dp[n][0] + dp[n][1];
  }
  wt(ans);
}
