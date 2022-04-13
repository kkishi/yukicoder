#include <bits/stdc++.h>

#include "pow.h"
#include "yukicoder.h"

template <int64_t Base>
int64_t Digit(int64_t x, int64_t i_th) {
  return x / Pow(Base, i_th) % Base;
}

void Main() {
  ints(p, q, r, k);
  vector next(60, vector(1000, int(0)));
  rep(i, 1000) {
    next[0][i] = (i * 10) % 1000 +
                 (Digit<10>(i, 2) + Digit<10>(i, 1) + Digit<10>(i, 0)) % 10;
  }
  rep(i, 1, 60) rep(j, 1000) next[i][j] = next[i - 1][next[i - 1][j]];

  int x = p % 10 * 100 + q % 10 * 10 + r % 10;
  k -= 3;
  rep(i, 60) if ((k >> i) & 1) x = next[i][x];
  wt(x % 10);
}
