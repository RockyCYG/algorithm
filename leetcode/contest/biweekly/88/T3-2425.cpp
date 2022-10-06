#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    int ans = 0;
    if (n % 2 == 1) {
      for (int x : nums1) {
        ans ^= x;
      }
    }
    if (m % 2 == 1) {
      for (int x : nums2) {
        ans ^= x;
      }
    }
    return ans;
  }
};