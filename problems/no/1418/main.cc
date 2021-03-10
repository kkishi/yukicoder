#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  VV<int> to(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  auto [ans, _] =
      Fix([&](auto rec, int node, int parent, int depth) -> pair<int, int> {
        int sum = 0;
        int size = 1;
        for (int child : to[node]) {
          if (child == parent) continue;
          auto [csum, csize] = rec(child, node, depth + 1);
          int x = n - csize;
          sum += csum + csize * x;
          size += csize;
        }
        int psize = n - size;
        return {sum + psize * size, size};
      })(0, -1, 0);
  wt(ans + n * n);
}
