#include <bits/stdc++.h>

#include "yukicoder.h"

string Solve(int a0, int n, int m, int k) {
  V<int> cnt = {n, m};
  string ret;
  int a = a0;
  rep(i, k + 1) {
    --cnt[a];
    ret += (char)('0' + a);
    a ^= 1;
  }
  if (min(cnt) < 0) return "{";
  {
    string tmp;
    rep(i, sz(ret)) {
      tmp += ret[i];
      while (ret[i] == '0' && cnt[0]) {
        tmp += '0';
        --cnt[0];
      }
    }
    swap(ret, tmp);
  }
  {
    string tmp;
    rrep(i, sz(ret)) {
      tmp += ret[i];
      while (ret[i] == '1' && cnt[1]) {
        tmp += '1';
        --cnt[1];
      }
    }
    reverse(tmp);
    swap(ret, tmp);
  }
  return ret;
}

void Main() {
  ints(n, m, k);
  string ans = min(Solve(0, n, m, k), Solve(1, n, m, k));
  if (ans == "{") ans = "-1";
  wt(ans);
}
