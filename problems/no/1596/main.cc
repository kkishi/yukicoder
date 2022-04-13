#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  ints(n, m);
  mint ans = mint::Comb(2 * n, n) * 2 * n;
  rep(m) {
    ints(t, x, y);
    mint p = mint::Comb(x + y, x);
    (t == 1 ? x : y)++;
    ans -= p * mint::Comb(n - x + n - y, n - x);
  }
  wt(ans);
}
