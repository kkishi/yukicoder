#include <bits/stdc++.h>

#include "yukicoder.h"

int Solve(int x, int y) {
  if (x < y) swap(x, y);
  int ans = 0;
  // a == 1
  if (x == y) {
    if (x <= 2) {
      ans += x - 1;
    } else {
      ans += x;
    }
  }
  // a >= 2
  for (int i = 3; i * i <= x + y; ++i) {
    if ((x + y) % i != 0) continue;
    auto f = [&](int a) {
      if ((x - y) % (a - 1) != 0) return;
      int bpc = (x + y) / (a + 1);
      int bmc = (x - y) / (a - 1);
      int b2 = bpc + bmc;
      int c2 = bpc - bmc;
      if (b2 > 0 && even(b2) && c2 > 0 && even(c2)) {
        // dbg(a, b2 / 2, c2 / 2);
        ++ans;
      }
    };
    f(i - 1);
    if (int j = (x + y) / i; j != i) f(j - 1);
  }
  return ans;
}

int Naive(int x, int y) {
  int ans = 0;
  rep(a, 1, 101) rep(b, 1, 101) rep(c, 1, 101) {
    if (a * b + c == x && a * c + b == y) {
      // dbg(a, b, c);
      ++ans;
    }
  }
  return ans;
}

void Main() {
  ints(s);
  rep(s) {
    ints(x, y);
    wt(Solve(x, y));
  }
  /*
  rep(x, 1, 100) rep(y, 1, 100) {
    int S = Solve(x, y);
    int N = Naive(x, y);
    if (S != N) {
      dbg(x, y, S, N);
    }
  }
  */
}
