#include <bits/stdc++.h>

#include "yukicoder.h"

int hb(int x) { return 63 - __builtin_clzll(x); }

int naive(int a, int b) {
  int ans = -big;
  rep(x, a + 1) rep(y, b + 1) {
    int z = min({x, y, (x ^ y)});
    // dbg(x, y, (x ^ y), z);
    chmax(ans, z);
  }
  return ans;
}

int solve(int a, int b) {
  if (a > b) swap(a, b);
  if (b == 0) return 0;
  if (hb(a) == hb(b)) {
    return (1LL << hb(a)) - 1;
  }
  return a;
}

void Main() {
  ints(a, b);
  wt(solve(a, b));
  /*
  rep(a, 100) rep(b, 100) {
    int x = naive(a, b);
    int y = solve(a, b);
    if (x != y) dbg(a, b, x, y);
  }
  */
}
