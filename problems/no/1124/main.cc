#include <bits/stdc++.h>

#include "atcoder.h"
#include "bidirected_graph.h"
#include "modint.h"
#include "rerooting.h"

void Main() {
  ints(n);
  BidirectedGraph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    g.AddEdge(a - 1, b - 1);
  }
  // Tree: 1 -> 2 -> 3
  //
  // N3 = {0} = ID
  // E2->3 = {0, 1} = {0} + inc({0}) = f(ID)
  // N2 = {0, 1} = {0, 1} x ID
  // E1->2 = {0, 0, 1, 2} = {0, 0} + inc({0, 1})
  // N1 = {0, 0, 1, 2}
  //
  // Tree: 3 <- 1 -> 2
  //
  // N2 = {0}
  // N3 = {0}
  // E1-2 = {0, 1} = {0} + inc({0})
  // E1-3 = {0, 1} = {0} + inc({0})
  // N1 = {0, 1, 1, 2} = {0, 1} x {0, 1}
  using mint = ModInt<>;
  struct DP {
    mint sqsum, sum, cnt;
  };
  auto f = [](DP x) -> DP {
    return {x.sqsum + 2 * x.sum + x.cnt, x.sum + x.cnt, x.cnt * 2};
  };
  V<DP> res = Rerooting<DP, int>(
      g,
      [](DP a, DP b) -> DP {
        return {a.sqsum * b.cnt + 2 * a.sum * b.sum + b.sqsum * a.cnt,
                a.sum * b.cnt + b.sum * a.cnt, a.cnt * b.cnt};
      },
      [&](const auto&, DP x) -> DP { return f(x); }, {0, 0, 1});
  mint ans = 0;
  each(r, res) ans += f(r).sqsum;
  wt(ans);
}
