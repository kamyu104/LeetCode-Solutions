// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const auto& boyer_moore_majority_vote = [&]() {
            int result = 0, cnt = 0;
            for (const auto& x : nums) {
                if (cnt == 0) {
                    result = x;
                }
                if (x == result) {
                    ++cnt;
                } else {
                    --cnt;
                }
            }
            return result; 
        };

        return boyer_moore_majority_vote();
    }
};
