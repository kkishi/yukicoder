## 解法 (main.cc)

座標圧縮する。 $dp[i][j] = 最小値をjと決める。A_iとB_iまでの要素を見て、それぞれj以上となる条件の元で出来る限り小さく決めたとき、これまでの最大値$ とする。これはRMQを実行するセグメント木を用いてインラインDPできる。
