#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> len(204);
  rep(i, 1, sz(len)) {
    int l = 0;
    int I = i;
    while (I) {
      I /= 10;
      ++l;
    }
    len[i] = l;
  }
  const int M = 200;
  vector dp(2 * M + 1, mint(0));
  dp[M] = 1;
  rep(n) {
    vector ndp(2 * M + 1, mint(0));
    rep(i, -M, M + 1) {
      if (dp[M + i] == 0) continue;
      rep(k, 1, 204) {
        int d = k - (len[k] + 1);
        int ni = i + d;
        if (ni < -M || M < ni) continue;
        ndp[M + ni] += dp[M + i];
      }
    }
    swap(dp, ndp);
  }
  wt(dp[M - 1]);
}
