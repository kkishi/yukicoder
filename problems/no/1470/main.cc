#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  int one = 0, two = 0;
  rep(n) {
    ints(a);
    if (a == 1) ++one;
    if (a == 2) ++two;
  }
  int rest = n - (one + two);
  auto nC2 = [](int x) { return x * (x - 1) / 2; };
  wt(1 * nC2(n - one) + 2 * (nC2(n - two) - nC2(rest)) + 3 * one * two);
}
