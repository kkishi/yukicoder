#include <bits/stdc++.h>

#include "rerooting.h"
#include "yukicoder.h"

void Main() {
  ints(n);
  VV<i32> edges(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  TreeDP<bool> tdp(
      edges, [](bool a, bool b) { return a || b; }, [](bool a) { return !a; },
      false);
  tdp.DFS(0);
  tdp.Rerooting(0);

  V<int> ans;
  rep(i, n) if (tdp.Result()[i]) ans.push_back(i);

  wt(sz(ans));
  for (int i : ans) wt(i + 1);
}
