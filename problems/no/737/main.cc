#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

struct DP {
  mint cnt, x;
  void Add(DP dp, int digit) {
    cnt += dp.cnt;
    x += dp.x * 2 + dp.cnt * digit;
  }
};

void Main() {
  ints(n);
  V<int> v;
  while (n) {
    v.pb(n & 1);
    n >>= 1;
  }
  reverse(all(v));
  int N = sz(v);
  vector dp(N + 1, vector(2, vector(60, DP{0, 0})));
  dp[0][0][0] = {1, 0};
  rep(i, N) rep(lo, 2) rep(pcnt, 60) rep(j, 2) {
    if (!lo && j > v[i]) continue;
    dp[i + 1][lo | (j < v[i])][pcnt + j].Add(dp[i][lo][pcnt], j);
  }
  mint ans = 0;
  rep(i, 2) rep(j, 60) ans += dp[N][i][j].x * j;
  wt(ans);
}
