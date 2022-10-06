#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = 1e5 + 5;

class Solution {
 public:
  int tree[maxn];
  int n;
  vector<int> countSmaller(vector<int>& nums) {
    n = nums.size();
    vector<int> arr = nums;
    sort(arr.begin(), arr.end());
    int m = unique(arr.begin(), arr.end()) - arr.begin();
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
      ans[i] = query(lower_bound(arr.begin(), arr.begin() + m, nums[i]) -
                     arr.begin());
      add(upper_bound(arr.begin(), arr.begin() + m, nums[i]) - arr.begin(), 1);
    }
    return ans;
  }

  void add(int i, int val) {
    while (i <= n) {
      tree[i] += val;
      i += i & -i;
    }
  }

  int query(int i) {
    int sum = 0;
    while (i > 0) {
      sum += tree[i];
      i -= i & -i;
    }
    return sum;
  }
};