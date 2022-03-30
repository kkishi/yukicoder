#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "add_segment_tree.h"
#include "heavy_light_decomposition.h"
#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

using S = pair<mint, mint>;
S op(S a, S b) { return {a.first + b.first, a.second + b.second}; };
S e() { return {0, 0}; }
using F = mint;
S mapping(F f, S x) { return {x.first + f * x.second, x.second}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

void Main() {
  ints(n);
  V<int> s(n), c(n);
  cin >> s >> c;
  Graph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g.AddEdge(a, b);
    g.AddEdge(b, a);
  }
  HeavyLightDecomposition hld(g);
  segtree t(n);
  rep(i, n) t.set(hld.Index(i), {s[i], c[i]});
  ints(q);
  rep(q) {
    ints(k);
    if (k == 0) {
      ints(x, y, z);
      --x, --y;
      each(l, r, hld.Query(x, y, true)) t.apply(l, r, z);
    } else {
      ints(x, y);
      --x, --y;
      mint ans = 0;
      each(l, r, hld.Query(x, y, true)) ans += t.prod(l, r).first;
      wt(ans);
    }
  }
}
