# Leetcode第425场周赛

## [Q1. 最小正和子数组](https://leetcode.cn/contest/weekly-contest-425/problems/minimum-positive-sum-subarray/description/)

### 题目描述

给你一个整数数组 nums 和 两个 整数 l 和 r。你的任务是找到一个长度在 l 和 r 之间（包含）且和大于 0 的 子数组 的最小和。

返回满足条件的子数组的 最小 和。如果不存在这样的子数组，则返回 -1。
**子数组** 是数组中的一个连续 非空 元素序列。

### 样例

```c++
输入： nums = [3, -2, 1, 4], l = 2, r = 3

输出： 1

解释：
长度在 l = 2 和 r = 3 之间且和大于 0 的子数组有：
[3, -2] 和为 1
[1, 4] 和为 5
[3, -2, 1] 和为 2
[-2, 1, 4] 和为 3
其中，子数组 [3, -2] 的和为 1，是所有正和中最小的。因此，答案为 1。
```

```c++
输入： nums = [-2, 2, -3, 1], l = 2, r = 3

输出： -1

解释：

不存在长度在 l 和 r 之间且和大于 0 的子数组。因此，答案为 -1。
```

```c++
输入： nums = [1, 2, 3, 4], l = 2, r = 4

输出： 3

解释：

子数组 [1, 2] 的长度为 2，和为 3，是所有正和中最小的。因此，答案为 3
1 <= l <= r <= nums.length

```

### 提示

* $ 1 \leq nums.length \leq 100 $
* $ 1 \leq l \leq r \leq nums.length$
* $-1000 \leq nums[i] \leq 1000$

### 算法

计算 nums 数组的前缀和，并枚举子数组的长度，取最小值。

### 时间复杂度

* $O(n^2)$

### 空间复杂度

* $O(n)$

### 代码

```c++
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pre(nums.size()+1);
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i-1] + nums[i-1];
        }
        int ans = INT_MAX;
        for(int i = l; i <= r; i++){
            for(int j = i; j <= n; j++){
                if(pre[j]-pre[j-i]>0) ans = min(ans, pre[j]-pre[j-i]);
            } 
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
```

## [Q2. 重排子字符串以形成目标字符串](https://leetcode.cn/contest/weekly-contest-425/problems/rearrange-k-substrings-to-form-target-string/)

### 题目描述

给你两个字符串 s 和 t（它们互为字母异位词），以及一个整数 k。

你的任务是判断是否可以将字符串 s 分割成 k 个等长的子字符串，然后重新排列这些子字符串，并以任意顺序连接它们，使得最终得到的新字符串与给定的字符串 t 相匹配。

如果可以做到，返回 true；否则，返回 false。

**字母异位词** 是指由另一个单词或短语的所有字母重新排列形成的单词或短语，使用所有原始字母恰好一次。

**子字符串** 是字符串中的一个连续 **非空 **字符序列。

### 样例

```c++
输入： s = "abcd", t = "cdab", k = 2

输出： true

解释：

将 s 分割成 2 个长度为 2 的子字符串：["ab", "cd"]。
重新排列这些子字符串为 ["cd", "ab"]，然后连接它们得到 "cdab"，与 t 相匹配。
```

```c++
输入： s = "aabbcc", t = "bbaacc", k = 3

输出： true

解释：

将 s 分割成 3 个长度为 2 的子字符串：["aa", "bb", "cc"]。
重新排列这些子字符串为 ["bb", "aa", "cc"]，然后连接它们得到 "bbaacc"，与 t 相匹配。
```

```c++
输入： s = "aabbcc", t = "bbaacc", k = 2

输出： false

解释：

将 s 分割成 2 个长度为 3 的子字符串：["aab", "bcc"]。
这些子字符串无法重新排列形成 t = "bbaacc"，所以输出 false。
```

### 提示

* $ 1 \leq s.length == t.lengt \leq 2 * 10^5$
* $ 1 \leq k \leq s.length$
* s.length能被k整除
* s 和 t 仅由小写英文字符异位词
* 输入保证 s 和 t 互为字母异位词。

### 算法

**哈希表**

* 将s按n/k一组分开并加入哈希表，在将t按n/k一组分开查看哈希表里是否存在。如果存在需要从哈希表中删除该项。

### 时间复杂度

* $ O(nlogn) $

### 空间复杂度

* $O(n)$

### 代码

```c++
class Solution {
public:

    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        k = n/k;
        map<string, int> mp;
        for(int i = 0; i < n; i+=k){
            mp[s.substr(i, k)] += 1;
        }
        for(int i = 0; i < n; i+=k){
            if(mp[t.substr(i, k)]!=0){
                mp[t.substr(i, k)] -= 1;
            } else{
                return false;
            }
        }
        return true;
    }
};
```

## [Q3. 最小数组和](https://leetcode.cn/contest/weekly-contest-425/problems/minimum-array-sum/)

### 题目描述

给你一个整数数组 nums 和三个整数 d、op1 和 op2。

你可以对 nums 执行以下操作：

* **操作 1**：选择一个下标 i，将 nums[i] 除以 2，并 **向上取整** 到最接近的整数。你最多可以执行此操作 op1 次，并且每个下标最多只能执行**一次**。
* **操作 2**：选择一个下标 i，仅当 nums[i] 大于或等于 d 时，从 nums[i] 中减去 d。你最多可以执行此操作 op2 次，并且每个下标最多只能执行**一次**。
  注意： 两种操作可以应用于同一下标，但每种操作最多只能应用一次。

返回在执行任意次数的操作后，nums 中所有元素的 **最小 **可能 **和** 。

### 样例

```c++
输入： nums = [2,8,3,19,3], d = 3, op1 = 1, op2 = 1

输出： 23

解释：

对 nums[1] = 8 应用操作 2，使 nums[1] = 5。
对 nums[3] = 19 应用操作 1，使 nums[3] = 10。
结果数组变为 [2, 5, 3, 10, 3]，在应用操作后具有最小可能和 23。
```

```c++
输入： nums = [2,4,3], d = 3, op1 = 2, op2 = 1

输出： 3

解释：

对 nums[0] = 2 应用操作 1，使 nums[0] = 1。
对 nums[1] = 4 应用操作 1，使 nums[1] = 2。
对 nums[2] = 3 应用操作 2，使 nums[2] = 0。
结果数组变为 [1, 2, 0]，在应用操作后具有最小可能和 3。
```

### 提示

* $1\leq nums.length \leq 100$
* $ 0 \leq nums[i] \leq 10^5$
* $0\leq d \leq 10^5$
* $0 \leq op1, op2 \leq nums.length$

### 算法

**动态规划**

* 定义状态$dp[i][j][k]$表示当前处理到第$i $个数，操作1还**剩**$j$个，操作2还**剩**$k$个时，通过操作1和2减少的和的最大值。
* 转移来源有三个，分别是当前数只用操作1、只用操作2和都使用。在两种操作都使用时需考虑两种操作的先后顺序，取最大值。转移过程中需注意只有$nums[i] \geq d$ 时才能用操作2。
* 最终答案为$s-min(dp[n][x][y], 0 \leq x \leq op1,0\leq y \leq op2) $，$s$是原数组的和。

### 时间复杂度

* $ O(n^3)$

### 空间复杂度

* $O(n^3)$

### 代码

```c++
class Solution {
public:
    int minArraySum(vector<int>& nums, int d, int op1, int op2) {
        int n = nums.size(), s = 0;
        for(int v:nums) s += v;
        int dp[n+1][op1+1][op2+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= op1; j++){
                for(int k = 0; k <= op2; k++){
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                    if(j){
                        dp[i][j-1][k] = max(dp[i][j-1][k], dp[i-1][j][k]+nums[i-1]/2);
                    }
                    if(k&&nums[i-1]>=d){
                        dp[i][j][k-1] = max(dp[i][j][k-1], dp[i-1][j][k]+d);
                    }
                    if(j&&k&&nums[i-1]>=d){
                        int mxd = 0;
			//考虑可以先做操作一，然后做操作二，因为这样先除后减减少量一定最大
                        if((nums[i-1]+1)/2<d){
                            mxd = d + (nums[i-1]-d)/2;
                        }
			//否则先做操作二在做操作一
			else{
                            mxd = d + nums[i-1]/2;
                        }
                        dp[i][j-1][k-1] = max(dp[i][j-1][k-1], mxd+dp[i][j][k]);
                    }
                }
            }
        }  
        int ans = 0;
        for(int j = 0; j <= op1; j++){
            for(int k = 0; k <= op2; k++){
                ans = max(ans, dp[n][j][k]);
            }
        }
        return s-ans;
    }
};
```

## [Q4. 移除边之后的权重最大和](https://leetcode.cn/contest/weekly-contest-425/problems/maximize-sum-of-weights-after-edge-removals/)

### 题目描述

存在一棵具有 n 个节点的**无向**树，节点编号为 0 到 n - 1。给你一个长度为 n - 1 的二维整数数组 $edges$，其中 $edges[i] = [u_i, v_i, w_i]$ 表示在树中节点 $u_i$ 和 $v_i$ 之间有一条权重为 $w_i$ 的边。

你的任务是移除零条或多条边，使得：

* 每个节点与**至多** k 个其他节点有边直接相连，其中 k 是给定的输入。
* 剩余边的权重之和 **最大化** 。

返回在进行必要的移除后，剩余边的权重的 **最大** 可能和。

### 样例

```c++
输入： edges = [[0,1,4],[0,2,2],[2,3,12],[2,4,6]], k = 2

输出： 22
```

```c++
输入： edges = [[0,1,5],[1,2,10],[0,3,15],[3,4,20],[3,5,5],[0,6,10]], k = 3

输出： 65

解释：

由于没有节点与超过 k = 3 个节点相连，我们不移除任何边。
权重之和为 65。因此，答案是 65。
```

### 提示

* $2\leq n \leq 10^5$
* $1\leq k \leq n-1$
* $edges.length == n-1$
* $edge[i].length == 3$
* $0\leq edges[i][0] \leq n-1 $
* $0 \leq edges[i][1] \leq n-1$
* $1 \leq edge[i][2] \leq 10^6$
* 输入保证$edges$形成一颗有效的树

### 算法

**树形dp**

* 定义状态dp[u][0]/dp[u][1]分别表示结点u与父节点的路径是否断开并且其子节点都合法的最小值之和，0表示不断，1表示断开。
* 在递归完成时对结点u进行更新，设$vv_i$是u的子节点。也就是我们要考虑u是否与其父节点的路径断开时，u与$vv_i$是否断开，且满足每个节点与**至多** k 个其他节点有边直接相连这个条件。
* 将$\{dp[vv_i][1]-dp[vv_i][0], dp[vv_i][1]\}$存入数组$arr$并排序， $vv_i$是u的所有子节点。如果还需断开s个边才满足要求，则选择排好序数组的前s个边。否则其他的可断可不断，选择代价最小的就好了。
* 因为0节点没有父节点，我们加一个虚点个0节点相连。最后特殊处理节点0。

### 代码

```c++
typedef long long LL;
typedef pair<LL, LL> PII;
class Solution {
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        LL ans = 0;
        int n = edges.size()+1;
        LL sum = 0;
        vector<vector<PII>> g(n+1);
        g[n].push_back({0, 0});
        g[0].push_back({n, 0});
        for(auto &t:edges){
            int u = t[0], v = t[1], w = t[2];
            g[u].push_back({v, w}), g[v].push_back({u, w});
            sum += w; 
        }
        vector<vector<LL>> dp(n+1, vector<LL>(2, 0));
        auto dfs = [&](auto&& dfs, int u, int father)->void{
            for(auto [v, w]:g[u]){
                if(v==father) continue;
                dfs(dfs, v, u);
                //断
                dp[v][1] += w;
                int s = 0;
                vector<PII> arr;
                for(auto [vv, ww]:g[v]){
                    if(vv==u) continue;
                    s += 1;
                    arr.push_back({dp[vv][1]-dp[vv][0], dp[vv][1]});
                }
                sort(arr.begin(), arr.end());
                for(int i = 0; i < arr.size(); i++){
                    if(i<s-k) dp[v][1] += arr[i].second;
                    else {
                        dp[v][1] += min(arr[i].second, arr[i].second-arr[i].first);
                    }
                }
                //不断
                for(int i = 0; i < arr.size(); i++){
                    if(i<s-k+1) {
                        dp[v][0] += arr[i].second;
                    }
                    else {
                        dp[v][0] += min(arr[i].second, arr[i].second-arr[i].first); 
                    }
                }
                if(v==0){
                    for(int i = 0; i < arr.size(); i++){
                        if(i<s-k){
                            ans += arr[i].second;
                        } else{
                            ans += min(arr[i].second, arr[i].second-arr[i].first);
                        }
                    }
                }
            }
        };
        dfs(dfs, n, -1);
        return sum-ans;
    }
};
```
