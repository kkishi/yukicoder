#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "yukicoder.h"

using S = int;

S op(S a, S b) { return min(a, b); }

S e() { return numeric_limits<int>::max(); }

using F = int;

S mapping(F f, S x) { return x + f; }

F composition(F f, F g) { return f + g; }

F id() { return 0; }

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
  rep(i, n) seg.set(i, a[i]);

  ints(q);
  rep(q) {
    ints(k, l, r, c);
    if (k == 1) {
      seg.apply(l - 1, r, c);
    } else {
      wt(seg.prod(l - 1, r));
    }
  }
}
