#include <bits/stdc++.h>

#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, x, y);
  V<int> a(x), b(y);
  cin >> a >> b;
  mint ans = 0;
  rep(i, 18) {
    int A = 0;
    each(e, a) if (hasbit(e, i))++ A;
    mint P = mint(A) / x;
    int B = 0;
    each(e, b) if (hasbit(e, i))++ B;
    mint Q = mint(y - B) / y;
    mint one = 0, zero = 1;
    rep(n) {
      {
        mint d = zero * P;
        one += d;
        zero -= d;
      }
      {
        mint d = one * Q;
        one -= d;
        zero += d;
      }
    }
    ans += (1 << i) * one * mint(x * y).Pow(n);
  }
  wt(ans);
}
