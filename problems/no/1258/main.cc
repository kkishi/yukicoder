#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  ints(s);
  rep(s) {
    ints(n, m, x);
    mint a = mint(1 + m).Pow(n);
    mint b = mint(1 - m).Pow(n);
    if (x == 1) {
      wt((a - b) / 2);
    } else {
      wt((a + b) / 2);
    }
  }
}
