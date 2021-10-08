#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n, w);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(mask, 1, 1 << n) {
    bool ok = false;
    for (int sub = mask;; sub = (sub - 1) & mask) {
      int sum = 0;
      rep(i, n) {
        if (hasbit(sub, i)) {
          sum += a[i] / 2;
        } else if (hasbit(mask, i)) {
          sum += a[i];
        }
      }
      if (sum == w) ok = true;
      if (sub == 0) break;
    }
    if (ok) ++ans;
  }
  wt(ans);
}
