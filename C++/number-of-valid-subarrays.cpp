// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int result = 0;
        vector<int> s;
        for (const auto& num : nums) {
            while (!s.empty() && s.back() > num) {
                s.pop_back();
            }
            s.emplace_back(num);
            result += s.size();
        }
        return result;
    }
};
