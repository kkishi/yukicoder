#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "heavy_light_decomposition.h"
#include "yukicoder.h"

void Main() {
  ints(n);
  Graph<int> g(n);
  rep(n - 1) {
    ints(u, v);
    --u, --v;
    g.AddEdge(u, v);
    g.AddEdge(v, u);
  }
  HeavyLightDecomposition hld(g, attr_on_node);
  add_sum::segtree t(V<int>(n, 1));
  ints(q);
  int ans = 0;
  rep(q) {
    ints(a, b);
    --a, --b;
    each(l, r, hld.Path(a, b)) {
      ans += t.prod(l, r).val;
      t.apply(l, r, 1);
    }
  }
  wt(ans);
}
