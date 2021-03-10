#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> dp(10, -1);
  dp[0] = 0;
  each(e, a) {
    V<int> ndp = dp;
    rep(i, 10) if (dp[i] != -1) chmax(ndp[(i + e) % 10], dp[i] + 1);
    swap(ndp, dp);
  }
  wt(dp[0]);
}
