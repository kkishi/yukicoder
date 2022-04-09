#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(x, y);
  auto f = [](int a, int b) {
    return min(abs(a - b + 12) % 12, abs(b - a + 12) % 12);
  };
  rep(z, 12) {
    if (f(x, y) == f(y, z) && f(y, z) == f(z, x)) {
      wt(z);
      return;
    }
  }
}
