# 今日任务

* leetcode昨天每日一题(bushi)

  ```c++
  class Solution {
  public:
      int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
          int n = stations.size();
          vector<long> dp(n + 1);
          dp[0] = startFuel;
          for (int i = 0; i < n; i++) {
              for (int j = i; j >= 0; j--) {
                  if (dp[j] >= stations[i][0]) {
                      dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                  }
              }
          }
          for (int i = 0; i <= n; i++) {
              if (dp[i] >= target) {
                  return i;
              }
          }
          return -1;
      }
  };
  ```

动态规划做法：首先状态定义有问题$dp[i][j]$，然后逆序更新(类似背包)可以省去一个维度，太久不做已经是不会了***~~~***

* 学习latex公式的书写，用于写题解记笔记等。
* ![1728357494559](image/note/1728357494559.png)
