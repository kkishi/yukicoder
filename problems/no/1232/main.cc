#include <bits/stdc++.h>

#include <atcoder/math>

#include "yukicoder.h"

int Solve() {
  ints(p);
  if (p == 2) return 2;
  return (p - 1) * atcoder::inv_mod(p - 1, p);
}

void Main() {
  ints(n);
  rep(n) wt(Solve());
}
