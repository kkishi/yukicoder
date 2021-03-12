#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(a, b, c);
    int l = lcm(a, lcm(b, c));
    wt(l, l, l);
  }
}
