#include <bits/stdc++.h>

#include "yukicoder.h"

bool Solve() {
  ints(n);
  VV<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  V<int> degree3;
  rep(i, n) {
    if (sz(g[i]) > 2) degree3.pb(i);
  }
  if (degree3.empty()) return true;
  if (sz(degree3) > 1) return false;
  int radius = -1;
  auto rec = Fix([&](auto rec, int node, int parent) -> pair<int, bool> {
    int ret = 0;
    for (int child : g[node]) {
      if (child == parent) continue;
      auto [res, ok] = rec(child, node);
      if (!ok) return {0, false};
      if (ret > 0) return {0, false};
      ret = res + 1;
    }
    return {ret, true};
  });
  for (int child : g[degree3[0]]) {
    auto [res, ok] = rec(child, degree3[0]);
    if (!ok) return false;
    if (radius != -1 && radius != res) return false;
    radius = res;
  }
  return true;
}

void Main() { wt(Solve()); }
