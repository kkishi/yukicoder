#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

struct DP {
  mint cnt, x, pcnt;
  void Add(DP dp, int digit) {
    cnt += dp.cnt;
    x += dp.x * 2 + dp.cnt * digit;
    pcnt += dp.pcnt + dp.cnt * digit;
  }
  mint V() { return x * pcnt; };
};

ostream& operator<<(ostream& os, const DP& dp) {
  os << "{" << dp.cnt << " " << dp.x << " " << dp.pcnt << "}";
  return os;
}

void Main() {
  ints(n);
  V<int> v;
  while (n) {
    v.pb(n & 1);
    n >>= 1;
  }
  reverse(all(v));
  int N = sz(v);
  vector dp(N + 1, vector(2, DP{0, 0, 0}));
  dp[0][0] = {1, 0, 0};
  rep(i, N) rep(lo, 2) rep(j, 2) {
    if (!lo && j > v[i]) continue;
    int nlo = lo | (j < v[i]);
    dp[i + 1][nlo].Add(dp[i][lo], j);
  }
  rep(i, N) dbg(dp[i]);
  mint ans = 0;
  rep(i, 2) ans += dp[N][i].V();
  wt(ans);
}
