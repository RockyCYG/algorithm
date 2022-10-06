#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int diff;

  long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
    this->diff = diff;
    int n = nums1.size();
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = nums1[i] - nums2[i];
    vector<int> tmp(n);
    return merge_sort(arr, tmp, 0, n - 1);
  }

  long long merge_sort(vector<int>& arr, vector<int>& tmp, int left, int right) {
    if (left >= right) return 0;
    int mid = (left + right) / 2;
    long long res = merge_sort(arr, tmp, left, mid) + merge_sort(arr, tmp, mid + 1, right);
    int i = left;
    for (int j = mid + 1; j <= right; j++) {
      while (i <= mid && arr[i] <= arr[j] + diff) {
        i++;
      }
      res += i - left;
    }
    int cur = left, j = mid + 1;
    i = left;
    while (i <= mid && j <= right) {
      if (arr[i] >= arr[j])
        tmp[cur++] = arr[j++];
      else
        tmp[cur++] = arr[i++];
    }
    while (i <= mid) tmp[cur++] = arr[i++];
    while (j <= right) tmp[cur++] = arr[j++];
    for (int i = left; i <= right; i++) arr[i] = tmp[i];
    return res;
  }
};