#include <bits/stdc++.h>

#include "int_sqrt.h"
#include "yukicoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(l, r);
    auto f = [](int x) { return IntSqrt(x) + IntSqrt(x / 2); };
    wt((f(r) - f(l - 1)) % 2);
  }
}
