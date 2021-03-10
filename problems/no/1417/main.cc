#include <bits/stdc++.h>

#include "factors.h"
#include "modint.h"
#include "yukicoder.h"

using mint = ModInt<>;

void Main() {
  strings(n);
  each(e, n) e -= '0';
  int N = sz(n);
  vector dp(N + 1, vector(3, vector(3, vector(3, mint(0)))));
  dp[0][0][0][0] = 1;
  V<int> two(10), five(10);
  rep(i, 10) {
    auto fs = Factors(i);
    two[i] = fs[2];
    five[i] = fs[5];
  }
  rep(i, N) {
    // j == 0: all zeros on the left
    // j == 1: equal to the input on the left
    // j == 2: non zero but smaller than the input on the left
    rep(j, 3) {
      // k: the number of 2s. k == 2 indicates that it may be more than 2.
      rep(k, 3) {
        // l: the number of 5s. l == 2 indicates that it may be more than 2.
        rep(l, 3) {
          rep(m, 10) {
            int nj;
            if (m == 0) {
              if (j == 0) {
                nj = 0;
              } else {
                continue;
              }
            } else {
              if (j == 0) {
                if (i == 0) {
                  if (m < n[0]) {
                    nj = 2;
                  } else if (m == n[0]) {
                    nj = 1;
                  } else {
                    continue;
                  }
                } else {
                  nj = 2;
                }
              } else if (j == 1) {
                if (m < n[i]) {
                  nj = 2;
                } else if (m == n[i]) {
                  nj = 1;
                } else {
                  continue;
                }
              } else {
                nj = 2;
              }
            }
            int nk = m == 0 ? 0 : min(2, k + two[m]);
            int nl = m == 0 ? 0 : min(2, l + five[m]);
            dp[i + 1][nj][nk][nl] += dp[i][j][k][l];
          }
        }
      }
    }
  }
  mint ans = 0;
  rep(i, 3) ans += dp[N][i][2][2];
  wt(ans);
}
