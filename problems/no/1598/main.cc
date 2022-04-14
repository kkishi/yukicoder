#include <bits/stdc++.h>

#include "yukicoder.h"

template <int64_t R, int64_t C>
class BitGrid {
 public:
  BitGrid(int64_t bit) : bit_(bit) {}
  int64_t Get(int r, int c) const { return (bit_ >> (r * C + c)) & 1; }
  BitGrid Set(int r, int c) const { return bit_ | (int64_t(1) << (r * C + c)); }
  int64_t Bit() const { return bit_; }
  static int64_t Mask() { return (int64_t(1) << (R * C)) - 1; }

 private:
  int64_t bit_ = 0;
};

namespace std {

template <int64_t R, int64_t C>
ostream& operator<<(ostream& os, const BitGrid<R, C>& g) {
  os << std::endl;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      os << g.Get(r, c);
    }
    os << std::endl;
  }
  return os;
}
}  // namespace std

using grid = BitGrid<4, 4>;

void Main() {
  vector inc(1 << 16, int(0));
  rep(mask, 1 << 16) {
    grid g(mask);
    rep(r, 4) rep(c, 3) inc[mask] += g.Get(r, c) ^ g.Get(r, c + 1);
    rep(r, 3) rep(c, 4) inc[mask] += g.Get(r, c) ^ g.Get(r + 1, c);
  }
  int N = 216;
  vector dp(1 << 16, vector(N, int(0)));
  dp[0][0] = 1;
  rep(mask, 1 << 16) rep(score, N) {
    if (dp[mask][score] == 0) continue;
    grid g(mask);
    rep(r, 4) rep(c, 4) if (!g.Get(r, c)) {
      dp[g.Set(r, c).Bit()][score + inc[g.Bit()]] += dp[mask][score];
    }
  }
  ints(k);
  wt(dp[grid::Mask()][k]);
}
