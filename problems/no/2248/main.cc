#include <bits/stdc++.h>

#include "compressor.h"
#include "dual_segment_tree.h"
#include "yukicoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  V<int> v;
  rep(i, n) {
    v.eb(a[i]);
    v.eb(b[i]);
    v.eb((a[i] + b[i]) / 2);
  }
  v.eb(0);
  v.eb(big);
  Compressor c(v);
  int N = sz(c.coord);
  DualSegmentTree<int> t(N, [](int a, int b) { return max(a, b); });
  rep(i, n) {
    V<int> v;
    v.eb(c(0));
    v.eb(c(big));
    v.eb(c(a[i]));
    v.eb(c(b[i]));
    v.eb(c((a[i] + b[i]) / 2));
    sort(v);
    rep(i, sz(v) - 1) t.Update(v[i] + 1, v[i + 1] + 1, v[i + 1]);
  }
  int ans = big;
  rep(i, 1, N - 1) chmin(ans, c.coord[t.Get(i)] - c.coord[i]);
  wt(ans);
}
