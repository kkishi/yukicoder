#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n, m);
  V<int> a(m), b(m), y(m);
  rep(i, m) cin >> a[i] >> b[i] >> y[i];
  V<int> ans(n);
  rep(i, 30) {
    VV<pair<int, int>> g(n);
    rep(j, m) {
      int A = a[j] - 1;
      int B = b[j] - 1;
      int C = hasbit(y[j], i);
      g[A].eb(B, C);
      g[B].eb(A, C);
    }
    V<int> v(n, -1);
    bool ok = true;
    rep(j, n) if (v[j] == -1) {
      Fix([&](auto rec, int node, int parent, int value) {
        if (v[node] != -1) {
          if (v[node] != value) {
            ok = false;
          }
          return;
        }
        v[node] = value;
        for (auto [child, x] : g[node]) {
          if (child == parent) continue;
          int next_value = x == 0 ? value : (1 - value);
          rec(child, node, next_value);
        }
      })(j, -1, 0);
    }
    if (!ok) {
      wt(-1);
      return;
    }
    rep(j, n) ans[j] |= v[j] << i;
  }
  each(e, ans) wt(e);
}
