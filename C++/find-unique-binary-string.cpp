// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;
        for (int i = 0; i < size(nums); ++i) {
            result.push_back((nums[i][i] == '0') ? : '1' : '0');
        }
        return result;
    }
};
