#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  ints(t);
  rep(t) {
    char kind, _;
    int n, k;
    cin >> kind >> _ >> n >> _ >> k >> _;
    if (kind == 'C') wt(mint::Comb(n, k));
    if (kind == 'P') wt(mint::Perm(n, k));
    if (kind == 'H') {
      if (n == 0 && k == 0) {
        // TODO: Add this case to pclib.
        wt(1);
      } else {
        wt(mint::Comb(n + k - 1, k));
      }
    }
  }
}
