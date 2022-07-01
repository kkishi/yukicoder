#include <bits/stdc++.h>

#include "bit.h"
#include "compressor.h"
#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  strings(s);
  Compressor c(a);
  int N = sz(c.coord);
  BIT<mint> b(N);
  rep(i, n) b.Add(c(a[i]), 1);
  V<mint> B(n, 1);
  each(si, s) {
    BIT<mint> cb(N);
    BIT<mint> nb(N);
    V<mint> nB(n);
    rep(i, n) {
      int j = c(a[i]);
      mint x = 0;
      if (si == '<') {
        x = cb.Sum(j - 1);
      } else {
        x = cb.Sum(N - 1) - cb.Sum(j);
      }
      nb.Add(j, x);
      nB[i] = x;
      cb.Add(j, B[i]);
    }
    swap(b, nb);
    swap(B, nB);
  }
  wt(b.Sum(N - 1));
}
