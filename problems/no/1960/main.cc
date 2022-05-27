#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<998244353>;

mint naive(int n, int m, int k) {
  V<int> p(n);
  iota(all(p), 0);
  mint ans = 0;
  do {
    bool ok = true;
    rep(i, m) {
      int x = p[i];
      while (x != i) {
        if (x < m) ok = false;
        x = p[x];
      }
    }
    rep(i, n - k, n) {
      int x = p[i];
      while (x != i) {
        if (n - k <= x) ok = false;
        x = p[x];
      }
    }
    if (ok) ++ans;
  } while (next_permutation(all(p)));
  return ans;
}

mint solve(int n, int m, int k) {
  if (n - k < m) {
    int x = m + k - n;
    m -= x;
    k -= x;
    n -= x;
  }
  mint ans = 0;
  rep(i, min(m, k) + 1) {
    ans += mint::Comb(m, i) * mint::Comb(k, i) * mint::Fact(i);
  }
  return ans * mint::Fact(n) / mint::Fact(m + k);
}

void Main() {
  ints(n, m, k);
  wt(solve(n, m, k));
  /*
  {
    int n = 9;
    rep(m, n + 1) {
      rep(k, n + 1) {
        mint x = naive(n, m, k);
        mint y = solve(n, m, k);
        if (x != y) dbg(n, m, k, x, y);
      }
    }
  }
  */
}
