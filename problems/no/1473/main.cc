#include <bits/stdc++.h>

#include "dijkstra.h"
#include "disjoint_set.h"
#include "graph.h"
#include "yukicoder.h"

void Main() {
  ints(n, m);
  V<tuple<int, int, int>> e;
  rep(m) {
    ints(s, t, d);
    --s, --t;
    e.eb(d, s, t);
  }
  sort(all(e), greater{});
  DisjointSet ds(n);
  Graph<int> g(n);
  int ans;
  bool connected = false;
  for (auto [d, s, t] : e) {
    if (connected && d < ans) break;
    ds.Union(s, t);
    g.AddEdge(s, t, 1);
    g.AddEdge(t, s, 1);
    ans = d;
    if (ds.Same(0, n - 1)) connected = true;
  }
  wt(ans, *Dijkstra(g, 0)[n - 1]);
}
