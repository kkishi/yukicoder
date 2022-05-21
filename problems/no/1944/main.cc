#include <bits/stdc++.h>

#include "geometry.h"
#include "yukicoder.h"

void Main() {
  ints(n);
  rd(Point, p);
  V<double> r(n);
  cin >> r;
  double sum = accumulate(r);
  wt([&] {
    rep(i, n) {
      double d = abs(p.Norm() - r[i]);
      double e = sum - r[i];
      if (d - 1e-6 < e * 2) return true;
    }
    return false;
  }());
}
