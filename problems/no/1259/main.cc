#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  ints(n, k, m);
  mint one = 0;
  rep(l, 1, n + 1) if (k % l == 0) {
    one += mint::Perm(n - 1, l - 1) * mint(n).Pow(n - l);
  }
  if (m == 1) {
    wt(one);
  } else {
    wt((mint(n).Pow(n) - one) / (n - 1));
  }
}
