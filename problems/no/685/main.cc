#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> v;
  if (n == 0) {
    v = {0};
  } else {
    while (n) {
      v.pb(n & 1);
      n >>= 1;
    }
    reverse(all(v));
  }
  int N = sz(v);
  vector dp(N + 1, vector(2, vector(2, vector(2, vector(2, mint(0))))));
  dp[0][0][0][0][0] = 1;
  rep(i, N) rep(y_lt_n, 2) rep(x_lt_y, 2) rep(and_lt_xor, 2) rep(xor_lt_or, 2)
      rep(x, 2) rep(y, 2) {
    if (!y_lt_n && y > v[i]) continue;
    if (!x_lt_y && x > y) continue;
    if (!and_lt_xor && ((x & y) > (x ^ y))) continue;
    if (!xor_lt_or && ((x ^ y) > (x | y))) continue;
    dp[i + 1][y_lt_n | (y < v[i])][x_lt_y | (x < y)]
      [and_lt_xor | ((x & y) < (x ^ y))][xor_lt_or | ((x ^ y) < (x | y))] +=
        dp[i][y_lt_n][x_lt_y][and_lt_xor][xor_lt_or];
  }
  mint ans = 0;
  rep(i, 2) rep(j, 2) ans += dp[N][i][j][1][1];
  wt(ans);
}
