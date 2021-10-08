#include <bits/stdc++.h>

#include "matrix.h"
#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;
using M = Matrix<mint, 4, 4>;
using N = Matrix<mint, 4, 1>;

void Main() {
  ints(c, n, m);
  N a = {0, 1, 0, 0};
  M x = {};
  x[0][3] = (c - 1) / mint(c);
  x[1][0] = 1;
  x[1][1] = 1 / mint(c);
  x[2][1] = 1 / mint(c);
  x[2][3] = (c - 2) / mint(c);
  x[3][2] = 1;
  x[3][3] = 1 / mint(c);
  N b = Mult(Pow(x, n), a);
  wt(1 - (1 - b[0][1]).Pow(m));
}
