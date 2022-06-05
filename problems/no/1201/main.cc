#include <bits/stdc++.h>

#include <atcoder/math>

#include "yukicoder.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(m);
  cin >> a >> b;
  int ans = 0;
  rep(i, n) rep(j, m) {
    ans += atcoder::floor_sum(b[j] + 1, b[j], a[i], 0) * 2;
    ans %= int(1e9 + 7);
  }
  wt(ans);
}
