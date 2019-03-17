// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        vector<int> counter(60);
        for (const auto& t : time) {
            result += counter[(60 - t % 60) % 60];
            ++counter[t % 60];
        }
        return result;
    }
};
