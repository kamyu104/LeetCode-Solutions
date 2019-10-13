// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> count;
        vector<int> freq(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            --freq[count[nums[i]]];
            ++freq[count[nums[i]] + 1];
            const auto c = ++count[nums[i]];
            if (freq[c] * c == (i + 1) && (i + 1) < nums.size()) {
                result = (i + 1) + 1;
            }
            const auto& remain = (i + 1) - freq[c] * c;
            if (freq[remain] == 1 && (remain == 1 || remain == c + 1)) {
                result = (i + 1);
            }
        }
        return result;
    }
};
