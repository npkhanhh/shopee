#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLHS(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = 0;
    int prev = -1;
    int cur = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        cur += 1;
      } else {
        if (prev > -1 && cur > -1 && prev + cur > res) {
          res = prev + cur;
        }
        if (nums[i] == nums[i - 1] + 1) {
          prev = cur;
        } else {
          prev = -1;
        }
        cur = 1;
      }
    }
    if (prev > -1 && cur > -1 && prev + cur > res) {
      res = prev + cur;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> v{1, 3, 2, 2, 5, 2, 3, 7};
  cout << s.findLHS(v);
  return 0;
}

