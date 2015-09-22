// Time:  O(n)
// Space: O(1)

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int num = 0;
    for (int i = 0; i < nums.size(); ++i) {
      num ^= nums[i] ^ (i + 1);
    }
    return num;
  }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
 public:
  int missingNumber(vector<int>& nums) {
    vector<int> expected(nums.size()); 
    iota(expected.begin(), expected.end(), 1);  // Costs extra space O(n)
    return accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>()) ^
           accumulate(expected.cbegin(), expected.cend(), 0, bit_xor<int>());
  }
};
