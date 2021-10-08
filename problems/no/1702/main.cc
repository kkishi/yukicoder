#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  strings(s);
  string yukicoder = "yukicoder";
  int N = sz(yukicoder);
  vector dp(N + 1, vector(2, mint(0)));
  dp[0][0] = 1;
  rep(i, n) {
    rrep(j, N) {
      rep(k, 2) {
        if (s[i] == yukicoder[j] || s[i] == '?') {
          int nk = k + (s[i] == '?');
          if (nk < 2) {
            dp[j + 1][nk] += dp[j][k];
          }
        }
      }
    }
  }
  wt(dp[N][0] + dp[N][1]);
}
