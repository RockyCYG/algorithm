#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> tmp(n);
    vector<int> ans(n);
    vector<int> idx(n);
    vector<int> tmpidx(n);
    for (int i = 0; i < n; i++) idx[i] = i;
    merge_sort(nums, tmp, idx, tmpidx, ans, 0, n - 1);
    return ans;
  }

  void merge_sort(vector<int>& nums, vector<int>& tmp, vector<int>& idx,
                  vector<int>& tmpidx, vector<int>& ans, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(nums, tmp, idx, tmpidx, ans, left, mid);
    merge_sort(nums, tmp, idx, tmpidx, ans, mid + 1, right);
    int i = left, j = mid + 1;
    int cur = left;
    while (i <= mid && j <= right) {
      if (nums[i] > nums[j]) {
        tmp[cur] = nums[j];
        tmpidx[cur] = idx[j];
        cur++, j++;
      } else {
        tmp[cur] = nums[i];
        tmpidx[cur] = idx[i];
        ans[idx[i]] += j - mid - 1;
        cur++, i++;
      }
    }
    while (i <= mid) {
      tmp[cur] = nums[i];
      tmpidx[cur] = idx[i];
      ans[idx[i]] += j - mid - 1;
      cur++, i++;
    }
    while (j <= right) {
      tmp[cur] = nums[j];
      tmpidx[cur] = idx[j];
      cur++, j++;
    }
    for (int i = left; i <= right; i++) {
      nums[i] = tmp[i];
      idx[i] = tmpidx[i];
    }
  }
};