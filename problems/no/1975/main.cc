#include <bits/stdc++.h>

#include "add_segment_tree.h"
#include "compressor.h"
#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  mint ans = 0;
  rep(2) {
    each(e, a) e = -e;
    Compressor c(a);
    int N = sz(c.coord);
    V<mint> p(n, 1);
    rep(2) {
      AddSegmentTree<mint> t(N);
      reverse(p);
      reverse(a);
      rep(i, n) {
        int ci = c(a[i]);
        p[i] *= t.Aggregate(0, ci);
        t.Set(ci, t.Get(ci) + mint(2).Pow(i));
      }
    }
    ans += accumulate(p);
  }
  wt(ans);
}
