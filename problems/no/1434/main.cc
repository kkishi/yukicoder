// NOTE: This solution is not correct.
#include <bits/stdc++.h>

#include "disjoint_set.h"
#include "yukicoder.h"

pair<bool, V<string>> Solve(int h, int w, int x) {
  if (!even(x)) return {false, {}};
  V<string> g(h, string(w, '#'));
  rep(i, h) rep(j, w) if (even(i) && even(j)) g[i][j] = '.';
  rep(i, h) g[i][0] = '+';
  // rep(i, w) g[0][i] = '.';
  for (int c = 1; c < w; c += 4) g[h - 1][c] = '+';
  g[h - 1][w - 1] = '+';
  x -= (h - 1) + (w - 1);
  if (x < 0) return {false, {}};
  rep(i, (w - 1) / 4) {
    int d = x / 4;
    int y = (h - 1) / 2;
    int z = min(d, y);
    dbg(x, z);
    int c = i * 4 + 2;
    int r = h - 1;
    dbg(d, y, z, c, r);
    g[r][c] = '+';
    rep(j, z) {
      rep(2) {
        --r;
        g[r][c] = '+';
      }
    }
    /*
    if (r > 0) {
      int r2 = r - 2;
      int c2 = c;
      while (r2 >= 0) {
        g[r2][c2] = '.';
        --r2;
      }
      ++r2;
      g[r2][c2 - 1] = '.';
      g[r2][c2 + 1] = '.';
      while (r2 <= r - 2) {
        g[r2][c2 + 1] = '.';
        ++r2;
      }
    }
    */
    rep(2) {
      ++c;
      g[r][c] = '+';
    }
    rep(j, z) {
      rep(2) {
        ++r;
        g[r][c] = '+';
      }
    }
    x -= z * 4;

    // rep(r, h) dbg(i, g[r]);
  }
  // int cnt = 0;
  DisjointSet ds(h * w);
  auto idx = [&](int i, int j) { return i * w + j; };
  int di[] = {0, 1, 0, -1};
  int dj[] = {1, 0, -1, 0};
  rep(i, h) rep(j, w) {
    if (g[i][j] != '+') continue;
    rep(d, 4) {
      int ni = i + di[d];
      int nj = j + dj[d];
      if (0 <= ni && ni < h && 0 <= nj && nj < w) {
        if (g[ni][nj] != '+') continue;
        ds.Union(idx(i, j), idx(ni, nj));
      }
    }
  }
  rep(i, h) rep(j, w) {
    if (g[i][j] == '.') {
      rep(d, 4) {
        int ni = i + di[d] * 2;
        int nj = j + dj[d] * 2;
        if (0 <= ni && ni < h && 0 <= nj && nj < w) {
          if (g[ni][nj] != '#') {
            if (ds.Same(idx(i, j), idx(ni, nj))) continue;
            ds.Union(idx(i, j), idx(ni, nj));
            g[i + di[d]][j + dj[d]] = 'o';
          }
          /*
          if ((ni == 0 && nj == 0) || (ni == h - 1 && nj == w - 1)) {
            if (ds.Same(idx(i, j), idx(ni, nj))) continue;
            ds.Union(idx(i, j), idx(ni, nj));
            g[i + di[d]][j + dj[d]] = '!';
          }
          */
        }
      }
    }
  }
  rep(i, h) rep(j, w) {
    if (even(i) && even(j)) assert(g[i][j] != '#');
    if (!even(i) && !even(j)) assert(g[i][j] == '#');
  }
  if (x == 0) {
    rep(i, h) dbg(g[i]);
  }
  rep(i, h) rep(j, w) if (g[i][j] != '#') g[i][j] = '.';
  return {x == 0, g};
}

void Main() {
  ints(h, w, x);
  if (auto [ok, g] = Solve(h, w, x); ok) {
    each(e, g) wt(e);
    return;
  }
  if (auto [ok, g] = Solve(w, h, x); ok) {
    dbg("transpose");
    rep(i, h) {
      rep(j, w) cout << g[j][i];
      cout << endl;
    }
    return;
  }
  wt(-1);
}
