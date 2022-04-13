#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  wt([] {
    ints(n);
    V<int> e(n);
    cin >> e;
    V<int> t(n + 1);
    t[0] = 1;
    rep(i, n) t[i + 1] = t[i] * 3;
    rep(mask, t[n]) {
      V<int> p(3);
      rep(i, n) p[mask / t[i] % 3] += e[i];
      if (p[0] == p[1] && p[1] == p[2]) return true;
    }
    return false;
  }());
}
