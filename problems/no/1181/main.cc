#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  mint x = (mint(k) * (k + 3) / 2).Pow(n);
  mint y = (mint(k) * (k + 1) / 2).Pow(n);
  wt(x - y);
}
