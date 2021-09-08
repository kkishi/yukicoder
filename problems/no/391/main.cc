#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  ints(n, m);
  mint ans = 0;
  rep(i, m) ans += (even(i) ? 1 : -1) * mint::Comb(m, i) * mint(m - i).Pow(n);
  wt(ans);
}
