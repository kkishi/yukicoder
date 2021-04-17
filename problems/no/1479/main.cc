#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "compress.h"
#include "yukicoder.h"

void Main() {
  ints(h, w);
  map<int, V<pair<int, int>>> m;
  rep(i, h) rep(j, w) {
    ints(a);
    if (a) m[a].eb(i, j);
  }
  int ans = 0;
  each(_, e, m) {
    V<int> rs, cs;
    each(r, c, e) {
      rs.pb(r);
      cs.pb(c);
    }
    V<int> crs = Compress(rs), ccs = Compress(cs);
    atcoder::mf_graph<int> g(sz(crs) + sz(ccs) + 2);
    int s = sz(crs) + sz(ccs), t = s + 1;
    rep(i, sz(crs)) g.add_edge(s, i, 1);
    rep(i, sz(ccs)) g.add_edge(sz(crs) + i, t, 1);
    each(r, c, e) {
      int ri = Uncompress(crs, r);
      int ci = Uncompress(ccs, c);
      g.add_edge(ri, sz(crs) + ci, 1);
    }
    ans += g.flow(s, t);
  }
  wt(ans);
}
