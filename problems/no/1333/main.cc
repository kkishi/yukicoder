#include <bits/stdc++.h>

#include "atcoder.h"
#include "bidirected_graph.h"
#include "modint.h"
#include "rerooting.h"

using mint = ModInt<>;

struct DP {
  mint sum, sqsum, cnt;
};

void Main() {
  ints(n);
  BidirectedGraph<int> g(n);
  rep(n - 1) {
    ints(u, v, w);
    g.AddEdge(u - 1, v - 1, w);
  }
  V<DP> res = Rerooting<DP, int>(
      g,
      [](DP a, DP b) -> DP {
        return {a.sum + b.sum, a.sqsum + b.sqsum, a.cnt + b.cnt};
      },
      [](const auto& e, DP x) -> DP {
        mint cnt = x.cnt + 1;
        return {x.sum + e.weight * cnt,
                x.sqsum + 2 * e.weight * x.sum + cnt * e.weight * e.weight,
                cnt};
      });
  mint ans = 0;
  each(r, res) ans += r.sqsum;
  wt(ans / 2);
}
