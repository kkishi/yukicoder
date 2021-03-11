#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

// Computes 2^k % n.
int rem(int n, int k) {
  if (k == 0) return 1;
  if (even(k)) {
    int r = rem(n, k / 2);
    return r * r % n;
  }
  return rem(n, k - 1) * 2 % n;
}

V<mint> Solve(int n, int k) {
  int r = (rem(n, k) - 1 + n) % n;        // (2^k - 1) % n
  mint x = (mint(2).Pow(k) - r - 1) / n;  // (2^k - 1) / n
  V<mint> ans(n);
  for (int i = 1; i < n; i += 2) ans[i] = x;
  for (int i = 1; i <= r; i += 2) ans[i] += 1;
  return ans;
}

// The possible positions after k moves look like:
//   -(2^k - 1), ..., -5, -3, -1, 1, 3, 5, ..., (2^k - 1)
// So it is sufficient if we can compute (2^k - 1) / n modulo 10^9+7 (1).
// It seems difficult to calculate (1) directly. It turns out that 2^k % n
// (2) can be computed easily, and using it we can compute (1).
void Main() {
  ints(n, k);
  V<mint> x;
  if (!even(n)) {
    V<mint> y = Solve(n * 2, k);
    x.resize(n);
    rep(i, n) x[i] = y[i] + y[n + i];
  } else {
    x = Solve(n, k);
  }
  V<mint> ans(n);
  rep(i, n) ans[i] = x[i] + x[(n - i) % n];
  mint t = 1 / mint(2).Pow(k);
  each(e, ans) wt(e * t);
}
