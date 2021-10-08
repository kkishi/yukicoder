#include <bits/stdc++.h>

#include "matrix.h"
#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;
using M = Matrix<mint, 6, 6>;
using N = Matrix<mint, 6, 1>;

void Main() {
  ints(t);
  mint oot = mint(1) / mint(3);
  rep(t) {
    ints(n);
    N v = {0, 1, 0, 0, 0, 0};
    M m = {};
    rep(i, 3) {
      rep(j, 3) if (j != i) { m[i * 2][j * 2 + 1] = oot; }
      m[i * 2 + 1][i * 2] = 1;
      m[i * 2 + 1][i * 2 + 1] = oot;
    }
    N a = Mult(Pow(m, n), v);
    wt(a[0][1]);
  }
}
